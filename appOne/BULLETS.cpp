#include"window.h"
#include"input.h"
#include"graphic.h"
#include "BULLETS.h"
BULLETS::BULLETS(class GAME* game)
    :GAME_OBJECT(game){
}
BULLETS::~BULLETS() {
    SAFE_DELETE_ARRAY(Bullets);
}
void BULLETS::SetBulletData(const DATA& data) {
    Bullet = data;
    Bullets = new BULLET[Bullet.totalNum];
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
        if (Bullets[i].pos.y < -Bullet.bcRadius ||
            Bullets[i].pos.y > height + Bullet.bcRadius ||
            Bullets[i].pos.x < -Bullet.bcRadius ||
            Bullets[i].pos.x > width + Bullet.bcRadius
            ) {
            kill(i);
        }
    }
}
void BULLETS::draw() {
    rectMode(CENTER);
    for (int i = 0; i < Bullet.curNum; i++) {
        imageColor(255);
        image(Bullet.img, Bullets[i].pos.x, Bullets[i].pos.y, Bullets[i].angle);
#ifdef _DEBUG
        fill(255, 255, 255, 128);
        circle(Bullets[i].pos.x, Bullets[i].pos.y, Bullet.bcRadius * 2);
#endif
    }
}
void BULLETS::kill(int i) {
    //生きている弾を死んだたまに上書き
    Bullet.curNum--;
    Bullets[i] = Bullets[Bullet.curNum];
}
