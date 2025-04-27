
#ifndef BRICK_H
#define BRICK_H

#include<QMap>
#include<QVector>

class Brick {
public:
    QVector<int> v;
    QVector <QVector<int>> v2;
    QMap<int, QVector<QVector < int>>> m;
    int left_shatter_x;
    int left_shatter_y;
    int right_shatter_x;
    int right_shatter_y;
    int shatter_state;
    Brick(int a);
    void BrickInit1();
    void BrickInit2();
    void BrickInit3();
    void ShatterState();
    void BrickShatter(QVector<QVector <int>>::iterator it
                      );
};

#endif // BRICK_H
