
#ifndef SETTING_H
#define SETTING_H

#include <QMainWindow>
#include <QWidget>
#include<QPainter>

class Gameset : public QWidget {
    Q_OBJECT
public:
    explicit Gameset(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
signals:
    void back();
};

#endif // SETTING_H
