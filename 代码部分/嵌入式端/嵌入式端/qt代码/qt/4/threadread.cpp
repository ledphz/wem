#include "threadread.h"
#include <QElapsedTimer>
#include <QtCore>
#include <QDebug>
#include<sqlite/sqlite3.h>

extern "C"
{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<unistd.h>
    #include<fcntl.h>
    #include<sys/types.h>
    #include <fcntl.h>
    #include <termios.h>
    #include<sys/socket.h>
    #include<arpa/inet.h>
    #include<time.h>
    #include <errno.h>
}

extern float val_nh4;
extern float val_tmpe;
extern float val_hum;

int sockfd;
sqlite3 *db;

struct gas
{
    float nh4;
    float temp;
    float humi;
    int count;
    char date[20];
};
struct gas my_data;

#define ip "192.168.0.34"
//#define ip "120.79.65.236"

ThreadRead::ThreadRead()
{

}

void ThreadRead::run()
{
    struct tm *p;
    time_t timep;
    int num;
    int fd, ret, is_conn_ser, count = 0;
    int i, k = 1, HUMI_Q_H, HUMI_Q_Q, NH4_Q_H, NH4_Q_Q, TEMP_Q_H, TEMP_Q_Q;
    float NH4, TEMP, HUMI;
    char str[8] = {0};
    char buf[11] = {0};
    char sql_insert[1024] = {0};
    is_conn_ser = socket_init();
    num = conn_to_sqlite();
    if (0 > num)
    {
        sprintf(err, "[conn_to_sqlite error] [FILE:%s] [LINE:%d]",  __FILE__, __LINE__);
        qCritical(err);
        num = 0;
    }
    //发送制定格式命令
    str[0] = 0x02;
    str[1] = 0x03;
    str[2] = 0x00;
    str[3] = 0x20;
    str[4] = 0x00;
    str[5] = 0x03;
    str[6] = 0x04;
    str[7] = 0x32;

    fd = open("/dev/ttyO1", O_RDWR);
    if(fd < 0)
    {
         //printf("open tty\n");
         sprintf(err, "[open /dev/ttyO1 error: %s] [FILE:%s] [LINE:%d]", strerror(errno), __FILE__, __LINE__);
         qFatal(err);
    }
    tty_set(fd);
    while(1)
    {
        for(i = 0; i < 8; i++)
        {
            ret = write(fd, &str[i], sizeof(str[0]));
            if ((unsigned int)ret < sizeof(str[0]))
            {
                //printf("write error\n");
                sprintf(err, "[write to /dev/ttyO1 error:%s] [FILE:%s] [LINE:%d]", strerror(errno), __FILE__, __LINE__);
                qCritical(err);
                //exit(1);
            }
        }
//        printf("************第%d次监控************\n", k);
        for(i = 0; i < 11; i++)
        {
            ret = read(fd, &buf[i], sizeof(str[0]));
            //printf("%02x ", buf[i]);
            if ((unsigned int)ret < sizeof(str[0]))
            {
                sprintf(err, " [read /dev/ttyO1 error:%s] [FILE:%s] [LINE:%d]", strerror(errno), __FILE__, __LINE__);
                qCritical(err);
            }
        }
//        printf("\n");
//        printf("****************翻译****************\n");
        //氨气
        if(buf[3] % 10 != 0)
        {
            NH4_Q_H = buf[3] % 10 * 256;
        }
        else
        {
            NH4_Q_H = 0;
        }
        if(buf[3] / 10 != 0)
        {
            NH4_Q_Q = buf[3] / 10 * 4096;
        }
        else
        {
            NH4_Q_Q = 0;
        }
        NH4 = NH4_Q_Q + NH4_Q_H + buf[4];
        val_nh4 = NH4 / 10.0;
        //温度
        if(buf[5] % 10 != 0)
        {
            TEMP_Q_H = buf[5] % 10 * 256;
        }
        else
        {
            TEMP_Q_H = 0;
        }
        if(buf[5] / 10 != 0)
        {
            TEMP_Q_Q = buf[5] / 10 * 4096;
        }
        else
        {
            TEMP_Q_Q = 0;
        }
        TEMP = TEMP_Q_H + TEMP_Q_Q + buf[6];
        val_tmpe = TEMP / 10.0;
        //湿度
        if(buf[7] % 10 != 0)
        {
            HUMI_Q_H = buf[7] % 10 * 256;
        }
        else
        {
            HUMI_Q_H = 0;
        }
        if(buf[7] / 10 != 0)
        {
            HUMI_Q_Q = buf[7] / 10 * 4096;
        }
        else
        {
            HUMI_Q_Q = 0;
        }
        HUMI = HUMI_Q_Q + HUMI_Q_H + buf[8];
        val_hum = HUMI / 10.0;
//        printf("氨气含量:%.2f%%\n", NH4 / 10);
//        printf("温度:%.2f℃\n", TEMP / 10);
//        printf("湿度:%.2f%%\n", HUMI / 10);

        my_data.nh4 = NH4 / 10.0;
        my_data.temp = TEMP / 10.0;
        my_data.humi = HUMI / 10.0;
        my_data.count = k;
        time(&timep);
        p=localtime(&timep);
        sprintf(my_data.date, "%d-%02d-%02d %02d:%02d:%02d", 1900+p->tm_year, 1+p->tm_mon, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
        sprintf(sql_insert, "INSERT INTO data (id, gas, tem, hum, tim) VALUES(%d, %.2f, %.2f, %.2f, '%s');", my_data.count+num, my_data.nh4, my_data.temp, my_data.humi, my_data.date);

        save_to_sqlite(sql_insert);
        ret = send(sockfd, &my_data, sizeof(my_data), 0);
        if(ret < 0)
        {
            perror("send error");
            count++;
            if (60 < count)
            {
                count = 0;
                qDebug()<<"Reconnect the server";
                socket_init();
            }
        }
        usleep(2000000);
        k++;
    }
    ::close(fd);
}

void ThreadRead :: tty_set(int fd)
{
    struct termios newtio;

    /* ignore modem control lines and enable receiver */
    memset(&newtio, 0, sizeof(newtio));
    newtio.c_cflag = newtio.c_cflag |= CLOCAL | CREAD;
    newtio.c_cflag = newtio.c_cflag |= CLOCAL | CREAD | CRTSCTS;
    newtio.c_cflag &= ~CSIZE;

    /* set character size */
    newtio.c_cflag |= CS8;

    /* set the parity */
    newtio.c_cflag &= ~PARENB;

    /* set the stop bits */
    newtio.c_cflag &= ~CSTOPB;

    /* set output and input baud rate */
    cfsetospeed(&newtio, B9600);
    cfsetispeed(&newtio, B9600);

    /* set timeout in deciseconds for non-canonical read */
    newtio.c_cc[VTIME] = 0;

    /* set minimum number of characters for non-canonical read */
    newtio.c_cc[VMIN] = 1;

    /* flushes data received but not read */
    tcflush(fd, TCIFLUSH);
    /* set the parameters associated with the terminal from
        the termios structure and the change occurs immediately */
    if((tcsetattr(fd, TCSANOW, &newtio))!=0) {
        //perror("set_tty/tcsetattr");
        sprintf(err, "set_tty/tcsetattr error:%s, FILE:%s, LINE:%d", strerror(errno), __FILE__, __LINE__);
        qFatal(err);
    }
}

int ThreadRead::socket_init()
{
    int ret;
    struct sockaddr_in my_addr;
    //socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1)
    {
        //perror("socker error\n");
        sprintf(err, "[socker error:%s] [FILE:%s] [LINE:%d]", strerror(errno), __FILE__, __LINE__);
        qCritical(err);
        return 0;
    }
    //connect
    bzero(&my_addr, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(2500);
    ret = inet_pton(AF_INET, ip, &my_addr.sin_addr);
    if(ret == -1)
    {
        //perror("inet_pton error\n");
        sprintf(err, "[inet_pton error:%s] [FILE:%s] [LINE:%d]", strerror(errno), __FILE__, __LINE__);
        qCritical(err);
        return 0;
    }
    if(::connect(sockfd, (struct sockaddr*)&my_addr, (unsigned int)sizeof(my_addr)) == -1)
    {
        //perror("connect error\n");
        sprintf(err, "[connect server error:%s] [FILE:%s] [LINE:%d]", strerror(errno), __FILE__, __LINE__);
        qCritical(err);
        return 0;
    }
    else
    {
       // printf("connect success\n");
        qDebug()<<"connect success";
        return 1;
    }
}

int ThreadRead::conn_to_sqlite()
{
    char *errmsg;
    int ret, num = 0, nRow, nColumn, index;
    char **dbResult;
    //打开数据库
    ret = sqlite3_open("/mnt/tf/test.db", &db);
    if(ret != SQLITE_OK)
    {
        //perror("打开数据库失败\n");
        sprintf(err, "[open sqlite3 error:%s] [FILE:%s] [LINE:%d]", strerror(errno), __FILE__, __LINE__);
        qCritical(err);
        return -1;
    }
    char sql[] = "CREATE TABLE IF NOT EXISTS data(\
         [id] INTEGER,\
         [gas] REAL,\
         [tem] REAL,\
         [hum] REAL,\
         [tim] TEXT \
         );";
    ret = sqlite3_exec(db, sql, NULL, NULL, &errmsg);
    if(ret != SQLITE_OK)
    {
        //perror("表创建失败\n");
        sprintf(err, "[create or open table error:%s] [FILE:%s] [LINE:%d]", strerror(errno), __FILE__, __LINE__);
        qCritical(err);
        return -1;
    }

    //获取上次最后数据序号
    ret = sqlite3_get_table(db, "select * from data", &dbResult, &nRow, &nColumn, &errmsg);
    if(ret != SQLITE_OK)
    {
        //perror("查询最后数字失败\n");
        sprintf(err, "[Query the number of data in the database error:%s] [FILE:%s] [LINE:%d]", strerror(errno), __FILE__, __LINE__);
        qCritical(err);
        return -1;
    }
    if(nRow != 0)
    {
        index = nRow * nColumn;
        num = atoi(dbResult[index]);
    }
    return num;
}

void ThreadRead::save_to_sqlite(char sql_insert[])
{
    int ret;
    char *errmsg;

    ret = sqlite3_exec(db, sql_insert, NULL, NULL, &errmsg);
    if(ret != SQLITE_OK)
    {
        perror("插入数据库失败\n");
        exit(0);
    }
}
