
#ifndef ANDY_H
#define ANDY_H
#include<QPixmap>
#include<QString>

class Andy {
public:
    Andy();

    int x;
    int map_x;
    int y;
    int colour;
    int life;
    int walk_state;
    int ground_state;
    int height;
    int distance;
    int die_state;
    int die_pix_state;
    int invincible_state;
    bool can_move;
    bool is_invincible;
    bool is_big;
    bool is_die;
    bool is_jump;
    bool is_jump_end;
    bool is_space_release;
    QString direction;
    void Andy_Init();
    void Move_state();
    void Andy_Move(const QString &direction);
    void Jump_And_Down();
    void Andy_die();
private:


};

#endif // ANDY_H
