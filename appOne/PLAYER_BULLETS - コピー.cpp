#include"input.h"
#include"graphic.h"

#include "PLAYER_BULLETS.h"
PLAYER_BULLETS::PLAYER_BULLETS(){
}
PLAYER_BULLETS::~PLAYER_BULLETS(){
    if (Bullets) {
        delete[] Bullets;
        Bullets = 0;
    }
}
void PLAYER_BULLETS::create(int img){
    Img = img;
    AdvSpeed = 10;
    AngSpeed = 0.05f;
    Num = 20;
    Bullets = new BULLET[Num];
    TriggerInterval = 10;
}
void PLAYER_BULLETS::init(class GAME* game) {
    TriggerCnt = -10;
    for (int i = 0; i < Num; i++) {
        Bullets[i].hp = 0;
        Bullets[i].angle = 0;
    }
}
int PLAYER_BULLETS::trigger() {
    int flag = 0;
    if (isPress(KEY_SPACE)) {
        if (TriggerCnt % TriggerInterval == 0) {
            flag = 1;
        }
        TriggerCnt++;
    }
    else {
        TriggerCnt = 0;
    }
    return flag;
}
void PLAYER_BULLETS::launch(float px, float py, float vx, float vy) {
    if (trigger()) {
        for (int i = 0; i < Num; i++) {
            if (Bullets[i].hp == 0) {
                Bullets[i].hp = 1;
                Bullets[i].px = px + vx * 100;
                Bullets[i].py = py + vy * 100;
                Bullets[i].vx = vx;
                Bullets[i].vy = vy;
                i = Num;
            }
        }
    }
}
void PLAYER_BULLETS::move(){
    for (int i = 0; i < Num; i++) {
        if (Bullets[i].hp > 0) {
            Bullets[i].px += Bullets[i].vx * AdvSpeed;
            Bullets[i].py += Bullets[i].vy * AdvSpeed;
            Bullets[i].angle += AngSpeed;
            if (   Bullets[i].py < -20
                || Bullets[i].py > height + 20
                || Bullets[i].px < -20
                || Bullets[i].px > width+20
                ) {
                Bullets[i].hp = 0;
            }
        }
    }
}
void PLAYER_BULLETS::draw() {
    rectMode(CENTER);
    for (int i = 0; i < Num; i++) {
        if (Bullets[i].hp > 0) {
            image(Img, Bullets[i].px, Bullets[i].py, Bullets[i].angle);
        }
    }
}