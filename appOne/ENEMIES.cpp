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
void ENEMIES::prepare(){
    Img = game()->contanier()->enemyImg;
    Num = 4;
    Enemies = new ENEMY[Num]();
    TriggerCnt = 0;
    TriggerInterval = 60;
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
void ENEMIES::start(){
    for (int i = 0; i < Num; i++) {
        Enemies[i].hp = 1;
    }
}
void ENEMIES::move() {
    Theta += 0.01f;
    for (int i = 0; i < Num; i++) {
        if (Enemies[i].hp>0) {
            Enemies[i].pos.x = Cx + sin(Theta + DivTheta * i) * Radius;
            Enemies[i].pos.y = Cy + -cos(Theta + DivTheta * i) * Radius / 8;
        }
    }
    launch();
    collision();
}
void ENEMIES::launch(){
    BULLETS* bullets = game()->enemyBullets();
    FLOAT2 targetPos = game()->player()->pos();
    if (!(++TriggerCnt %= TriggerInterval)){
        for (int i = 0; i < Num; i++) {
            if (Enemies[i].hp) {
                FLOAT2 vec = (targetPos - Enemies[i].pos).normalize();
                bullets->launch(Enemies[i].pos, vec);
            }
        }
    }
    bullets->move();
}
void ENEMIES::collision() {
    PLAYER_BULLETS* playerBullets = game()->playerBullets();
    int num = playerBullets->num();
    for (int i = 0; i < Num; i++) {
        if (Enemies[i].hp) {
            for (int j = 0; j < num; j++) {
                if (playerBullets->hp(j)) {
                    FLOAT2 pos = playerBullets->pos(j);
                    FLOAT2 vec = Enemies[i].pos - pos;
                    if (vec.sqMag() < 100 * 100) {
                        Enemies[i].hp = 0;
                        playerBullets->kill(j);
                    }
                }
            }
        }
    }
}
void ENEMIES::isDrawn(){
    for (int i = 0; i < Num; i++) {
        if (Enemies[i].hp > 0) {
            imageColor(255);
            image(Img, Enemies[i].pos.x, Enemies[i].pos.y, Enemies[i].angle);
#ifdef _DEBUG
            fill(255, 255, 255, 128);
            circle(Enemies[i].pos.x, Enemies[i].pos.y, 90 * 2);
#endif
        }
    }
}
