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
void BULLETS::SetTotalNum(int num) {
    TotalNum = num;
    Bullets = new BULLET[TotalNum];
}
void BULLETS::init() {
    for (int i = 0; i < TotalNum; i++) {
        Bullets[i].angle = 0;
    }
    CurNum = 0;
}
void BULLETS::launch(const FLOAT2& pos, const FLOAT2& vec) {
    if (CurNum < TotalNum) {
        int i = CurNum;
        Bullets[i].pos = pos + vec * OfstLaunchDist;
        Bullets[i].vec = vec;
        CurNum++;
    }
}
void BULLETS::update() {
    for (int i = CurNum - 1; i >= 0; i--) {
        //move
        Bullets[i].pos += Bullets[i].vec * (AdvSpeed*delta);
        Bullets[i].angle += AngSpeed;
        //ウィンドウの外に出た
        if (Bullets[i].pos.y < -20
            || Bullets[i].pos.y > height + 20
            || Bullets[i].pos.x < -20
            || Bullets[i].pos.x > width + 20
            ) {
            kill(i);
        }
    }
}
void BULLETS::draw() {
    rectMode(CENTER);
    for (int i = 0; i < CurNum; i++) {
        imageColor(255);
        image(Img, Bullets[i].pos.x, Bullets[i].pos.y, Bullets[i].angle);
#ifdef _DEBUG
        fill(255, 255, 255, 64);
        circle(Bullets[i].pos.x, Bullets[i].pos.y, BCRadius * 2);
#endif
    }
}
FLOAT2 BULLETS::pos(int i) {
    return Bullets[i].pos;
}
int BULLETS::curNum() {
    return CurNum;
}
void BULLETS::kill(int i) {
    //生きている弾を死んだたまに上書き
    CurNum--;
    Bullets[i] = Bullets[CurNum];
}
float BULLETS::bcRadius() {
    return BCRadius;
}