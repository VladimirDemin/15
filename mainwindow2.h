#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game15widget.h"
#include <QMainWindow>
#include <QMessageBox>
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

private slots:
    void on_exit_triggered();
    void on_newGame_triggered();
    void on_restart_triggered();
    void TimerSlot();

private:
    Ui::MainWindow *ui;
    QTimer* timer;
    int ms;
    int s;
    int m;

};

#endif // MAINWINDOW_H
