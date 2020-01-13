#include "history.h"
#include "ui_history.h"
//#include "keyBoard.h"
#include <QTextCodec>
#include <QPropertyAnimation>
#include <QStyledItemDelegate>

history::history(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::history)
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
//    keyBoard keyboard;
//    keyboard.hide();
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton_last->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton_next->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton_query->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    init_sql();
    init_table();
    //中文支持
    QFont font;
    font.setPointSize(16);//实际上是16的字号，但设成16却不行
    font.setFamily(("wenquanyi"));
    font.setBold(false);
    ui->pushButton->setFont(font);
    ui->pushButton_last->setFont(font);
    ui->pushButton_next->setFont(font);
    ui->pushButton_query->setFont(font);
    ui->label->setFont(font);
    ui->label_2->setFont(font);
    ui->label_3->setFont(font);
    ui->label_4->setFont(font);
    ui->label_5->setFont(font);
    ui->label_6->setFont(font);
    ui->label_7->setFont(font);
    ui->label_8->setFont(font);
    ui->label_9->setFont(font);
    ui->label_10->setFont(font);
    ui->lineEdit->setText("input");

    //渐变
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(0);     animation->setEndValue(1);
    animation->start();
}

history::~history()
{
    delete ui;
}

void history::init_sql()
{
    if(QSqlDatabase::contains("SQLITE"))
    {
        db = QSqlDatabase::database("SQLITE");
     }
    else
    {
        db = QSqlDatabase::addDatabase("QSQLITE", "SQLITE");
    }
    //db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/mnt/tf/test.db");
    if (!db.open())
    {
        qDebug() << "Error: Failed to connect database." << db.lastError();
        sprintf(err, "Failed to connect database, FILE:%s, LINE:%d", __FILE__, __LINE__);
        qCritical(err);
    }
}

void history::init_table()
{
    int i, year_now, mon, day, hour;
    struct tm *p;
    time_t timep;
    time(&timep);
    p=localtime(&timep);
    year_now = 1900+p->tm_year;
    mon = 1+p->tm_mon;
    day = p->tm_mday;
    hour = p->tm_hour;

    QStyledItemDelegate *delegate = new QStyledItemDelegate(this);
    ui->comboBox_fyear->setItemDelegate(delegate);
    ui->comboBox_fyear->setStyleSheet("QComboBox QAbstractItemView::item {min-height: 40px;}");
    ui->comboBox_nyear->setItemDelegate(delegate);
    ui->comboBox_nyear->setStyleSheet("QComboBox QAbstractItemView::item {min-height: 40px;}");
    ui->comboBox_fmon->setItemDelegate(delegate);
    ui->comboBox_fmon->setStyleSheet("QComboBox QAbstractItemView::item {min-height: 40px;}");
    ui->comboBox_nmon->setItemDelegate(delegate);
    ui->comboBox_nmon->setStyleSheet("QComboBox QAbstractItemView::item {min-height: 40px;}");
    ui->comboBox_fday->setItemDelegate(delegate);
    ui->comboBox_fday->setStyleSheet("QComboBox QAbstractItemView::item {min-height: 40px;}");
    ui->comboBox_nday->setItemDelegate(delegate);
    ui->comboBox_nday->setStyleSheet("QComboBox QAbstractItemView::item {min-height: 40px;}");
    ui->comboBox_fhour->setItemDelegate(delegate);
    ui->comboBox_fhour->setStyleSheet("QComboBox QAbstractItemView::item {min-height: 40px;}");
    ui->comboBox_nhour->setItemDelegate(delegate);
    ui->comboBox_nhour->setStyleSheet("QComboBox QAbstractItemView::item {min-height: 40px;}");

    for (i = 2000; i <= year_now; i++)
    {
        ui->comboBox_fyear->addItem(QString::number(i));
        ui->comboBox_nyear->addItem(QString::number(i));
    }
    ui->comboBox_fyear->setStyleSheet("QComboBox QAbstractItemView::item {min-height: 50px;}");
    for (i = 1; i <= 12; i++)
    {
        ui->comboBox_fmon->addItem(QString::number(i));
        ui->comboBox_nmon->addItem(QString::number(i));
    }
    for (i = 1; i <= 31; i++)
    {
        ui->comboBox_fday->addItem(QString::number(i));
        ui->comboBox_nday->addItem(QString::number(i));
    }
    for (i = 0; i <= 23; i++)
    {
        ui->comboBox_fhour->addItem(QString::number(i));
        ui->comboBox_nhour->addItem(QString::number(i));
    }
    ui->comboBox_fyear->setCurrentIndex(year_now-2000);
    ui->comboBox_nyear->setCurrentIndex(year_now-2000);
    ui->comboBox_fmon->setCurrentIndex(mon-1);
    ui->comboBox_nmon->setCurrentIndex(mon-1);
    ui->comboBox_fday->setCurrentIndex(day-1);
    ui->comboBox_nday->setCurrentIndex(day-1);
    ui->comboBox_fhour->setCurrentIndex(hour);
    ui->comboBox_nhour->setCurrentIndex((hour+1)%24);

    ui->tableWidget->setRowCount(MAXCOUNT);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setColumnWidth(1,180);
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"ID"<<"TIME"<<"TEM"<<"HUM"<<"NH4");
    ui->label_count->setText("记录数量:");
    ui->label_page->setText("0页");
    QFont font;
    font.setPointSize(16);//实际上是16的字号，但设成16却不行
    font.setFamily(("wenquanyi"));
    font.setBold(false);
    ui->label_count->setFont(font);
    ui->label_page->setFont(font);
}

void history::on_pushButton_clicked()
{
    db.close();
    //emit sendsignal();
    this->close();
    //this->setAttribute(Qt::WA_DeleteOnClose,1);
    all_file *all_filedlg = new all_file(this);//新建子界面
    all_filedlg->show();//子界面出现
}

void history::on_pushButton_query_clicked()
{
    qDebug()<<"View history";
    QString query;
    int fyear=ui->comboBox_fyear->currentText().toInt();
    int nyear=ui->comboBox_nyear->currentText().toInt();
    int fmon=ui->comboBox_fmon->currentText().toInt();
    int nmon=ui->comboBox_nmon->currentText().toInt();
    int fday=ui->comboBox_fday->currentText().toInt();
    int nday=ui->comboBox_nday->currentText().toInt();
    int fhour=ui->comboBox_fhour->currentText().toInt();
    int nhour=ui->comboBox_nhour->currentText().toInt();
    tim_begin.sprintf("%04d-%02d-%02d %02d:00:00", fyear, fmon, fday, fhour);
    tim_end.sprintf("%04d-%02d-%02d %02d:00:00", nyear, nmon, nday, nhour);
//    qDebug()<<tim_begin;
//    qDebug()<<tim_end;
    query = QString("select count(*) from data where tim between '%1' and '%2'").arg(tim_begin).arg(tim_end);
    QSqlQuery sql_query(query, db);
    //QSqlQuery sql_query;
    if (!sql_query.exec())
    {
        //qDebug()<<sql_query.lastError();
        sprintf(err, "Failed to calculate the number of data queried:%s, FILE:%s, LINE:%d", sql_query.lastError(), __FILE__, __LINE__);
        qCritical(err);
    }
    else
    {
        while (sql_query.next())
        {
            QString count = sql_query.value(0).toString();
//            qDebug()<<count;
            ui->label_count->setText("记录数量: "+count);
            max_page = count.toInt();
            max_page = (max_page+(MAXCOUNT-1)) / MAXCOUNT;
        }
    }
    page = 1;
    showpage();
}

void history::on_pushButton_last_clicked()
{
    if (1 >= page)
    {
        return;
    }
    page--;
    showpage();
}

void history::on_pushButton_next_clicked()
{
    if (max_page <= page)
    {
        return;
    }
    page++;
    showpage();
}

void history::showpage()
{
    int i;
    QString str;
    QString query;
    ui->tableWidget->clearContents();
    number = (page-1)*MAXCOUNT + 1;
    query = QString("select * from data where tim between '%1' and '%2' order by tim asc limit %3,%4").arg(tim_begin).arg(tim_end).arg((page-1)*MAXCOUNT).arg(MAXCOUNT);
    QSqlQuery sql_query(query, db);
    if (!sql_query.exec())
    {
        //qDebug()<<sql_query.lastError();
        sprintf(err, "Failed to query data:%s, FILE:%s, LINE:%d", sql_query.lastError(), __FILE__, __LINE__);
        qCritical(err);
    }
    else
    {
        i = 0;
        while(sql_query.next())
        {
            QString time = sql_query.value(4).toString();
            QString tem = sql_query.value(2).toString();
            QString hum = sql_query.value(3).toString();
            QString nh4 = sql_query.value(1).toString();
            QString str_num = QString::number(number);
            ui->tableWidget->setItem(i,0,new QTableWidgetItem(str_num));
            //qDebug()<<QString("时间:%1 温度:%2 湿度:%3 氨气:%4").arg(time).arg(tem).arg(hum).arg(nh4);
            ui->tableWidget->setItem(i,1,new QTableWidgetItem(time));
            ui->tableWidget->setItem(i,2,new QTableWidgetItem(tem));
            ui->tableWidget->setItem(i,3,new QTableWidgetItem(hum));
            ui->tableWidget->setItem(i,4,new QTableWidgetItem(nh4));
            i++;
            number++;
        }
        str.sprintf("%d/%d页", page, max_page);
        ui->label_page->setText(str);
    }
}
