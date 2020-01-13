#include "feel.h"
#include "ui_feel.h"
#include <stdio.h>
#include <QtDebug>
#include <QWidget>
#include <QPropertyAnimation>

extern float val_nh4;
extern float val_tmpe;
extern float val_hum;

feel::feel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::feel)
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
    QFont font;
    font.setPointSize(16);//实际上是16的字号，但设成16却不行
    font.setFamily(("wenquanyi"));
    font.setBold(false);
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->label_tmpe->setStyleSheet("color:#71C671;");
    ui->label_hum->setStyleSheet("color:#71C671;");
    ui->label_nh3->setStyleSheet("color:#71C671;");
    ui->pushButton->setFont(font);

    QString str_nh4;       //氨气
    QString str_tmpe;  //温度
    QString str_hum;    //湿度

    str_nh4.sprintf(" %.2f", val_nh4);
    ui->label_nh3->setText(str_nh4);

    str_tmpe.sprintf("%.2f", val_tmpe);
    ui->label_tmpe->setText(str_tmpe);

    str_hum.sprintf(" %.2f", val_hum);
    ui->label_hum->setText(str_hum);

    QString date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    ui->label_time->setText(date_time);

    //设置为多次触发
    if (update_time == NULL)
    {
        update_time = new QTimer;
        update_time->setSingleShot(false);
        connect(update_time,SIGNAL(timeout()),this,SLOT(time_update()));
        update_time->start(1000);
     }

    //渐变
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(0);     animation->setEndValue(1);
    animation->start();
}

feel::~feel()
{
    delete ui;
}

void feel::on_pushButton_clicked()
{
    if (update_time->isActive())
    {
        update_time->stop();
    }
    //emit sendsignal();
    this->close();
    //this->setAttribute(Qt::WA_DeleteOnClose,1);
    all_file *all_filedlg = new all_file(this);//新建子界面
    all_filedlg->show();//子界面出现
}

void feel::time_update()
{
    QString str_nh4;       //氨气
    QString str_tmpe;  //温度
    QString str_hum;    //湿度

    QString date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    ui->label_time->setText(date_time);

    str_nh4.sprintf("%.2f", val_nh4);
    ui->label_nh3->setText(str_nh4);

    str_tmpe.sprintf("%.2f", val_tmpe);
    ui->label_tmpe->setText(str_tmpe);

    str_hum.sprintf("%.2f", val_hum);
    ui->label_hum->setText(str_hum);
    set_col();
}


//设置颜色等级
void feel::set_col()
{
    //设置温度
    if (0> val_tmpe)    //非常冷
    {
        ui->label_tmpe->setStyleSheet("color:#6A5ACD;");
    }
    else if (20 > val_tmpe)     //比较冷
    {
        ui->label_tmpe->setStyleSheet("color:#1E90FF;");
    }
    else if (28 > val_tmpe)     //适宜
    {
        ui->label_tmpe->setStyleSheet("color:#71C671;");
    }
    else if (35 > val_tmpe)     //比较热
    {
        ui->label_tmpe->setStyleSheet("color:#EE7600;");
    }
    else   //非常热
    {
        ui->label_tmpe->setStyleSheet("color:#EE0000;");
    }

    //设置湿度
    if (30 > val_hum)   //干燥
    {
        ui->label_hum->setStyleSheet("color:#EE0000;");
    }
    else if (70 > val_hum)  //适宜
    {
        ui->label_hum->setStyleSheet("color:#71C671;;");
    }
    else        //潮湿
    {
         ui->label_hum->setStyleSheet("color:#1E90FF;");
    }

    //设置氨气
    if (0.76 > val_nh4)     //正常
    {
        ui->label_nh3->setStyleSheet("color:#71C671;");
    }
    else if (11.4 > val_nh4)    //偏高
    {
        ui->label_nh3->setStyleSheet("color:#EE7600;");
    }
    else    //危险
    {
        ui->label_nh3->setStyleSheet("color:#EE0000;");
    }
}
