
#define MAINWINDOW_H

#include<Qmainwindow>

#include<QPainter>
#include<QTimer>
#include "ui_mainwindow.h"
#include<mypushbutton.h>
#include<gamehelp.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void paintEvent(QPaintEvent *);
    Ui::MainWindow *ui;
};
