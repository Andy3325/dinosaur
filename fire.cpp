#include "fire.h"
#include"musicplayer.h"
#include<QDebug>
extern MusicPlayer *musicPlayer;
extern QString FireBall ;
Fire::Fire() {
    Fire_Init();
}

void Fire::Fire_Init() {
    x = x1 = x2 = y = y2 = y2 = 0;
    direction = direction1 = direction2 = 1;
    is_have = is_have1 = is_have2 = false;
}

void Fire::Fire_Move(Andy *m, Pipe *p, Brick *r, Master *ms) {
    andy = m;
    pipe = p;
    brick = r;
    master = ms;
}

void Fire::Fire_xy() {
    musicPlayer->play(FireBall);
    if (!is_have) {
        if (andy->direction == "right") {
            x = andy->x + 350;
            direction = 1;
        } else {
            direction = 0;
            x = andy->x + 290;
        }
        is_have = true;
        y = andy->y + 15;
        if (andy->x <= 300) {
            x -= 300 - andy->x;
        }
    } else if (is_have && !is_have1) {
        if (andy->direction == "right") {
            x1 = andy->x + 350;
            direction1 = 1;
        } else {
            direction1 = 0;
            x1 = andy->x + 290;
        }
        is_have1 = true;
        y1 = andy->y + 15;
        if (andy->x <= 300) {
            x1 -= 300 - andy->x;
        }
    } else if (is_have && is_have1 && !is_have2) {
        if (andy->direction == "right") {
            x2 = andy->x + 350;
            direction2 = 1;
        } else {
            direction2 = 0;
            x2 = andy->x + 290;
        }
        is_have2 = true;
        y2 = andy->y + 15;
        if (andy->x <= 300) {
            x2 -= 300 - andy->x;
        }
    } else if (is_have && is_have1 && is_have2) {
        if (x > x1 && x > x2) {
            if (andy->direction == "right") {
                x = andy->x + 350;
                direction = 1;
            } else {
                direction = 0;
                x = andy->x + 290;
            }
            is_have = true;
            y = andy->y + 15;
            if (andy->x <= 300) {
                x -= 300 - andy->x;
            }
        } else if (x1 > x && x1 > x2) {
            if (andy->direction == "right") {
                x1 = andy->x + 350;
                direction1 = 1;
            } else {
                direction1 = 0;
                x1 = andy->x + 290;
            }
            is_have1 = true;
            y1 = andy->y + 15;
            if (andy->x <= 300) {
                x1 -= 300 - andy->x;
            }
        } else if (x2 > x && x2 > x1) {
            if (andy->direction == "right") {
                x2 = andy->x + 350;
                direction2 = 1;
            } else {
                direction2 = 0;
                x2 = andy->x + 290;
            }
            is_have2 = true;
            y2 = andy->y + 15;
            if (andy->x <= 300) {
                x2 -= 300 - andy->x;
            }
        }
    }
}

void Fire::Fire_state() {
    if (is_have && direction) {
        x += 10;
    } else if (is_have && !direction) {
        x -= 10;
    }
    if (is_have1 && direction1) {
        x1 += 10;
    } else if (is_have1 && !direction1) {
        x1 -= 10;
    }
    if (is_have2 && direction2) {
        x2 += 10;
    } else if (is_have2 && !direction2) {
        x2 -= 10;
    }
    for (QVector < QVector < int >> ::iterator it = master->m.begin()->begin(); it != master->m.begin()->end();
         it++)
    {
        if (x > *it->begin() && x <= *it->begin() + 30 && *(it->begin() + 2) == 1 && y >= *(it->begin() + 1) &&
            y <= *(it->begin() + 1) + 40) {
            is_have = false;
            *(it->begin() + 2) = 0;
            x = 0;
            return;
        }
        if (x1 > *it->begin() && x1 <= *it->begin() + 30 && *(it->begin() + 2) == 1 && y >= *(it->begin() + 1) &&
            y <= *(it->begin() + 1) + 40) {
            is_have1 = false;
            *(it->begin() + 2) = 0;
            x1 = 0;
            return;
        }
        if (x2 > *it->begin() && x2 <= *it->begin() + 30 && *(it->begin() + 2) == 1 && y >= *(it->begin() + 1) &&
            y <= *(it->begin() + 1) + 40) {
            is_have2 = false;
            *(it->begin() + 2) = 0;
            x2 = 0;
            return;
        }
    }
    for (QVector < QVector < int >> ::iterator it = brick->m.begin()->begin(); it != brick->m.begin()->end();
         it++)
    {
        if (x > *it->begin() + 10 && x <= *it->begin() + 30 && y > *(it->begin() + 1) && y < *(it->begin() + 1) + 40) {
            is_have = false;
            x = 0;
            return;
        }
        if (x1 > *it->begin() + 10 && x1 <= *it->begin() + 30 && y > *(it->begin() + 1) &&
            y < *(it->begin() + 1) + 40) {
            is_have1 = false;
            x1 = 0;
            return;
        }
        if (x2 > *it->begin() + 10 && x2 <= *it->begin() + 30 && y > *(it->begin() + 1) &&
            y < *(it->begin() + 1) + 40) {
            is_have2 = false;
            x2 = 0;
            return;
        }
    }

    for (QVector < QVector < int >> ::iterator it = pipe->long_m.begin()->begin(); it != pipe->long_m.begin()->end();
         it++)
    {
        if (x > *it->begin() + 10 && x <= *it->begin() + 30 && y > *(it->begin() + 1) &&
            y <= *(it->begin() + 1) + 100) {
            is_have = false;
            x = 0;
            return;
        }
        if (x1 > *it->begin() + 10 && x1 <= *it->begin() + 30 && y > *(it->begin() + 1) &&
            y <= *(it->begin() + 1) + 100) {
            is_have1 = false;
            x1 = 0;
            return;
        }
        if (x2 > *it->begin() + 10 && x2 <= *it->begin() + 30 && y > *(it->begin() + 1) &&
            y <= *(it->begin() + 1) + 100) {
            is_have2 = false;
            x2 = 0;
            return;
        }
    }
    for (QVector < QVector < int >> ::iterator it = pipe->short_m.begin()->begin(); it != pipe->short_m.begin()->end();
         it++)
    {
        if (x > *it->begin() + 10 && x <= *it->begin() + 30 && y > *(it->begin() + 1) && y <= *(it->begin() + 1) + 50) {
            is_have = false;
            x = 0;
            return;
        }
        if (x1 > *it->begin() + 10 && x1 <= *it->begin() + 30 && y > *(it->begin() + 1) &&
            y <= *(it->begin() + 1) + 50) {
            is_have1 = false;
            x1 = 0;
            return;
        }
        if (x2 > *it->begin() + 10 && x2 <= *it->begin() + 30 && y > *(it->begin() + 1) &&
            y <= *(it->begin() + 1) + 50) {
            is_have2 = false;
            x2 = 0;
            return;
        }
    }
}

