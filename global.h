
#ifndef GLOBAL_H
#define GLOBAL_H

#include <QString>
#include <QVector>
#include <QPixmap>
#include <musicplayer.h>
#include <QSoundEffect>

extern int LIVES;
extern QVector<QSoundEffect*>playerList;
extern QVector<QSoundEffect*>backplayerList;
extern MusicPlayer *musicPlayer;
extern void stopAllMusic();
extern void stopAllBackMusic();
extern QString FlagPoleMusic;
extern QString GameOver;
extern QString CoinMusic;
extern QString course_clear ;
extern QString Death;
extern QString FlagPoleMusic ;
extern QString GameOver ;
extern QString Invincible;
extern QString MainTheme ;
extern QString MainTheme_spedup ;
extern QString OutOfTime ;
extern QString StageClear ;
extern QString Start ;
extern QString World_clear ;
extern QString Begin ;
extern QString BigJump ;
extern QString BrickSmash ;
extern QString Bump ;
extern QString CoinMusic ;
extern QString count_down ;
extern QString FireBall ;
extern QString Kick ;
extern QString MainTheme_sped_up_instance ;
extern QString MainTheme_sped_up ;
extern QString OneUp;
extern QString Pipe ;
extern QString PowerUp;
extern QString PowerUpAppers ;
extern QString SmallJump ;
extern QString Stomp ;

#endif // GLOBAL_H
