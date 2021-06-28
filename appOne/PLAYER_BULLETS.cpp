#include"CONTAINER.h"
#include"GAME.h"
#include "PLAYER_BULLETS.h"
PLAYER_BULLETS::PLAYER_BULLETS(class GAME* game)
    : BULLETS(game) {
}
PLAYER_BULLETS::~PLAYER_BULLETS(){
}
void PLAYER_BULLETS::create(){
    Img = game()->container()->playerBulletImg;
    Bullet.advSpeed = 600;
    Bullet.angSpeed = 0.05f;
    Bullet.ofstLaunchDist = 100;
    Bullet.bcRadius = 30;
    Bullet.totalNum=20;
    AllocateBullets(Bullet.totalNum);
}
