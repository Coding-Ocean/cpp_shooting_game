#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"PLAYER.h"
#include"ENEMIES.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
ENEMIES::ENEMIES(class GAME* game)
:CHARACTER(game){
}
ENEMIES::~ENEMIES(){
    destroy();
}
void ENEMIES::create(){
    Img = game()->container()->enemyImg;
    TotalNum = 8;
    CurNum = TotalNum;
    Enemies = new ENEMY[TotalNum]();
    TriggerInterval = 0.72f;
    MajRadius = 800;
    MinRadius = 100;
    BCRadius = 90;
}
void ENEMIES::destroy() {
    SAFE_DELETE_ARRAY(Enemies);
}
void ENEMIES::init(){
    Cx = width / 2;
    Cy = -300;
    CurNum = TotalNum;
    float divTheta = 3.141592f * 2 / TotalNum;
    for (int i = 0; i < TotalNum; i++) {
        Enemies[i].ofstTheta = divTheta * i;
        Enemies[i].triggerElapsedTime = 0.09f * (TotalNum-i);
        Enemies[i].hp = 5;
    }
}
void ENEMIES::update() {
    move();
    launch();
    collision();
}
void ENEMIES::move() {
    //ã‚©‚ç~‚è‚Ä‚­‚é
    if (Cy < 300)Cy += 1;
    //‘È‰~ã‚ðˆÚ“®
    for (int i = 0; i < CurNum; i++) {
        float theta = RefTheta + Enemies[i].ofstTheta;
        Enemies[i].pos.x = Cx + sin(theta) * MajRadius;
        Enemies[i].pos.y = Cy + -cos(theta) * MinRadius;
    }
    //Šî€‚Æ‚È‚éŠp‚ðXV
    RefTheta += 0.6f * delta;
}
void ENEMIES::launch(){
    BULLETS* bullets = game()->enemyBullets();
    FLOAT2 targetPos = game()->player()->pos();
    for (int i = 0; i < CurNum; i++) {
        Enemies[i].triggerElapsedTime += delta;
        if ( Enemies[i].triggerElapsedTime >= TriggerInterval ) {
            FLOAT2 vec = (targetPos - Enemies[i].pos).normalize();
            bullets->launch(Enemies[i].pos, vec);
            Enemies[i].triggerElapsedTime = 0;
        }
    }
}
void ENEMIES::collision() {
    BULLETS* bullets = game()->playerBullets();
    float distance = BCRadius + bullets->bcRadius();
    float sqDistance = distance * distance;
    for (int i = CurNum - 1; i >= 0; i--) {
        int curNum = bullets->curNum();
        int flag = 0;
        for (int j = curNum - 1; j >= 0 && flag == 0; j--) {
            FLOAT2 vec = Enemies[i].pos - bullets->pos(j);
            if (Enemies[i].invincibleTime <= 0 && 
                vec.sqMag() < sqDistance) {
                Enemies[i].hp--;
                Enemies[i].invincibleTime = 0.05f;
                if (Enemies[i].hp <= 0) {
                    //kill
                    CurNum--;
                    Enemies[i] = Enemies[CurNum];
                }
                bullets->kill(j);
                flag = 1;
            }
        }
    }
}
void ENEMIES::draw(){
    for (int i = 0; i < CurNum; i++) {
        if (Enemies[i].invincibleTime > 0) {
            imageColor(255, 0, 0,128);
            Enemies[i].invincibleTime -= delta;
        }
        else {
            imageColor(255, 255, 255, 128);
        }
        image(Img, Enemies[i].pos.x, Enemies[i].pos.y, Enemies[i].angle);
        //hp gauge
        fill(0, 255, 0);
        noStroke();
        FLOAT2 ofst(-10, -120);
        FLOAT2 pos = Enemies[i].pos + ofst;
        rect(pos.x, pos.y, Enemies[i].hp * 30.0f, 15.0f);
#ifdef _DEBUG
        fill(255, 255, 255, 64);
        circle(Enemies[i].pos.x, Enemies[i].pos.y, BCRadius*2);
#endif
    }
}
