#include"libOne.h"
#include"GAME.h"
#include"BULLETS.h"
#include "PLAYER.h"
void PLAYER::create(int img) {
    Img = img;
    AngSpeed = 0.01f;
    AdvSpeed = 3;
    TriggerCnt = -9;
    TriggerInterval = 0;
}
void PLAYER::init(class GAME* game) {
    Pos.x = width / 2;
    Pos.y = height / 2;
    Angle = 0;
}
void PLAYER::move() {
    if (isPress(KEY_D)) {
        Angle += AngSpeed;
    }
    if (isPress(KEY_A)) {
        Angle += -AngSpeed;
    }
    Vec.x = sin(Angle);
    Vec.y = -cos(Angle);
    if (isPress(KEY_W)) {
        Pos += Vec * AdvSpeed;
    }
    if (isPress(KEY_S)) {
        Pos += Vec * -AdvSpeed;
    }
}
void PLAYER::launch(class BULLETS* bullets){
    if (isTrigger(KEY_SPACE)) TriggerInterval = 10;
    if (isPress(KEY_SPACE) && TriggerInterval > 0) {
        if (TriggerCnt % TriggerInterval == 0) {
            bullets->launch(Pos, Vec);
        }
        TriggerCnt++;
    }
    else {
        TriggerCnt = 0;
    }
    bullets->move();
}
void PLAYER::draw() {
    rectMode(CENTER);
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
