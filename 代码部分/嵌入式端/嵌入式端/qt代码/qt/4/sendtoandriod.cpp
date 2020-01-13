#include "sendtoandriod.h"

#define SPORT 2500
#define SADDR "127.0.0.1"

extern "C"
{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<unistd.h>
    #include <pthread.h>
    #include<fcntl.h>
    #include<sys/types.h>
    #include <fcntl.h>
    #include <termios.h>
    #include<sys/socket.h>
    #include<arpa/inet.h>
    #include<time.h>
    #include <errno.h>
}

typedef struct android_
{
    int fd;
    char ip[20];
}android;

extern float val_nh4;
extern float val_tmpe;
extern float val_hum;
char err[200];
char reply[50];
extern SendToAndriod sendtoandriod;

SendToAndriod::SendToAndriod()
{

}

void *thread_recv(void *arg)
{
    android client = *(android *)arg;
    int ret;
    char buf[20];
    while (1)
    {
        memset(buf, 0, sizeof(buf));
        ret = recv(client.fd, buf, sizeof(buf), 0);
        if (0 > ret)
        {
            //perror("recv error\n");
            sprintf(err, " [recv error:%s] [FILE:%s] [LINE:%d]", strerror(errno), __FILE__, __LINE__);
            qCritical(err);
            pthread_exit(NULL);
        }
        else if (0 == ret)
        {
            qDebug()<<"Disconnect from Android!" <<" ip:"<<client.ip;
            pthread_exit(NULL);
        }
        if (0 == strncmp(buf, "temp", 4))
        {
            sprintf(reply, "温度：%.2f℃\n", val_tmpe);
            ret = send(client.fd, reply, strlen(reply), 0);
        }
        else if (0 == strncmp(buf, "hum", 3))
        {
            sprintf(reply, "湿度：%.2f%%\n", val_hum);
            ret = send(client.fd, reply, strlen(reply), 0);
        }
        else if (0 == strncmp(buf, "nh3", 3))
        {
            sprintf(reply, "氨气：%.2f%%\n", val_nh4);
            ret = send(client.fd, reply, strlen(reply), 0);
        }
        else if (0 == strncmp(buf, "q_on", 4))
        {
            system("/mnt/tf/web/run.sh");
        }
        else if (0 == strncmp(buf, "q_off", 5))
        {
            system("/mnt/tf/web/stop.sh");
        }
        else if (0 == strncmp(buf, "k_off", 5))
        {
            system("shutdown -h now");
        }
        else if (0 == strncmp(buf, "k_restart", 9))
        {
            system("reboot");
        }
        else
        {
            sprintf(reply, "request error\n");
            ret = send(client.fd, reply, strlen(reply), 0);
        }

        if (0 >= ret)
        {
            //perror("send error\n");
            sprintf(err, " [send error:%s] [FILE:%s] [LINE:%d]", strerror(errno), __FILE__, __LINE__);
            qCritical(err);
            pthread_exit(NULL);
        }
    }
}

void SendToAndriod::run()
{
    int sockfd;
    android andr_client;
        struct sockaddr_in seraddr, clientaddr;
        socklen_t addrlen;
        usleep(2000000);
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (-1 == sockfd)
        {
            //perror("socket error");
            sprintf(err, " [socket error:%s] [FILE:%s] [LINE:%d]", strerror(errno), __FILE__, __LINE__);
            qCritical(err);
            sendtoandriod.terminate();
            sendtoandriod.wait();
        }

        memset(&seraddr, 0, sizeof(seraddr));
        seraddr.sin_family = AF_INET;
        seraddr.sin_port = htons(SPORT);
        seraddr.sin_addr.s_addr = htonl(INADDR_ANY);

        if (-1 == bind(sockfd, (struct sockaddr *)&seraddr, sizeof(seraddr)))
        {
            //perror("bind error");
            sprintf(err, " [bind error:%s] [FILE:%s] [LINE:%d]", strerror(errno), __FILE__, __LINE__);
            qCritical(err);
            sendtoandriod.terminate();
            sendtoandriod.wait();
        }
        if (-1 == listen(sockfd, 10))
        {
            //perror("listen error");
            sprintf(err, " [listen error:%s] [FILE:%s] [LINE:%d]", strerror(errno), __FILE__, __LINE__);
            qCritical(err);
            sendtoandriod.terminate();
            sendtoandriod.wait();
        }

        addrlen = sizeof(clientaddr);
        while (1)
        {
            andr_client.fd = accept(sockfd, (struct sockaddr *)&clientaddr, &addrlen);
            if (-1 ==andr_client.fd)
            {
                //perror("accept error");
                sprintf(err, " [accept error:%s] [FILE:%s] [LINE:%d]", strerror(errno), __FILE__, __LINE__);
                qCritical(err);
                sendtoandriod.terminate();
                sendtoandriod.wait();
            }
            if (NULL == inet_ntop(AF_INET, (const void *)&clientaddr.sin_addr.s_addr, andr_client.ip, sizeof(andr_client.ip)))
            {
                perror("inet_ntop error");
                exit(1);
            }

            qDebug()<<"connect to android success! ip:"<<andr_client.ip;

            sprintf(reply, "连接成功\n");
            if (0 > send(andr_client.fd, reply, strlen(reply), 0))
            {
                sprintf(err, " [send error:%s] [FILE:%s] [LINE:%d]", strerror(errno), __FILE__, __LINE__);
                qCritical(err);
                sendtoandriod.terminate();
                sendtoandriod.wait();
            }

            pthread_t thread_id;
            if (0 != pthread_create(&thread_id, NULL,thread_recv, &andr_client))
            {
                qCritical("pthread_create error");
                sendtoandriod.terminate();
                sendtoandriod.wait();
            }
        }
}


