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
    Num = 8;
    CurNum = Num;
    Enemies = new ENEMY[Num]();
    TriggerCnt = 0;
    TriggerInterval = 45;
    Cx = width / 2;
    Cy = 300;
    MajRadius = 800;
    MinRadius = 100;
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
        Enemies[i].triggerCnt = 5 * (Num-i);
        Enemies[i].hp = 5;
    }
}
void ENEMIES::update() {
    move();
    launch();
    collision();
}
void ENEMIES::move() {
    for (int i = 0; i < CurNum; i++) {
        float theta = Theta + Enemies[i].theta;
        Enemies[i].pos.x = Cx + sin(theta) * MajRadius;
        Enemies[i].pos.y = Cy + -cos(theta) * MinRadius;
    }
    Theta += 0.01f;
}
void ENEMIES::launch(){
    BULLETS* bullets = game()->enemyBullets();
    FLOAT2 targetPos = game()->player()->pos();
    for (int i = 0; i < CurNum; i++) {
        if (!(++Enemies[i].triggerCnt %= TriggerInterval)) {
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
            FLOAT2 vec = Enemies[i].pos - playerBullets->pos(j);
            if (Enemies[i].colCnt <= 0 && 
                vec.sqMag() < 120 * 120) {
                Enemies[i].hp--;
                Enemies[i].colCnt = 3;
                if (Enemies[i].hp <= 0) {
                    CurNum--;
                    Enemies[i] = Enemies[CurNum];
                }
                playerBullets->kill(j);
                flag = 1;
            }
        }
    }
}
void ENEMIES::draw(){
    for (int i = 0; i < CurNum; i++) {
        if (Enemies[i].colCnt > 0) {
            imageColor(255, 0, 0,128);
            Enemies[i].colCnt--;
        }
        else {
            imageColor(255,255,255,128);
        }
        image(Img, Enemies[i].pos.x, Enemies[i].pos.y, Enemies[i].angle);
        fill(0, 255, 0);
        noStroke();
        rect(Enemies[i].pos.x-10,Enemies[i].pos.y - 120, 
            Enemies[i].hp * 30.0f, 15.0f);
#ifdef _DEBUG
        fill(255, 255, 255, 128);
        circle(Enemies[i].pos.x, Enemies[i].pos.y, 90 * 2);
#endif
    }
}
