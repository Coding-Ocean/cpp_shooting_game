#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include "PLAYER.h"
PLAYER::PLAYER(class GAME* game)
    :CHARACTER(game){
}
PLAYER::~PLAYER() {
}
void PLAYER::initOnce() {
    Img = game()->container()->playerImg;
    AngSpeed = 0.02f;
    AdvSpeed = 5;
    TriggerCnt = 0;
    TriggerInterval = 10;
}
void PLAYER::init() {
    Pos.x = width / 2;
    Pos.y = height - 105;
    Angle = 0;
    MoveMode = 0;
    Hp = 5;
}
void PLAYER::update() {
    if (isTrigger(KEY_Q)) {
        MoveMode = !MoveMode;
    }
    if (MoveMode == 0) {
        move();
    }
    else {
        rotate();
    }
    launch();
    collision();
}
void PLAYER::move() {
    Angle = 0;
    Vec.x = 0;
    Vec.y = -1;
    if (Pos.x < width - 100 && isPress(KEY_D)) {
        Pos.x += AdvSpeed;
    }
    if (Pos.x > 100 && isPress(KEY_A)) {
        Pos.x += -AdvSpeed;
    }
}
void PLAYER::rotate() {
    if (isPress(KEY_D)) {
        Angle += AngSpeed;
    }
    if (isPress(KEY_A)) {
        Angle += -AngSpeed;
    }
    Vec.x = sin(Angle);
    Vec.y = -cos(Angle);
}
void PLAYER::launch(){
    if (isPress(KEY_SPACE)) {
        if (TriggerCnt % TriggerInterval == 0) {
            game()->playerBullets()->launch(Pos, Vec);
        }
        TriggerCnt++;
    }
    else {
        TriggerCnt = 0;
    }
}
void PLAYER::collision() {
    ENEMY_BULLETS* enemyBullets = game()->enemyBullets();
    int curNum = enemyBullets->curNum();
    for (int i = curNum - 1; i >= 0; i--) {
        FLOAT2 pos = enemyBullets->pos(i);
        FLOAT2 vec = Pos - pos;
        if (ColCnt==0 && vec.sqMag() < 50 * 50) {
            enemyBullets->kill(i);
            Hp--;
            ColCnt = 3;
        }
    }
}
void PLAYER::draw() {
    rectMode(CENTER);
    if (ColCnt > 0) {
        imageColor(255, 0, 0);
        ColCnt--;
    }
    else {
        imageColor(255);
    }
    image(Img, Pos.x, Pos.y, Angle);
    fill(0, 255, 0);
    noStroke();
    rect(Pos.x, Pos.y-120, Hp * 30.0f, 15.0f);
#ifdef _DEBUG
    fill(255, 255, 255, 128);
    for (int i = 0; i < 3; i++) {
        circle(cpx(i), cpy(i), 40*2);
    }
#endif
}

int PLAYER::hp() {
    return Hp;
}
void PLAYER::setZeroHp() {
    Hp = 0;
}
float PLAYER::cpx(int i) {
    CollisionOffset = 70;
    if (i == 0) { return Pos.x + Vec.x * CollisionOffset; }
    if (i == 1) { return Pos.x + Vec.x * -CollisionOffset; }
    if (i == 2) { return Pos.x; }
    return 0;
}
float PLAYER::cpy(int i) {
    if (i == 0) { return Pos.y + Vec.y * CollisionOffset; }
    if (i == 1) { return Pos.y + Vec.y * -CollisionOffset; }
    if (i == 2) { return Pos.y; }
    return 0;
}
