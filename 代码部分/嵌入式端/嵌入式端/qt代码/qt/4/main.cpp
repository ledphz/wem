#include "mainwindow.h"
#include "threadread.h"
#include "sendtoandriod.h"
//#include "keyBoard.h"
#include <QApplication>
#include <QTextCodec>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <stdio.h>
#include <QDateTime>
#include <QWidget>
#include <QWSServer>

float val_nh4 = 0.0;    //氨气
float val_tmpe = 0.0;   //温度
float val_hum = 0.0;    //湿度
ThreadRead threadread;
SendToAndriod sendtoandriod;

void myMessageOutput(QtMsgType type, const char *msg)
{

    /* 往控制台中打印 */
        switch (type)
        {
        case QtDebugMsg:
            fprintf(stderr, "%s\n", msg);
            break;
        case QtWarningMsg:
            fprintf(stderr, "Warning: %s\n", msg);
            break;
        case QtCriticalMsg:
            fprintf(stderr, "Critical: %s\n", msg);
            break;
        case QtFatalMsg:
            fprintf(stderr, "Fatal: %s\n", msg);
        }

        /*输出到日志文件*/
    QString text;
    QString date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    switch (type)
    {
    case QtDebugMsg:
        text = QString("Debug: %1 [Date: %2]").arg(msg).arg(date_time);
        break;
    case QtWarningMsg:
        text = QString("Warning: %1 [Date: %2]").arg(msg).arg(date_time);
        break;
    case QtCriticalMsg:
        text = QString("Critical: %1 [Date: %2]").arg(msg).arg(date_time);
        break;
    case QtFatalMsg:
        text = QString("Fatal: %1 [Date: %2]").arg(msg).arg(date_time);
        //abort();  //注释掉依旧会退出程序，如果不注释掉将无法写入日志文件。
        break;
    }

    QFile file("/mnt/tf/run.log");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream ts(&file);
    ts<<text<<endl;
}

int main(int argc, char *argv[])
{
    qInstallMsgHandler(myMessageOutput);
    qDebug()<<"Startup program";
    QApplication a(argc, argv);
    //中文支持
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));       //支持Tr中文
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));//支持中文文件名显示
//    QFont font;
//    font.setPointSize(16);//实际上是16的字号，但设成16却不行
//    font.setFamily(("wenquanyi"));
//    font.setBold(false);
//    a.setFont(font);
    QWSServer::setBackground(QColor(188,210,230));
    MainWindow w;
    //修改大小
    w.resize( 800, 480);
//    keyBoard keyboard;
//    keyboard.hide();

    threadread.start();
    sendtoandriod.start();
    w.show();

//    qDebug() << "This is a debug";
//    qWarning() << "This is a warning!";
//    qCritical("This is a critical message");
//    qFatal("This is a fatal message");
    return a.exec();
}
