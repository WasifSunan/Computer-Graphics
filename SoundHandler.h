#ifndef SOUNDHANDLER_H_INCLUDED
#define SOUNDHANDLER_H_INCLUDED


#include <mmsystem.h>
using namespace std;

class SoundHandler
{
  public:
    bool mute;

    SoundHandler();
    void heroShoot();
    void enemyShoot();
//    void heroGotHit();
//    void enemyDead();
};

SoundHandler::SoundHandler()
{
    mute = false;
}

void SoundHandler::heroShoot(){
    if(!mute)
        PlaySound("heroShoot.wav", NULL, SND_FILENAME | SND_ASYNC);
}

void SoundHandler::enemyShoot(){
    if(!mute)
        PlaySound("enemy.wav", NULL, SND_FILENAME | SND_ASYNC);
}

//void SoundHandler::heroGotHit(){
//    if(!mute)
//        PlaySound("heroGotHit.wav", NULL, SND_FILENAME | SND_ASYNC);
//}
//
//void SoundHandler::enemyDead(){
//    if(!mute)
//        PlaySound("enemyDead.wav", NULL, SND_FILENAME | SND_ASYNC);
//}

#endif // SOUNDHANDLER_H_INCLUDED
