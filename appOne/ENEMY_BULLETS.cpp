#include"CONTAINER.h"
#include"GAME.h"
#include "ENEMY_BULLETS.h"
ENEMY_BULLETS::ENEMY_BULLETS(class GAME* game)
    : BULLETS(game) {
}
ENEMY_BULLETS::~ENEMY_BULLETS() {
}
void ENEMY_BULLETS::create() {
    Img = game()->container()->enemyBulletImg;
    Bullet.advSpeed = 600;
    Bullet.angSpeed = 0.0f;
    Bullet.ofstLaunchDist = 90;
    Bullet.bcRadius = 30;
    Bullet.totalNum = 20;
    AllocateBullets(Bullet.totalNum);
}
