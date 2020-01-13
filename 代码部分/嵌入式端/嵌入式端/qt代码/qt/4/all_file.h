#ifndef ALL_FILE_H
#define ALL_FILE_H

#include <QDialog>
#include "look.h"
#include"feel.h"
#include "log_i.h"
#include "history.h"

namespace Ui {
class all_file;
}

class all_file : public QDialog
{
    Q_OBJECT

public:
    explicit all_file(QWidget *parent = 0);
    ~all_file();

private slots:
    void on_pushButton_clicked();

    //void reshow();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();
    void time_update();

private:
    Ui::all_file *ui;
    QTimer *update_time = NULL;
};

#endif // ALL_FILE_H
