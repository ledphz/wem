#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);
    ui->setupUi(this);
    ui->pushButton_touming->setFlat(true);
    ui->label->setScaledContents(true);
    QMovie *movie = new QMovie(":/new/prefix1/world.gif");
    ui->label->setMovie(movie);
    movie->start();

    //设置定时器
    if (update_time == NULL)
    {
        update_time = new QTimer;
        update_time->setSingleShot(true);
        connect(update_time,SIGNAL(timeout()),this,SLOT(time_update()));
        update_time->start(19000);
     }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::time_update()
{
    this->hide();//主界面关闭
    all_file *all_filedlg = new all_file(this);//新建子界面
    all_filedlg->show();//子界面出现
}


void MainWindow::on_pushButton_touming_clicked()
{
    if (update_time->isActive())
    {
        update_time->stop();
    }
    //this->hide();//主界面关闭
    this->close();
    all_file *all_filedlg = new all_file(this);//新建子界面
    all_filedlg->show();//子界面出现
}
