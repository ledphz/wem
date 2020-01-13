#ifndef HISTORY_H
#define HISTORY_H

#include <QDialog>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
#include <time.h>
#include <stdio.h>
#include "all_file.h"

#define MAXCOUNT 7

namespace Ui {
class history;
}

class history : public QDialog
{
    Q_OBJECT

public:
    explicit history(QWidget *parent = 0);
    ~history();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_query_clicked();
    void showpage();
    void init_table();
    void init_sql();
    void on_pushButton_last_clicked();
    void on_pushButton_next_clicked();

//signals:
//    void sendsignal();//这个函数用户向主界面通知关闭的消息

private:
    Ui::history *ui;
    //QTimer *update_time = NULL;
    int max_page;
    int page, number;
    QString tim_begin;
    QString tim_end;
    char err[200];
    QSqlDatabase db;
};

#endif // HISTORY_H
