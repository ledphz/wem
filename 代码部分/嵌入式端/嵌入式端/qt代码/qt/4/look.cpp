#include "look.h"
#include "ui_look.h"
#include<QDebug>
#include <stdio.h>
#include <unistd.h>
#include <QTextCodec>
#include "all_file.h"
#include <QPropertyAnimation>
#include <QDesktopWidget>

look::look(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::look)
{
    reply = NULL;
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
    qDebug()<<"view video";
    QFont font;
    font.setPointSize(16);
    font.setFamily(("wenquanyi"));
    font.setBold(false);
    ui->setupUi(this);
    ui->pushButton_2->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton_2->setFont(font);
    ui->pushButton_screenshot->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton_screenshot->setFont(font);

//    QTextCodec *codec = QTextCodec::codecForName("System");
//    QTextCodec::setCodecForTr(codec);
//    QTextCodec::setCodecForLocale(codec);
//    QTextCodec::setCodecForCStrings(codec);

    QString date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    ui->label_time->setText(date_time);

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_replyFinished(QNetworkReply*)));

    //设置为多次触发
    if (update_time == NULL)
    {
        update_time = new QTimer;
        update_time->setSingleShot(false);
        connect(update_time,SIGNAL(timeout()),this,SLOT(PicConnect()));
        update_time->start(100);
     }

    //渐变
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(0);     animation->setEndValue(1);
    animation->start();
}

look::~look()
{
    delete ui;
}

void look::on_pushButton_2_clicked()
{
    if (update_time->isActive())
    {
        update_time->stop();
    }
//    emit sendsignal();
    this->close();
//    this->setAttribute(Qt::WA_DeleteOnClose,1);
    all_file *all_filedlg = new all_file(this);//新建子界面
    all_filedlg->show();//子界面出现
}

void look::PicConnect()
{
    QString date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    ui->label_time->setText(date_time);

    QNetworkRequest request;
    request.setUrl(QUrl("http://192.168.0.100:8080/?action=snapshot"));
    reply = manager->get(request);
}

void look::slot_replyFinished(QNetworkReply* reply)
{       //save the picture
    QByteArray data = reply->readAll();
    //qDebug()<<reply->isFinished();'
    pix.loadFromData(data, "JPEG");
    if (1 == flag)
    {
        flag = 0;
        QString date_time = QDateTime::currentDateTime().toString("yyyyMMddhhmmss");
        QString filename = QString("/mnt/tf/screenshot/%1.jpeg").arg(date_time);
        qDebug()<<filename;
        pix.save(filename, "JPEG", 100);
    }
//    ui->label->setStyleSheet("border:2px groove gray;border-radius:30px;padding:2px 4px;");
//    pix.scaled(ui->label->size(), Qt::KeepAspectRatio);
//    ui->label->setScaledContents(true);
    ui->label->setPixmap(pix);
    //delete manager;
    reply->deleteLater();
    //manager->deleteLater();
}

void look::StopPic()
{
    isPicOnLabel=false;
}

void look::on_pushButton_screenshot_clicked()
{
    flag = 1;
    qDebug()<<"screenshot";
}
