#include"window.h"
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
void BULLETS::AllocateBullets(int num) {
    Bullets = new BULLET[num];
}
void BULLETS::init() {
    Bullet.curNum = 0;
}
void BULLETS::launch(const VECTOR2& pos, const VECTOR2& vec) {
    if (Bullet.curNum < Bullet.totalNum) {
        int i = Bullet.curNum;
        Bullets[i].pos = pos + vec * Bullet.ofstLaunchDist;
        Bullets[i].vec = vec;
        Bullets[i].angle = 0;
        Bullet.curNum++;
    }
}
void BULLETS::update() {
    for (int i = Bullet.curNum - 1; i >= 0; i--) {
        //move
        Bullets[i].pos += Bullets[i].vec * (Bullet.advSpeed * delta);
        Bullets[i].angle += Bullet.angSpeed;
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
    for (int i = 0; i < Bullet.curNum; i++) {
        imageColor(255);
        image(Img, Bullets[i].pos.x, Bullets[i].pos.y, Bullets[i].angle);
#ifdef _DEBUG
        fill(255, 255, 255, 64);
        circle(Bullets[i].pos.x, Bullets[i].pos.y, BCRadius * 2);
#endif
    }
}
VECTOR2 BULLETS::pos(int i) {
    return Bullets[i].pos;
}
int BULLETS::curNum() {
    return Bullet.curNum;
}
void BULLETS::kill(int i) {
    //生きている弾を死んだたまに上書き
    Bullet.curNum--;
    Bullets[i] = Bullets[Bullet.curNum];
}
float BULLETS::bcRadius() {
    return Bullet.bcRadius;
}