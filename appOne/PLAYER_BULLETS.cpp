#include "PLAYER_BULLETS.h"
PLAYER_BULLETS::PLAYER_BULLETS(){
}
PLAYER_BULLETS::~PLAYER_BULLETS(){
}
void PLAYER_BULLETS::create(int img){
    Img = img;
    Num = 20;
    AdvSpeed = 10;
    AngSpeed = 0.05f;
    OfstLaunchDist = 90;
    AllocateMemory();
}
