#ifndef DIAMOND_H
#define DIAMOND_H

#include<QVector>
#include<QMap>

class Diamond
{
public:
    QVector<int> v;
    QVector <QVector<int>> v2;
    QMap<int, QVector<QVector < int>>> m;
    Diamond(int a);
    void Diamond_Init2();
    void Diamond_Init3();
};

#endif // DIAMOND_H
