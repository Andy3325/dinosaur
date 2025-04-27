#include "level1.h"
#include "level2.h"
#include<musicplayer.h>
#include<QSoundEffect>
#include <QDebug>
#include <global.h>
#include<QPixmap>

level1::level1(QWidget *parent) : QWidget(parent) {
    setWindowTitle("game");
    setFixedSize(800, 600);

    musicPlayer->backMusicPlay(MainTheme);
    Game_Init();
    Pause_Init();
    QTimer::singleShot(1000, this, [=]() {
        timer1 = startTimer(15);
        timer3 = startTimer(50);
        game_start = true;
    });
    this->setFocusPolicy(Qt::StrongFocus);
}

void level1::Pause_Init() {
    Pause = new GamePause();
    MyPushButton *btn_continue = new MyPushButton(":/photo/continueGame.jpg");

    btn_continue->setParent(Pause);
    btn_continue->setFixedSize(150, 75);
    btn_continue->setIconSize(QSize(150, 75));
    btn_continue->move(30, 10);
    connect(btn_continue, &QPushButton::clicked, this, [=]() {
        btn_continue->zoom1();
        btn_continue->zoom2();
        QTimer::singleShot(500, this, [=]() {
            timer1 = startTimer(15);
            timer3 = startTimer(50);
            andy->walk_state = 0;
            key = "nullptr";
            Pause->close();
            update();
        });
    });

    MyPushButton *initGame = new MyPushButton(":/photo/initGame.png");
    initGame->setParent(Pause);
    initGame->setFixedSize(150, 75);
    initGame->setIconSize(QSize(150, 75));
    initGame->move(20, 90);
    connect(initGame, &QPushButton::clicked, this, [=]() {
        initGame->zoom1();
        initGame->zoom2();
        QTimer::singleShot(500, this, [=]() {
            Pause_Game_Init();
            Pause->close();
            QTimer::singleShot(500, this, [=]() {
                timer1 = startTimer(15);
                timer3 = startTimer(50);
                game_start = true;
            });
            update();
        });
    });

    MyPushButton *exit_btn = new MyPushButton(":/photo/exit.jpg");
    exit_btn->setParent(Pause);
    exit_btn->setFixedSize(150, 75);
    exit_btn->setIconSize(QSize(150, 75));
    exit_btn->move(20, 170);
    connect(exit_btn, &QPushButton::clicked, this, [=]() {
        exit_btn->zoom1();
        exit_btn->zoom2();
        QTimer::singleShot(500, this, [=]() {
            this->close();
        });
    });
}

void level1::timerEvent(QTimerEvent *event) {
    if (event->timerId() == timer1 && andy->is_die) {
        andy->Andy_die();
        if(open==false){
            stopAllBackMusic();
            musicPlayer->play(Death);
            open =true;
            QTimer::singleShot(2000, this, [=](){
                open =false;
            });
        }
        Die_Init();
        update();
        return;
    }
    if (event->timerId() == timer1) {
        andy->Andy_Move(key);
        andy->Jump_And_Down();
        Jump_Collision();
        Move_Collision();
        brick->ShatterState();
        mushroom->Move_state();
        master->Master_Move();
        Die_Init();
        Fall_Down(andy->y);
        fire->Fire_state();
        update();
    }

    if (event->timerId() == timer2) {
        andy->Andy_Move(key);
        Jump_Collision();
        Move_Collision();
    }

    if (event->timerId() == timer3) {
        time -= 0.05;
        if(time<=0.0){
            stopAllMusic();
            stopAllBackMusic();
            musicPlayer->play(OutOfTime);
            Game_Over();
            update();
            return;
        };
        Jump_Collision();
        Move_Collision();
        master->Master_Move();
        unknown->Unknown_State();
        unknown->Crash_state();
    }
}

void level1::keyPressEvent(QKeyEvent *event) {
    if (!andy->is_die) {
        switch (event->key()) {
        case Qt::Key_Right:
            andy->direction = key = "right";
            break;
        case Qt::Key_Left:
            andy->direction = key = "left";
            break;
        case Qt::Key_Z:
            timer2 = startTimer(25);
            is_kill_timer2 = false;
            break;
        case Qt::Key_Space:
            andy->is_jump = true;
            break;
        case Qt::Key_B:
            if (game_start) {
                killTimer(timer1);
                if (is_kill_timer2) {
                    killTimer(timer2);
                }
                killTimer(timer3);
                Pause->setParent(this);
                Pause->open();
            }
            break;
        case Qt::Key_C:
            if (andy->life < 8) {
                andy->life++;
            }
        case Qt::Key_X:
            if (!is_press_x && !andy->is_jump && andy->is_jump_end && andy->colour == 3) {
                is_press_x = true;
                fire->Fire_xy();
            }
            break;
        case Qt::Key_W:
            is_press_x = true;
            fire->Fire_xy();
        }
    }
}

void level1::keyReleaseEvent(QKeyEvent *event) {
    if (!andy->is_die) {
        switch (event->key()) {
        case Qt::Key_Right:
            andy->walk_state = 0;
            key = "nullptr";
            break;
        case Qt::Key_Left:
            andy->walk_state = 0;
            key = "nullptr";
            break;
        case Qt::Key_Z:
            is_kill_timer2 = true;
            killTimer(timer2);
            break;
        case Qt::Key_Space:
            andy->is_jump = false;
            andy->is_space_release = true;
            break;
        case Qt::Key_X:
            is_press_x = false;
            break;
        }
    }
}

void level1::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if((andy->life<=0)||(time<=0.0)){
        painter.drawPixmap(0, 0, 800, 550, QPixmap(":/photo/gameover.png"));
        return;
    }
    if (!game_start) {
        painter.drawPixmap(0, 0, 800, 550, QPixmap(":/photo/blackground2.png"));
        painter.drawPixmap(300, 250, 40, 40, QPixmap(":/photo/life.png"));
        painter.setPen(QColor(255, 255, 255));
        QFont font;
        font.setPointSize(35);
        painter.setFont(font);
        painter.drawText(360, 280, "x");
        painter.drawText(80, 38, "times:");
        painter.drawText(220, 38, QString::number(time, 'f', 1));
        painter.drawText(600, 38, "coin:");
        painter.drawText(720, 38, QString::number(unknown->coin));
        font.setPointSize(45);
        painter.setFont(font);
        painter.drawText(400, 287, QString::number(andy->life));
        return;
    }
    painter.drawPixmap(0, 0, 800, 550, QPixmap(":/photo/sky.png"));
    painter.drawPixmap(230, 10, QPixmap(":/photo/coin.png"), 0, 0, 30, 30);
    painter.drawPixmap(380, 10, 30, 30, QPixmap(":/photo/score.png"));
    painter.setFont(QFont("Times", 45, QFont::Bold));
    painter.drawText(280, 48, QString::number(unknown->coin));
    painter.drawText(430, 48, QString::number(score));
    for (int i = 1; i <= andy->life; i++) {
        painter.drawPixmap(800 - i * 35, 10, 30, 30, QPixmap(":/photo/life.png"));
    }
    painter.drawPixmap(10, 12, 30, 30, QPixmap(":/photo/time.png"));
    painter.drawText(50, 48, QString::number(time, 'f', 1));
    painter.drawPixmap(0, 500, QPixmap(":/photo/ground.png"), andy->ground_state, 0, 800, 45);

    if (andy->x > 7800) {
        QVector < QVector < int >> ::iterator
            it = castle->m.begin()->begin();
        painter.drawPixmap(*it->begin() - andy->x-20, *(it->begin() + 1), 220, 220, QPixmap(":/photo/castle.png"));
    }
    if (mushroom->mushroom_state != 0) {
        painter.drawPixmap(mushroom->mushroom_x - andy->x, mushroom->mushroom_y, 40, 40,
                           QPixmap(":/photo/mushroom" + QString::number(andy->colour) + ".png"));
    }
    for (QVector < QVector < int >> ::iterator it = brick->m.begin()->begin(); it != brick->m.begin()->end();
         it++)
    {
        if (*(it->begin()) - andy->x > -50 && *(it->begin()) - andy->x < 800 && *(it->begin() + 2) == 1) {
            painter.drawPixmap(*(it->begin()) - andy->x, *(it->begin() + 1), 50, 40, QPixmap(":/photo/brick1.png"));
        }
    }
    for (QVector < QVector < int >> ::iterator it = unknown->m.begin()->begin(); it != unknown->m.begin()->end();
         it++)
    {
        if (*(it->begin()) - andy->x > -50 && *(it->begin()) - andy->x < 800 && *(it->begin() + 2) != 0) {
            painter.drawPixmap(*(it->begin()) - andy->x, *(it->begin() + 1), QPixmap(":/photo/unknown.png"),
                               unknown->unknown_state, 0, 50, 40);
        } else if (*(it->begin()) - andy->x > -50 && *(it->begin()) - andy->x < 800 && *(it->begin() + 2) == 0) {
            painter.drawPixmap(*(it->begin()) - andy->x, *(it->begin() + 1), 50, 40,
                               QPixmap(":/photo/unknown_after.png"));
        }
    }
    if (unknown->coin_state > 0) {
        painter.drawPixmap(unknown->coin_x - andy->x, unknown->coin_y, QPixmap(":/photo/coin.png"), unknown->coin_state,
                           0, 30, 33);
    }
    for (QVector < QVector < int >> ::iterator it = pipe->long_m.begin()->begin(); it != pipe->long_m.begin()->end();
         it++)
    {
        if (*(it->begin()) - andy->x > -80 && *(it->begin()) - andy->x < 800) {
            painter.drawPixmap(*(it->begin()) - andy->x, *(it->begin() + 1), 80, 100, QPixmap(":/photo/pipe_long.png"));
        }
    }
    for (QVector < QVector < int >> ::iterator it = pipe->short_m.begin()->begin(); it != pipe->short_m.begin()->end();
         it++)
    {
        if (*(it->begin()) - andy->x > -80 && *(it->begin()) - andy->x < 800) {
            painter.drawPixmap(*(it->begin()) - andy->x, *(it->begin() + 1), 80, 50, QPixmap(":/photo/pipe_short.png"));
        }
    }
    if (brick->shatter_state > 0) {
        painter.drawPixmap(brick->left_shatter_x - andy->x, brick->left_shatter_y - 20, 30, 30,
                           QPixmap(":/photo/brick2.png"));
        painter.drawPixmap(brick->left_shatter_x - andy->x, brick->left_shatter_y + 50, 30, 30,
                           QPixmap(":/photo/brick2.png"));
        painter.drawPixmap(brick->right_shatter_x - andy->x, brick->right_shatter_y - 20, 30, 30,
                           QPixmap(":/photo/brick3.png"));
        painter.drawPixmap(brick->right_shatter_x - andy->x, brick->right_shatter_y + 50, 30, 30,
                           QPixmap(":/photo/brick3.png"));
    }
    for (QVector < QVector < int >> ::iterator it = master->m.begin()->begin(); it != master->m.begin()->end();
         it++)
    {
        if (*(it->begin()) - andy->x > -80 && *(it->begin()) - andy->x < 800 && *(it->begin() + 2) != 0) {
            painter.drawPixmap(*(it->begin()) - andy->x, *(it->begin() + 1), 40, 40,
                               QPixmap(":/photo/master_" + QString::number(*(it->begin() + 3)) + ".png"));
        } else if (*(it->begin()) - andy->x > -80 && *(it->begin()) - andy->x < 800 && *(it->begin() + 2) == 0 &&
                   *(it->begin() + 4) == 1) {
            painter.drawPixmap(*(it->begin()) - andy->x, *(it->begin() + 1) + 20, 40, 20,
                               QPixmap(":/photo/master_" + QString::number(*(it->begin() + 3)) + ".png"));
        }
    }
    if (andy->is_die) {
        painter.drawPixmap(andy->map_x, andy->y, QPixmap(":/photo/andy_die.png"), andy->die_pix_state, 0, 50, 50);
    }
    if (!andy->is_die && andy->invincible_state % 2 == 0 && !is_win) {
        painter.drawPixmap(andy->map_x, andy->y,
                           QPixmap(":/photo/walk_" + andy->direction + QString::number(andy->colour) + ".png"),
                           andy->walk_state, 0, 45, 45);
    }
    if (fire->is_have) {
        painter.drawPixmap(fire->x - andy->x, fire->y, 20, 20, QPixmap(":/photo/fire.png"));
    }
    if (fire->is_have1) {
        painter.drawPixmap(fire->x1 - andy->x, fire->y1, 20, 20, QPixmap(":/photo/fire.png"));
    }
    if (fire->is_have2) {
        painter.drawPixmap(fire->x2 - andy->x, fire->y2, 20, 20, QPixmap(":/photo/fire.png"));
    }
}

void level1::Game_Init() {
    andy = new Andy;
    brick = new Brick(1);
    pipe = new class Pipe(1);
    unknown = new Unknown(1);
    mushroom = new MushRoom(1);
    master = new Master(1);
    fire = new Fire;
    castle = new Castle;
    key = "nullptr";
    is_press_x = false;
    is_win = false;
    score = 0;
    time = 300.0;
    is_kill_timer2 = true;
    game_start = false;
    open =false;
    master->Master_State(andy, pipe, brick);
    fire->Fire_Move(andy, pipe, brick, master);
}

void level1::Pause_Game_Init() {
    key = "nullptr";
    score = 0;
    time = 300.0;
    is_press_x = false;
    is_kill_timer2 = true;
    game_start = false;
    open =false;
    andy->Andy_Init();
    unknown->Unknown_Init1();
    brick->BrickInit1();
    mushroom->MushRoom_Init1();
    master->Master_Init1();
    master->Master_State(andy, pipe, brick);
}

void level1::Jump_Collision() {
    if (andy->height - andy->distance <= 0) {
        return;
    }
    if(andy->is_jump_end){
        return;
    }
    for (QVector < QVector < int >> ::iterator it = brick->m.begin()->begin(); it != brick->m.begin()->end();
         it++)
    {
        if (*it->begin() - andy->x - 300 >= -30 && *it->begin() - andy->x - 300 <= 30 &&
            *(it->begin() + 1) - andy->y + 40 >= -10 && *(it->begin() + 1) - andy->y + 40 <= 20 &&
            *(it->begin() + 2) == 1) {
            score += 5;
            brick->BrickShatter(it);
            *(it->begin() + 2) = 0;
            andy->y = *(it->begin() + 1) + 40;
            andy->height = andy->distance;
            return;
        }
    }
    for (QVector < QVector < int >> ::iterator it = unknown->m.begin()->begin(); it != unknown->m.begin()->end();
         it++)
    {
        if (*it->begin() - andy->x - 300 >= -30 && *it->begin() - andy->x - 300 <= 30 &&
            *(it->begin() + 1) - andy->y + 40 >= -10 && *(it->begin() + 1) - andy->y + 40 <= 20) {
            if (*(it->begin() + 2) == 1) {
                unknown->coin++;
                score += 10;
                unknown->Unknown_crash(it);
            } else if (*(it->begin() + 2) == 2) {
                mushroom->MushRoom_Move(it, unknown, brick, andy);
            }
            andy->y = *(it->begin() + 1) + 40;
            *(it->begin() + 2) = 0;
            andy->height = andy->distance;
            return;
        }
    }
}

void level1::Move_Collision() {

    for (QVector < QVector < int >> ::iterator it = brick->m.begin()->begin(); it != brick->m.begin()->end();
         it++)
    {
        if (*it->begin() - andy->x - 300 >= 35 && *it->begin() - andy->x - 300 <= 40 &&
            *(it->begin() + 1) > andy->y - 35 && *(it->begin() + 1) < andy->y + 35 && andy->direction == "right" &&
            *(it->begin() + 2) == 1) {
            andy->can_move = false;
            return;
        } else if (*it->begin() - andy->x - 300 >= -40 && *it->begin() - andy->x - 300 <= -35 &&
                   *(it->begin() + 1) > andy->y - 35 && *(it->begin() + 1) < andy->y + 35 &&
                   andy->direction == "left" && *(it->begin() + 2) == 1) {
            andy->can_move = false;
            return;
        }
    }
    for (QVector < QVector < int >> ::iterator it = unknown->m.begin()->begin(); it != unknown->m.begin()->end();
         it++)
    {
        if (*it->begin() - andy->x - 300 >= 35 && *it->begin() - andy->x - 300 <= 40 &&
            *(it->begin() + 1) > andy->y - 35 && *(it->begin() + 1) < andy->y + 35 && andy->direction == "right") {
            andy->can_move = false;
            return;
        } else if (*it->begin() - andy->x - 300 >= -40 && *it->begin() - andy->x - 300 <= -35 &&
                   *(it->begin() + 1) > andy->y - 35 && *(it->begin() + 1) < andy->y + 35 &&
                   andy->direction == "left") {
            andy->can_move = false;
            return;
        }
    }
    for (QVector < QVector < int >> ::iterator it = pipe->long_m.begin()->begin(); it != pipe->long_m.begin()->end();
         it++)
    {
        if (*it->begin() - andy->x - 300 >= 30 && *it->begin() - andy->x - 300 <= 35 &&
            *(it->begin() + 1) < andy->y + 45 && andy->direction == "right") {
            andy->can_move = false;
            return;
        } else if (*it->begin() - andy->x - 300 >= -55 && *it->begin() - andy->x - 300 <= -50 &&
                   *(it->begin() + 1) < andy->y + 45 && andy->direction == "left") {
            andy->can_move = false;
            return;
        }
    }
    for (QVector < QVector < int >> ::iterator it = pipe->short_m.begin()->begin(); it != pipe->short_m.begin()->end();
         it++)
    {
        if (*it->begin() - andy->x - 300 >= 30 && *it->begin() - andy->x - 300 <= 35 &&
            *(it->begin() + 1) < andy->y + 45 && andy->direction == "right") {
            andy->can_move = false;
            return;
        } else if (*it->begin() - andy->x - 300 >= -55 && *it->begin() - andy->x - 300 <= -50 &&
                   *(it->begin() + 1) < andy->y + 45 && andy->direction == "left") {
            andy->can_move = false;
            return;
        }
    }
    QVector < QVector < int >> ::iterator
        it = castle->m.begin()->begin();
    if (*it->begin() - andy->x - 300 >= -60 && *it->begin() - andy->x - 300 <= -20 &&
        *(it->begin() + 1) < andy->y - 100 && *(it->begin() + 1) > andy->y - 200) {

        is_win = true;
        is_win= level1_Win(is_win);
    }
    andy->can_move = true;
}

void level1::Fall_Down(int &y) {
    qDebug() << andy->distance;
    if (andy->height - andy->distance < 0) {
        if (y > 455) {
            y = 455;
            andy->is_jump_end = true;
            andy->distance = 0;
            andy->height = 18;
            return;
        }
        for (QVector < QVector < int >> ::iterator it = brick->m.begin()->begin(); it != brick->m.begin()->end();
             it++)
        {
            if (*it->begin() - andy->x - 300 >= -30 && *it->begin() - andy->x - 300 <= 30 &&
                *(it->begin() + 1) <= y + 50 && *(it->begin() + 1) >= y + 25 && *(it->begin() + 2) == 1) {
                y = *(it->begin() + 1) - 45;
                andy->is_jump_end = true;
                andy->height = andy->distance = 18;
                return;
            }
        }
        for (QVector < QVector < int >> ::iterator it = unknown->m.begin()->begin(); it != unknown->m.begin()->end();
             it++)
        {
            if (*it->begin() - andy->x - 300 >= -30 && *it->begin() - andy->x - 300 <= 30 &&
                *(it->begin() + 1) <= y + 50 && *(it->begin() + 1) >= y + 25) {
                y = *(it->begin() + 1) - 45;
                andy->is_jump_end = true;
                andy->height = andy->distance = 18;
                return;
            }
        }
        for (QVector < QVector < int >> ::iterator it = pipe->long_m.begin()->begin(); it !=
                                                                                 pipe->long_m.begin()->end();
             it++)
        {
            if (*it->begin() - andy->x - 300 >= -50 && *it->begin() - andy->x - 300 <= 30 &&
                *(it->begin() + 1) <= y + 50 && *(it->begin() + 1) >= y + 25) {
                y = *(it->begin() + 1) - 45;
                andy->is_jump_end = true;
                andy->height = andy->distance = 18;
                return;
            }
        }
        for (QVector < QVector < int >> ::iterator it = pipe->short_m.begin()->begin(); it !=
                                                                                  pipe->short_m.begin()->end();
             it++)
        {
            if (*it->begin() - andy->x - 300 >= -50 && *it->begin() - andy->x - 300 <= 30 &&
                *(it->begin() + 1) <= y + 50 && *(it->begin() + 1) >= y + 25) {
                y = *(it->begin() + 1) - 45;
                andy->is_jump_end = true;
                andy->height = andy->distance = 18;
                return;
            }
        }
    }
}

void level1::Die_Init() {
    if (andy->is_die && key != "null") {
        andy->walk_state = 0;
        key = "null";
    }
    if (andy->invincible_state == 100) {
        andy->is_invincible = false;
        andy->invincible_state = 0;
    }
    if (andy->is_invincible) {
        andy->invincible_state += 1;
    }
    if (andy->y > 500) {
        andy->y = 455;
        andy->life--;
        if(andy->life<=0){
            Game_Over();
            return;
        };
        killTimer(timer3);
        killTimer(timer1);
        game_start = false;
        QTimer::singleShot(2000, this, [=]() {
            andy->is_die = false;
            andy->is_invincible = true;
            timer1 = startTimer(20);
            timer3 = startTimer(50);
            game_start = true;
            andy->die_state = 0;
            andy->die_pix_state = -50;
            musicPlayer->backMusicPlay(MainTheme);
        });
    }
}

bool level1::level1_Win(bool is_win) {
    killTimer(timer1);
    killTimer(timer3);
    killTimer(timer2);
    if(is_win){
    QTimer::singleShot(1000, this, [=]() {
        game_start = false;
        time = 300.0;
        update();
    });
    level2 *Level2 = new level2;
    this->hide();
    Level2->show();
    connect(Level2,&level2::back,this,[=](){
        this->close();
        emit  this->back();
    });
    return false;
    }
    return false;
}

void level1::Game_Over(){
    killTimer(timer1);
    killTimer(timer3);
    killTimer(timer2);
    QTimer::singleShot(1000, this, [=]() {
        game_start = false;
        time = 300.0;
        QTimer::singleShot(1500, this, [=]() {
            this->close();
            emit  this->back();
        });
    });
}

