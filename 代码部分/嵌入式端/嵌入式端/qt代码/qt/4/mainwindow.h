#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "all_file.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void StopPic();

private slots:
    void time_update();

    void on_pushButton_touming_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *update_time = NULL;
};

#endif // MAINWINDOW_H
