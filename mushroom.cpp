#include <mushroom.h>
#include"global.h"
#include<QDebug>

MushRoom::MushRoom(int a)
{
    if(a==1)
    {
        MushRoom_Init1();
    }
    if(a==2)
    {
        MushRoom_Init2();
    }
    if(a==3)
    {
        MushRoom_Init3();
    }
}

void MushRoom::MushRoom_Init1(){
    mushroom_kind=0;
    mushroom_x=0;
    mushroom_y=0;
    mushroom_state=0;
    mushroom_fall_down_distance=19;
}

void MushRoom::MushRoom_Init2(){
    mushroom_kind=0;
    mushroom_x=0;
    mushroom_y=0;
    mushroom_state=0;
    mushroom_fall_down_distance=19;
}

void MushRoom::MushRoom_Init3(){
    mushroom_kind=0;
    mushroom_x=0;
    mushroom_y=0;
    mushroom_state=0;
    mushroom_fall_down_distance=19;
}

void MushRoom::MushRoom_Move(QVector<QVector<int>>::iterator it,Unknown *u,Brick *r, Andy *m){
    unknown = u;
    brick = r;
    andy = m;
    if((andy->colour==1)||(andy->colour==3)){
        mushroom_kind = 1;
    }else{
        mushroom_kind = 2;
    }
    mushroom_x = *it->begin();
    mushroom_y = *(it->begin() + 1);
    mushroom_state = 1;
}

void MushRoom::Move_state(){
    if (mushroom_state != 0 && mushroom_state != -2) {
        if (mushroom_state <= 20) {
            mushroom_y -= 2;
            mushroom_state++;
        } else if (mushroom_state > 20) {
            mushroom_x += 2;
            mushroom_state++;
        }
        for (QVector < QVector < int >> ::iterator it = brick->m.begin()->begin(); it != brick->m.begin()->end();it++)
        {
            if (*it->begin() - mushroom_x >= -50 && *it->begin() - mushroom_x <= 30 &&
                *(it->begin() + 1) <= mushroom_y + 40 && *(it->begin() + 1) >= mushroom_y && *(it->begin() + 2) != 0) {
                return;
            }
        }
        for (QVector < QVector < int >> ::iterator it = unknown->m.begin()->begin(); it != unknown->m.begin()->end();it++)
        {
            if (*it->begin() - mushroom_x >= -50 && *it->begin() - mushroom_x <= 30 &&
                *(it->begin() + 1) <= mushroom_y + 40 && *(it->begin() + 1) >= mushroom_y) {
                return;
            }
        }
        mushroom_state = -1;
        mushroom_y += 20 - mushroom_fall_down_distance;
        mushroom_fall_down_distance--;

    }
    if (mushroom_y >= 460 && mushroom_state != 0) {
        if (mushroom_x - 330 <= andy->x && mushroom_x - 270 >= andy->x && mushroom_y - andy->y == 5) {
            mushroom_state = 0;
            andy->colour = mushroom_kind + 1;
            musicPlayer->play(PowerUp);
            mushroom_fall_down_distance = 19;
            return;
        }
        mushroom_state = -2;
        mushroom_y = 460;
        mushroom_x -= 2;
    }
}

