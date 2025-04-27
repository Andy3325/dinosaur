#ifndef GLOBAL_CPP
#define GLOBAL_CPP
#include "global.h"
#include <QDebug>

QString LEVEL_NAME = "";
QVector<QSoundEffect*>playerList;
QVector<QSoundEffect*>backplayerList;
MusicPlayer *musicPlayer = new MusicPlayer;

//音效区
QString course_clear = ":/music/course_clear.wav";
QString Death = ":/music/death.wav";
QString FlagPoleMusic = ":/music/flagpole.wav";
QString GameOver = ":/music/game_over.wav";
QString Invincible = ":/music/invincible.wav";
QString MainTheme = ":/music/main_theme.wav";
QString MainTheme_spedup = ":/music/main_theme_sped_up.wav";
QString OutOfTime = ":/music/out_of_time.wav";
QString StageClear = ":/music/stage_clear.wav";
QString Start = ":/music/start.wav";
QString World_clear = ":/music/world_clear.wav";
QString Begin = ":/sound/begin.wav";
QString BigJump = ":/sound/big_jump.wav";
QString BrickSmash = ":/sound/brick_smash.wav";
QString Bump = ":/sound/bump.wav";
QString CoinMusic = ":/sound/coin.wav";
QString count_down = ":/sound/count_down.wav";
QString FireBall = ":/sound/fireball.wav";
QString Kick = ":/sound/kick.wav";
QString MainTheme_sped_up_instance = ":/sound/main_theme_sped_up - instance.wav";
QString MainTheme_sped_up = ":/sound/main_theme_sped_up - instance.wav";
QString OneUp = ":/sound/one_up.wav";
QString Pipe = ":/sound/pipe.wav";
QString PowerUp = ":/sound/powerup.wav";
QString PowerUpAppers = ":/sound/powerup_appears.wav";
QString SmallJump = ":/sound/small_jump.wav";
QString Stomp = ":/sound/stomp.wav";

void stopAllMusic()
{
    for(int i=0;i<playerList.size();i++)
    {
        QSoundEffect *m = playerList[i];
        m->stop();
        playerList.remove(i);
    }
}

void stopAllBackMusic()
{
    for(int i=0;i<backplayerList.size();i++)
    {
        QSoundEffect *m = backplayerList[i];
        m->stop();
        backplayerList.remove(i);
    }
}
#endif // GLOBAL_CPP
