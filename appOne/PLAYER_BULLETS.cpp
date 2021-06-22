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
    SetTotalNum(20);
    AdvSpeed = 600;
    AngSpeed = 0.05f;
    OfstLaunchDist = 100;
    BCRadius = 30;
}
