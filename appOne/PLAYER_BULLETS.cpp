#include"CONTAINER.h"
#include"GAME.h"
#include "PLAYER_BULLETS.h"
PLAYER_BULLETS::PLAYER_BULLETS(class GAME* game)
    : BULLETS(game) {
}
PLAYER_BULLETS::~PLAYER_BULLETS(){
}
void PLAYER_BULLETS::prepare(){
    Img = game()->container()->playerBulletImg;
    Num = 20;
    AdvSpeed = 10;
    AngSpeed = 0.05f;
    OfstLaunchDist = 100;
    AllocateMemory();
}
