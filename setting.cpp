#include <setting.h>
#include"global.h"
#include"mypushbutton.h"
#include<QTimer>

Gameset::Gameset(QWidget *parent) : QWidget(parent) {
    setWindowTitle("setting");
    resize(800, 550);
    MyPushButton *openVoice_btn = new MyPushButton(":/photo/openVoice.jpg");
    openVoice_btn->setParent(this);
    openVoice_btn->setFixedSize(180, 80);
    openVoice_btn->setIconSize(QSize(180, 80));
    openVoice_btn->move(500, this->height() * 0.4);
    connect(openVoice_btn, &QPushButton::clicked, [=]() {
        openVoice_btn->zoom1();
        openVoice_btn->zoom2();
        musicPlayer = new MusicPlayer;
        musicPlayer->backMusicPlay(Start);
        QTimer::singleShot(500, this, [=]() {
            this->close();
            emit this->back();
        });
    });

    MyPushButton *closeVoice_btn = new MyPushButton(":/photo/closeVoice.jpg");
    closeVoice_btn->setParent(this);
    closeVoice_btn->setFixedSize(180, 80);
    closeVoice_btn->setIconSize(QSize(180, 80));
    closeVoice_btn->move(500, this->height() * 0.6);
    connect(closeVoice_btn, &QPushButton::clicked, [=]() {
        closeVoice_btn->zoom1();
        closeVoice_btn->zoom2();
        stopAllBackMusic();
        delete musicPlayer;
        QTimer::singleShot(500, this, [=]() {
            this->close();
            emit this->back();
        });
    });

    MyPushButton *backgame_btn = new MyPushButton(":/photo/back.jpg");
    backgame_btn->setParent(this);
    backgame_btn->setFixedSize(180, 80);
    backgame_btn->setIconSize(QSize(180, 80));
    backgame_btn->move(500, this->height() * 0.8);
    connect(backgame_btn, &QPushButton::clicked, [=]() {
        backgame_btn->zoom1();
        backgame_btn->zoom2();
        QTimer::singleShot(500, this, [=]() {
            this->close();
            emit this->back();
        });
    });
}

void Gameset::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.drawPixmap(0, 0, 800, 550, QPixmap(":/photo/background4.jpg"));
}


