#ifndef FEEL_H
#define FEEL_H

#include <QDialog>
#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include "all_file.h"

namespace Ui {
class feel;
}

class feel : public QDialog
{
    Q_OBJECT

public:
    explicit feel(QWidget *parent = 0);
    ~feel();

private slots:
    void on_pushButton_clicked();
    void time_update();
    void set_col();

//signals:
//    void sendsignal();//这个函数用户向主界面通知关闭的消息

private:
    Ui::feel *ui;
    QTimer *update_time = NULL;
    QLabel *currentTimeLabel;
};

#endif // FEEL_H
