#include "all_file.h"
#include "ui_all_file.h"
#include <QMovie>
#include "threadread.h"
#include "sendtoandriod.h"
#include <QPropertyAnimation>

extern ThreadRead threadread;
extern SendToAndriod sendtoandriod;

all_file::all_file(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::all_file)
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
    //中文支持
    QFont font;
    font.setPointSize(16);//实际上是16的字号，但设成16却不行
    font.setFamily(("wenquanyi"));
    font.setBold(false);
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton_2->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton_3->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton_4->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton_5->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton->setFont(font);
    ui->pushButton_2->setFont(font);
    ui->pushButton_3->setFont(font);
    ui->pushButton_4->setFont(font);
    ui->pushButton_5->setFont(font);
    //渐变
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();

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
}

all_file::~all_file()
{
    delete ui;
}

//void all_file::reshow()
//{
//    this->show();
//}

void all_file::on_pushButton_clicked()//look
{
    //this->hide();//主界面关闭
    this->close();
    look *lookdlg = new look(this);//新建子界面
    //connect(lookdlg,SIGNAL(sendsignal()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
    lookdlg->show();//子界面出现
}

void all_file::on_pushButton_3_clicked()//feel
{
    this->close();//主界面关闭
    feel *feeldlg = new feel(this);//新建子界面
    //connect(feeldlg,SIGNAL(sendsignal()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
    feeldlg->show();//子界面出现
}

void all_file::on_pushButton_2_clicked()
{
    this->close();//主界面关闭
    log_i *log_idlg = new log_i(this);//新建子界面
    //connect(log_idlg,SIGNAL(sendsignal()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
    log_idlg->show();//子界面出现
}

void all_file::on_pushButton_4_clicked()
{
    this->close();//主界面关闭
    history *historydlg = new history(this);//新建子界面
    //connect(historydlg,SIGNAL(sendsignal()),this,SLOT(reshow()));//当点击子界面时，调用主界面的reshow()函数
    historydlg->show();//子界面出现
}

void all_file::on_pushButton_5_clicked()
{
    threadread.terminate();
    threadread.wait();
    sendtoandriod.terminate();
    sendtoandriod.wait();
    qDebug()<<"close program";
    this->close();
    this->setAttribute(Qt::WA_DeleteOnClose,1);
}

void all_file::time_update()
{
    QString date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    ui->label_time->setText(date_time);
}
