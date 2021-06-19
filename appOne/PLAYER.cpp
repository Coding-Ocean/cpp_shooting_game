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
    TriggerCnt = -9;
    TriggerInterval = 0;
}
void PLAYER::init() {
    Pos.x = width / 2;
    Pos.y = height - 105;
    Angle = 0;
    MoveMode = 0;
}
void PLAYER::update() {
    if (isTrigger(KEY_Q)) {
        MoveMode = !MoveMode;
    }
    if (MoveMode == 0) {
        moveLeftRight();
    }
    else {
        rotate();
    }
    launch();
    collision();
}
void PLAYER::moveLeftRight() {
    Angle = 0;
    Vec.x = 0;
    Vec.y = -1;
    if (isPress(KEY_D)) {
        Pos.x += AdvSpeed;
    }
    if (isPress(KEY_A)) {
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
    if (isTrigger(KEY_SPACE)) TriggerInterval = 10;
    if (isPress(KEY_SPACE) && TriggerInterval > 0) {
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
    for (int i = curNum-1; i >= 0; i--) {
        //if (enemyBullets->hp(i)) {
            FLOAT2 pos = enemyBullets->pos(i);
            FLOAT2 vec = Pos - pos;
            if (vec.sqMag() < 50 * 50) {
                enemyBullets->kill(i);
                ColCnt = 3;
            }
        //}
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
#ifdef _DEBUG
    fill(255, 255, 255, 128);
    for (int i = 0; i < 3; i++) {
        circle(cpx(i), cpy(i), 40*2);
    }
#endif
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
