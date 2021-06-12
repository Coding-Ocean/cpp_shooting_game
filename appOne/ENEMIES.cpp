#include"libOne.h"
#include"BULLETS.h"
#include"CHARACTER.h"
#include "ENEMIES.h"
ENEMIES::ENEMIES(){
}
ENEMIES::~ENEMIES(){
    destroy();
}
void ENEMIES::create(int img){
    Img = img;
    Num = 12;
    Data = new DATA[Num]();
    TriggerCnt = 0;
    TriggerInterval = 20;
}
void ENEMIES::destroy() {
    if (Data) {
        delete[] Data;
        Data = 0;
    }
}
void ENEMIES::init(class GAME* game) {
    float divTheta = 3.141592f * 2 / Num;
    float cx = width / 2;
    float cy = height / 2;
    float radius = 350;
    for (int i = 0; i < Num; i++) {
        Data[i].px = cx +  sin(divTheta*i) * radius;
        Data[i].py = cy + -cos(divTheta*i) * radius;
    }
}
void ENEMIES::move(class GAME* game) {
    float divTheta = 3.141592f * 2 / Num;
    float cx = width / 2;
    float cy = height / 2;
    float radius = 350;
    Theta += 0.01f;
    for (int i = 0; i < Num; i++) {
        Data[i].px = cx +  sin(Theta + divTheta * i) * radius;
        Data[i].py = cy + -cos(Theta + divTheta * i) * radius;
    }
}
void ENEMIES::launch(class BULLETS* bullets, class CHARACTER* target) {
    if (!(++TriggerCnt %= TriggerInterval)){
        for (int i = 0; i < Num; i++) {
            float vx = target->px() - Data[i].px;
            float vy = target->py() - Data[i].py;
            float distance = sqrt(vx * vx + vy * vy);
            vx /= distance;
            vy /= distance;
            bullets->launch(Data[i].px, Data[i].py, vx, vy);
        }
    }
    bullets->move();
}
void ENEMIES::draw(){
    for (int i = 0; i < Num; i++) {
        image(Img, Data[i].px, Data[i].py, Data[i].angle);
        fill(255, 255, 255, 128);
        circle(Data[i].px, Data[i].py, 90*2);
    }
}
