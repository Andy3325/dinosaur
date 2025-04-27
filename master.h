
#ifndef MASTER_H
#define MASTER_H

#include<QMap>
#include<QVector>
#include<QString>
#include"pipe.h"
#include"brick.h"
#include<andy.h>



class Master {
public:
    QString direction;
    int die_state;
    Andy *andy;
    Pipe *pipe;
    Brick *brick;
    QVector <QVector<int>> v1;
    QMap<int, QVector<QVector < int>>> m;
    QVector<QVector < int>>::
        iterator itm;

    void Master_Init1();
    void Master_Init2();
    void Master_Init3();
    void Master_State(Andy *m, Pipe *p, Brick *r);

    void Master_Move();

    Master(int a);
};

#endif // MASTER_H
