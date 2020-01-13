#include "log_i.h"
#include "ui_log_i.h"
#include <QDebug>
#include <QFile>
#include <QPropertyAnimation>
#include <QStyledItemDelegate>

log_i::log_i(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::log_i)
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
    QFont font;
    font.setPointSize(16);//实际上是16的字号，但设成16却不行
    font.setFamily(("wenquanyi"));
    font.setBold(false);
    ui->setupUi(this);
    ui->pushButton->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    ui->pushButton_query->setStyleSheet("border:2px groove gray;border-radius:10px;padding:2px 4px;");
    QStyledItemDelegate *delegate = new QStyledItemDelegate(this);
    ui->comboBox_grade->setItemDelegate(delegate);
    ui->comboBox_grade->setStyleSheet("QComboBox QAbstractItemView::item {min-height: 40px;}");
    ui->comboBox_grade->addItem("调试信息");
    ui->comboBox_grade->addItem("警告信息");
    ui->comboBox_grade->addItem("严重错误");
    ui->comboBox_grade->addItem("致命错误");
    ui->pushButton->setFont(font);
    ui->pushButton_query->setFont(font);
    ui->comboBox_grade->setFont(font);
    ui->label->setFont(font);

    //渐变
    QPropertyAnimation *animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(1000);
    animation->setStartValue(0);     animation->setEndValue(1);
    animation->start();
}

log_i::~log_i()
{
    delete ui;
}

//void log_i::reshow()
//{
//    this->show();
//}

void log_i::on_pushButton_clicked()
{
    //emit sendsignal();
    this->close();
   // this->setAttribute(Qt::WA_DeleteOnClose,1);
    all_file *all_filedlg = new all_file(this);//新建子界面
    all_filedlg->show();//子界面出现
}

void log_i::on_pushButton_query_clicked()
{
    int num = 1;
    qDebug()<<"View log";
    ui->textEdit->clear();
    QString displayString;
    int choose = ui->comboBox_grade->currentIndex();
    QFile file("run.log");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //qDebug()<<"Can't open the file!"<<endl;
        sprintf(err, "Can't open the file, FILE:%s, LINE:%d",  __FILE__, __LINE__);
        qCritical(err);
    }
    while(!file.atEnd())
    {
        QByteArray line = file.readLine();
        QString str(line);
        //QString str_line(line);
        //QString str = QString("%1、%2").arg(num).arg(str_line);
        if (0 == choose && str.startsWith("Debug:"))
        {
            displayString.append(str+"\n");
            num++;
        }
        else if (1 == choose && str.startsWith("Warning:"))
        {
            displayString.append(str+"\n");
            num++;
        }
        else if (2 == choose && str.startsWith("Critical:"))
        {
            displayString.append(str+"\n");
            num++;
        }
        else if (3 == choose && str.startsWith("Fatal:"))
        {
            displayString.append(str+"\n");
            num++;
        }
    }
    QFont font;
    font.setPointSize(16);//实际上是16的字号，但设成16却不行
    font.setFamily(("wenquanyi"));
    font.setBold(false);
    ui->textEdit->setPlainText(displayString);
    ui->textEdit->setFont(font);
}
