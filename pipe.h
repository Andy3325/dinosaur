
#ifndef PIPE_H
#define PIPE_H

#include<QMap>
#include<QVector>

class Pipe {
public:
    QVector<int> v;
    QVector <QVector<int>> v2;
    QMap<int, QVector<QVector < int>>> short_m;
    QMap<int, QVector<QVector < int>>> long_m;

    void Pipe_Init1();
    void Pipe_Init2();
    void Pipe_Init3();
    Pipe(int a);
};

#endif // PIPE_H
