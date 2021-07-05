#include"CONTAINER.h"
#include"GAME.h"
#include "PLAYER_BULLETS.h"
PLAYER_BULLETS::PLAYER_BULLETS(class GAME* game)
    : BULLETS(game) {
}
void PLAYER_BULLETS::create(){
    SetBulletData(game()->container()->playerBullet());
}
