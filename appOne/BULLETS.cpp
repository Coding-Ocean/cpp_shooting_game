#include"input.h"
#include"graphic.h"
#include "BULLETS.h"
BULLETS::BULLETS() {
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
void BULLETS::init(class GAME* game) {
    for (int i = 0; i < Num; i++) {
        Bullets[i].hp = 0;
        Bullets[i].angle = 0;
    }
}
void BULLETS::launch(const FLOAT2& pos, const FLOAT2& vec) {
    for (int i = 0; i < Num; i++) {
        if (Bullets[i].hp == 0) {
            Bullets[i].hp = 1;
            Bullets[i].pos = pos + vec * OfstLaunchDist;
            Bullets[i].vec = vec;
            i = Num;
        }
    }
}
void BULLETS::move() {
    for (int i = 0; i < Num; i++) {
        if (Bullets[i].hp > 0) {
            Bullets[i].pos += Bullets[i].vec * AdvSpeed;
            Bullets[i].angle += AngSpeed;
            if (Bullets[i].pos.y < -20
                || Bullets[i].pos.y > height + 20
                || Bullets[i].pos.x < -20
                || Bullets[i].pos.x > width + 20
                ) {
                Bullets[i].hp = 0;
            }
        }
    }
}
void BULLETS::draw() {
    rectMode(CENTER);
    for (int i = 0; i < Num; i++) {
        if (Bullets[i].hp > 0) {
            imageColor(255);
            image(Img, Bullets[i].pos.x, Bullets[i].pos.y, Bullets[i].angle);
        }
    }
}
int BULLETS::hp(int i) {
    return Bullets[i].hp;
}
FLOAT2 BULLETS::pos(int i) {
    return Bullets[i].pos;
}
int BULLETS::num() {
    return Num;
}
void BULLETS::kill(int i) {
    Bullets[i].hp = 0;
}
    //Bullets[i] = Bullets[CurNum - 1];