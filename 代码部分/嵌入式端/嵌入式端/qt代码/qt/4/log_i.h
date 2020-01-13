#ifndef LOG_I_H
#define LOG_I_H

#include <QDialog>
#include "all_file.h"

namespace Ui {
class log_i;
}

class log_i : public QDialog
{
    Q_OBJECT

public:
    explicit log_i(QWidget *parent = 0);
    ~log_i();

private slots:
    //void reshow();

    void on_pushButton_clicked();

    void on_pushButton_query_clicked();

//signals:
//    void sendsignal();//这个函数用户向主界面通知关闭的消息

private:
    Ui::log_i *ui;
    char err[200];
};

#endif // LOG_I_H
