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
    Enemy.totalNum = 8;
    Enemy.triggerInterval = 0.72f;
    Enemy.majRadius = 800;
    Enemy.minRadius = 100;
    Enemy.invincibleTime = 0.05f;
    Enemy.bcRadius = 90;
    Enemy.hp = 5;
    Enemy.ofstTime = 0.09f;
    Enemies = new ENEMY[Enemy.totalNum]();
}
void ENEMIES::destroy() {
    SAFE_DELETE_ARRAY(Enemies);
}
void ENEMIES::init(){
    Enemy.centerX = 960;
    Enemy.centerY = -300;
    Enemy.curNum = Enemy.totalNum;
    float divTheta = 3.1415926f * 2 / Enemy.totalNum;
    for (int i = 0; i < Enemy.totalNum; i++) {
        Enemies[i].ofstTheta = divTheta * i;
        Enemies[i].triggerElapsedTime = Enemy.ofstTime * (Enemy.totalNum-i);
        Enemies[i].hp = Enemy.hp;
    }
}
void ENEMIES::update() {
    move();
    launch();
    collision();
}
void ENEMIES::move() {
    //ã‚©‚ç~‚è‚Ä‚­‚é
    if (Enemy.centerY < 300)Enemy.centerY += 1;
    //‘È‰~ã‚ðˆÚ“®
    for (int i = 0; i < Enemy.curNum; i++) {
        float theta = Enemy.refTheta + Enemies[i].ofstTheta;
        Enemies[i].pos.x = Enemy.centerX + sin(theta) * Enemy.majRadius;
        Enemies[i].pos.y = Enemy.centerY + -cos(theta) * Enemy.minRadius;
    }
    //Šî€‚Æ‚È‚éŠp‚ðXV
    Enemy.refTheta += 0.6f * delta;
}
void ENEMIES::launch(){
    BULLETS* bullets = game()->enemyBullets();
    VECTOR2 targetPos = game()->player()->pos();
    for (int i = 0; i < Enemy.curNum; i++) {
        Enemies[i].triggerElapsedTime += delta;
        if ( Enemies[i].triggerElapsedTime >= Enemy.triggerInterval ) {
            VECTOR2 launchVec = normalize(targetPos - Enemies[i].pos);
            bullets->launch(Enemies[i].pos, launchVec);
            Enemies[i].triggerElapsedTime = 0;
        }
    }
}
void ENEMIES::collision() {
    BULLETS* bullets = game()->playerBullets();
    float distance = Enemy.bcRadius + bullets->bcRadius();
    float sqDistance = distance * distance;
    for (int i = Enemy.curNum - 1; i >= 0; i--) {
        int curNum = bullets->curNum();
        int flag = 0;
        for (int j = curNum - 1; j >= 0 && flag == 0; j--) {
            VECTOR2 vec = Enemies[i].pos - bullets->pos(j);
            if (Enemies[i].invincibleRestTime <= 0 && 
                sqLength(vec) < sqDistance) {
                Enemies[i].hp--;
                Enemies[i].invincibleRestTime = Enemy.invincibleTime;
                if (Enemies[i].hp <= 0) {
                    //kill
                    Enemy.curNum--;
                    Enemies[i] = Enemies[Enemy.curNum];
                }
                bullets->kill(j);
                flag = 1;
            }
        }
    }
}
void ENEMIES::draw(){
    for (int i = 0; i < Enemy.curNum; i++) {
        if (Enemies[i].invincibleRestTime > 0) {
            imageColor(255, 0, 0,128);
            Enemies[i].invincibleRestTime -= delta;
        }
        else {
            imageColor(255, 255, 255, 128);
        }
        image(Img, Enemies[i].pos.x, Enemies[i].pos.y, Enemies[i].angle);
        //hp gauge
        fill(0, 255, 0);
        noStroke();
        VECTOR2 ofst(-10, -120);
        VECTOR2 pos = Enemies[i].pos + ofst;
        rect(pos.x, pos.y, Enemies[i].hp * 30.0f, 15.0f);
#ifdef _DEBUG
        fill(255, 255, 255, 64);
        circle(Enemies[i].pos.x, Enemies[i].pos.y, bcRadius*2);
#endif
    }
}
