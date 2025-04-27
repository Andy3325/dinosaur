
#ifndef MUSHROOM_H
#define MUSHROOM_H
#include<QVector>
#include<QMap>
#include"brick.h"
#include"unknown.h"
#include"andy.h"
class MushRoom
{
public:
    QMap<int,QVector<QVector<int>>>m;
    int mushroom_kind;
    int mushroom_x;
    int mushroom_y;
    int mushroom_state;
    int mushroom_fall_down_distance;
    Brick *brick;
    Unknown *unknown;
    Andy *andy;
    MushRoom(int a);
    void MushRoom_Init1();
    void MushRoom_Init2();
    void MushRoom_Init3();
    void Move_state();
    void MushRoom_Move(QVector<QVector<int>>::iterator it,Unknown *u,Brick *r, Andy *m);
};

#endif // MUSHROOM_H
