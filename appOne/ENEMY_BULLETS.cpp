#include "ENEMY_BULLETS.h"
void ENEMY_BULLETS::create(int img) {
    Img = img;
    AdvSpeed = 10;
    AngSpeed = 0.0f;
    Num = 120;
    Bullets = new BULLET[Num];
    OfstLaunchPos = 90;
}
