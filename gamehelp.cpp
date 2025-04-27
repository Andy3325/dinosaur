#include <gamehelp.h>
#include"mypushbutton.h"
#include<QTimer>

GameHelp::GameHelp(QWidget *parent) : QWidget(parent) {
    setWindowTitle("help");
    resize(800, 550);
    MyPushButton *back_btn = new MyPushButton(":/photo/back.png");
    back_btn->setParent(this);
    back_btn->setFixedSize(180, 80);
    back_btn->setIconSize(QSize(180, 80));
    back_btn->move(500, this->height() * 0.8);
    connect(back_btn, &QPushButton::clicked, [=]() {
        back_btn->zoom1();
        back_btn->zoom2();
        QTimer::singleShot(500, this, [=]() {
            this->close();
            emit this->back();
        });
    });
}

void GameHelp::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, 800, 550, QPixmap(":/photo/gamehelp.png"));
}

