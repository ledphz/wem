#ifndef  LOOK_H
#define LOOK_H

#include <QMainWindow>
#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QtNetwork>
#include<QPixmap>
#include<QPainter>
#include<QImage>
#include<QFile>
#include<QPixmap>
#include<QTimer>
#include<QMessageBox>
#include <QTimer>
#include "all_file.h"

namespace Ui {
class look;
}

class look : public QDialog
{
    Q_OBJECT

public:
    explicit look(QWidget *parent = 0);
    ~look();
    void StopPic();

private slots:
    void on_pushButton_2_clicked();
    void PicConnect();
    void slot_replyFinished(QNetworkReply* reply);
    //void finished();


//signals:
//    void sendsignal();//这个函数用户向主界面通知关闭的消息

    void on_pushButton_screenshot_clicked();

private:
    Ui::look *ui;
    QNetworkAccessManager *manager;
    bool isPicOnLabel;
    QNetworkReply *reply;
    QTimer *update_time = NULL;
    QPixmap pix;
    int flag = 0;
};

#endif // LOOK_H
