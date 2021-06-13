#include "ENEMY_BULLETS.h"
void ENEMY_BULLETS::create(int img) {
    Num = 120;
    Img = img;
    AdvSpeed = 10;
    AngSpeed = 0.0f;
    OfstLaunchDist = 90;
    AllocateMemory();
}
