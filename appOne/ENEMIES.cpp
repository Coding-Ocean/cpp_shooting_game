#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"ENEMY_BULLETS.h"
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMIES.h"
ENEMIES::ENEMIES(class GAME* game)
:CHARACTER(game){
}
ENEMIES::~ENEMIES(){
    destroy();
}
void ENEMIES::initOnce(){
    Img = game()->container()->enemyImg;
    Num = 20;
    CurNum = Num;
    Enemies = new ENEMY[Num]();
    TriggerCnt = 0;
    TriggerInterval = 60;
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
void ENEMIES::init(){
    CurNum = Num;
    float divTheta = 3.141592f * 2 / Num;
    for (int i = 0; i < Num; i++) {
        Enemies[i].theta = divTheta * i;
    }
}
void ENEMIES::update() {
    for (int i = 0; i < CurNum; i++) {
        float theta = Theta + Enemies[i].theta;
        Enemies[i].pos.x = Cx + sin(theta) * Radius;
        Enemies[i].pos.y = Cy + -cos(theta) * Radius / 8;
    }
    Theta += 0.01f;
    launch();
    collision();
}
void ENEMIES::launch(){
    BULLETS* bullets = game()->enemyBullets();
    FLOAT2 targetPos = game()->player()->pos();
    if (!(++TriggerCnt %= TriggerInterval)){
        for (int i = 0; i < CurNum; i++) {
            FLOAT2 vec = (targetPos - Enemies[i].pos).normalize();
            bullets->launch(Enemies[i].pos, vec);
        }
    }
}
void ENEMIES::collision() {
    BULLETS* playerBullets = game()->playerBullets();
    for (int i = CurNum - 1; i >= 0; i--) {
        int curNum = playerBullets->curNum();
        int flag = 0;
        for (int j = curNum - 1; j >= 0 && flag == 0; j--) {
            FLOAT2 pos = playerBullets->pos(j);
            FLOAT2 vec = Enemies[i].pos - pos;
            if (vec.sqMag() < 100 * 100) {
                this->kill(i);
                playerBullets->kill(j);
                flag = 1;
            }
        }
    }
}
void ENEMIES::kill(int i) {
    CurNum--;
    Enemies[i] = Enemies[CurNum];
}
void ENEMIES::draw(){
    for (int i = 0; i < CurNum; i++) {
        imageColor(255);
        image(Img, Enemies[i].pos.x, Enemies[i].pos.y, Enemies[i].angle);
#ifdef _DEBUG
        fill(255, 255, 255, 128);
        circle(Enemies[i].pos.x, Enemies[i].pos.y, 90 * 2);
#endif
    }
}
