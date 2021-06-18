#include"CONTAINER.h"
#include"GAME.h"
#include "ENEMY_BULLETS.h"
ENEMY_BULLETS::ENEMY_BULLETS(class GAME* game)
    : BULLETS(game) {
}
ENEMY_BULLETS::~ENEMY_BULLETS() {
}
void ENEMY_BULLETS::prepare() {
    Img = game()->container()->enemyBulletImg;
    Num = 120;
    AdvSpeed = 10;
    AngSpeed = 0.0f;
    OfstLaunchDist = 90;
    AllocateMemory();
}
