
#ifndef LEVEL2_H
#define LEVEL2_H

#include <QWidget>
#include<QPainter>
#include<QDebug>
#include<QString>
#include<QTimer>
#include<QKeyEvent>
#include<QDialog>
#include"andy.h"
#include"brick.h"
#include"unknown.h"
#include"mushroom.h"
#include"master.h"
#include"pipe.h"
#include"gamepause.h"
#include<mypushbutton.h>
#include"fire.h"
#include"castle.h"
#include"bullet.h"
#include"flower.h"
#include"diamond.h"

class level2 : public QWidget {
    Q_OBJECT

public:
    explicit level2(QWidget *parent = nullptr);
    int timer1;
    int timer2;
    int timer3;
    bool is_kill_timer2;
    bool game_start;
    bool open;
    double time;
    double invincible_time = 0.0;
    int score;
    bool is_press_x;
    bool is_win;
    QString key;
    Andy *andy;
    Brick *brick;
    Flower *flower;
    Diamond *diamond;
    Pipe *pipe;
    Unknown *unknown;
    MushRoom *mushroom;
    GamePause *Pause;
    Master *master;
    Bullet *bullet;
    Fire *fire;
    Castle *castle;

    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void timerEvent(QTimerEvent *event);
    void Game_Init();

    void Die_Init();

    void Pause_Init();

    void Pause_Game_Init();

    void Fall_Down(int &y);

    void Jump_Collision();
    void Move_Collision();
    bool level2_Win(bool is_win);
    void Game_Over();
signals:
    void back();
private:

};

#endif // LEVEL2_H
