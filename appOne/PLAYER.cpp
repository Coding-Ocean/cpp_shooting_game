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
    Px = width / 2;
    Py = height / 2;
    Angle = 0;
}
void PLAYER::move() {
    if (isPress(KEY_D)) {
        Angle += AngSpeed;
    }
    if (isPress(KEY_A)) {
        Angle += -AngSpeed;
    }
    Vx = sin(Angle);
    Vy = -cos(Angle);
    if (isPress(KEY_W)) {
        Px += Vx * AdvSpeed;
        Py += Vy * AdvSpeed;
    }
    if (isPress(KEY_S)) {
        Px += -Vx * AdvSpeed;
        Py += -Vy * AdvSpeed;
    }
}
void PLAYER::launch(class BULLETS* bullets){
    if (isPress(KEY_SPACE)&&TriggerInterval>0) {
        if (TriggerCnt % TriggerInterval == 0) {
            bullets->launch(Px, Py, Vx, Vy);
        }
        TriggerCnt++;
    }
    else {
        TriggerCnt = 0;
        TriggerInterval = 10;
    }
    bullets->move();
}
void PLAYER::draw() {
    rectMode(CENTER);
    image(Img, Px, Py, Angle);
    fill(255, 255, 255, 128);
    for (int i = 0; i < 3; i++) {
        circle(cpx(i), cpy(i), 40*2);
    }
}

float PLAYER::cpx(int i) {
    CollisionOffset = 70;
    if (i == 0) { return Px + Vx * CollisionOffset; }
    if (i == 1) { return Px + Vx * -CollisionOffset; }
    if (i == 2) { return Px; }
    return 0;
}
float PLAYER::cpy(int i) {
    if (i == 0) { return Py + Vy * CollisionOffset; }
    if (i == 1) { return Py + Vy * -CollisionOffset; }
    if (i == 2) { return Py; }
    return 0;
}
