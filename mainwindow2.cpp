#include "mainwindow2.h"
#include "ui_mainwindow2.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     QMessageBox::information(this, "", tr("Игра не соберётся до начала игры."));

     ms=0;
     s=0;
     m=0;
     timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(TimerSlot()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_exit_triggered()
{
    close();
}

void MainWindow::on_newGame_triggered()
{
    ui->game15Widget->newGame();
    timer->start(1);
}
void MainWindow::on_restart_triggered()
{
    ui->game15Widget->restart_Game();
    timer->start(1);
}
void MainWindow::TimerSlot()
{
    ms++;
     if(ms>=1000)
     {
         ms=0;
         s++;
     }
     if(s>=60)
     {
         s=0;
         m++;
     }
     ui->label->setText("Время игры: " + QString::number(m)+":"+ QString::number(s)+":"+QString::number(ms));
}


