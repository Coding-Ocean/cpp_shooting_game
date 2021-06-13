#include"libOne.h"
#include"BULLETS.h"
#include "ENEMIES.h"
ENEMIES::ENEMIES(){
}
ENEMIES::~ENEMIES(){
    destroy();
}
void ENEMIES::create(int img){
    Img = img;
    Num = 2;
    Enemies = new ENEMY[Num]();
    TriggerCnt = 0;
    TriggerInterval = 20;
    DivTheta = 3.141592f * 2 / Num;
    Cx = width / 2;
    Cy = 300;
    Radius = 800;
}
void ENEMIES::destroy() {
    if (Enemies) {
        delete[] Enemies;
        Enemies = 0;
    }
}
void ENEMIES::init(class GAME* game) {
}
void ENEMIES::move() {
    Theta += 0.01f;
    for (int i = 0; i < Num; i++) {
        Enemies[i].pos.x = Cx +  sin(Theta + DivTheta * i) * Radius;
        Enemies[i].pos.y = Cy + -cos(Theta + DivTheta * i) * Radius/8;
    }
}
void ENEMIES::launch(class BULLETS* bullets, const FLOAT2& targetPos) {
    if (!(++TriggerCnt %= TriggerInterval)){
        for (int i = 0; i < Num; i++) {
            FLOAT2 vec = (targetPos - Enemies[i].pos).normalize();
            bullets->launch(Enemies[i].pos, vec);
        }
    }
    bullets->move();
}
void ENEMIES::draw(){
    for (int i = 0; i < Num; i++) {
        image(Img, Enemies[i].pos.x, Enemies[i].pos.y, Enemies[i].angle);
#ifdef _DEBUG
        fill(255, 255, 255, 128);
        circle(Enemies[i].pos.x, Enemies[i].pos.y, 90*2);
#endif
    }
}
