
#ifndef WEED_H
#define WEED_H

#include<QMap>
#include<QVector>
#include<andy.h>

class Spikeweed {
public:
    Andy *andy;
    QVector <QVector<int>> v1;
    QMap<int, QVector<QVector < int>>> m;
    QVector<QVector < int>>::iterator itm;
    void Spikeweed_Init3();
    void Spikeweed_State(Andy *m);
    void Spikeweed_collision();
    Spikeweed(int a);
};

#endif // WEED_H
