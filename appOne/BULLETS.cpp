#include"input.h"
#include"graphic.h"
#include "BULLETS.h"
BULLETS::BULLETS(class GAME* game)
    :CHARACTER(game){
}
BULLETS::~BULLETS() {
    if (Bullets) {
        delete[] Bullets;
        Bullets = 0;
    }
}
void BULLETS::AllocateMemory() {
    Bullets = new BULLET[Num];
}
void BULLETS::start() {
    for (int i = 0; i < Num; i++) {
        Bullets[i].hp = 0;
        Bullets[i].angle = 0;
    }
    CurNum = 0;
}
void BULLETS::launch(const FLOAT2& pos, const FLOAT2& vec) {
    if (CurNum < Num) {
        int i = CurNum;
        Bullets[i].hp = 1;
        Bullets[i].pos = pos + vec * OfstLaunchDist;
        Bullets[i].vec = vec;
        CurNum++;
    }
}
void BULLETS::move() {
    for (int i = CurNum - 1; i >= 0; i--) {
        Bullets[i].pos += Bullets[i].vec * AdvSpeed;
        Bullets[i].angle += AngSpeed;
        if (Bullets[i].pos.y < -20
            || Bullets[i].pos.y > height + 20
            || Bullets[i].pos.x < -20
            || Bullets[i].pos.x > width + 20
            ) {
            kill(i);
        }
    }

}
void BULLETS::isDrawn() {
    rectMode(CENTER);
    for (int i = 0; i < CurNum; i++) {
        imageColor(255);
        image(Img, Bullets[i].pos.x, Bullets[i].pos.y, Bullets[i].angle);
    }
}
int BULLETS::hp(int i) {
    return Bullets[i].hp;
}
FLOAT2 BULLETS::pos(int i) {
    return Bullets[i].pos;
}
int BULLETS::curNum() {
    return CurNum;
}
void BULLETS::kill(int i) {
    Bullets[i].hp = 0;
    CurNum--;
    Bullets[i] = Bullets[CurNum];
}