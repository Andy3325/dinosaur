
#ifndef FLOWER_H
#define FLOWER_H

#include<QVector>
#include<QMap>

class Flower
{
public:
    QVector<int> v;
    QVector <QVector<int>> v2;
    QMap<int, QVector<QVector < int>>> m;
    Flower(int a);
    void Flower_Init2();
    void Flower_Init3();
};

#endif // FLOWER_H
