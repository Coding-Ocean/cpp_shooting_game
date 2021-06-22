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
void PLAYER::create() {
    Img = game()->container()->playerImg;
    AngSpeed = 1.2f;
    AdvSpeed = 300;
    TriggerElapsedTime = 0;
    TriggerInterval = 0.1f;
    BCRadius = 40;
}
void PLAYER::init() {
    Pos.x = width / 2;
    Pos.y = height - 105;
    Angle = 0;
    MoveMode = 0;
    Hp = 5;
    Dir.x = 0;
    Dir.y = -1;
}
void PLAYER::update() {
    move();
    launch();
    collision();
}
void PLAYER::move() {
    if (Pos.x < width - 100 && isPress(KEY_D)) {
        Pos.x += AdvSpeed * delta;
    }
    if (Pos.x > 100 && isPress(KEY_A)) {
        Pos.x += -AdvSpeed * delta;
    }
}
void PLAYER::launch(){
    if (isPress(KEY_SPACE)) {
        TriggerElapsedTime += delta;
        if (TriggerElapsedTime > TriggerInterval) {
            game()->playerBullets()->launch(Pos, Dir);
            TriggerElapsedTime = 0;
        }
    }
    else {
        TriggerElapsedTime = TriggerInterval;
    }
}
void PLAYER::collision() {
    BULLETS* bullets = game()->enemyBullets();
    //“–‚½‚Á‚½‚Æ”»’è‚·‚éÅ’·‹——£
    float distance = BCRadius + bullets->bcRadius();
    float sqDistance = distance * distance;
    //“G’e‚Æ‚Ì“–‚½‚è”»’è
    int curNum = bullets->curNum();
    for (int i = curNum - 1; i >= 0; i--) {
        FLOAT2 pos = bullets->pos(i);
        FLOAT2 vec = Pos - pos;
        if (InvincibleTime<=0 && vec.sqMag() < sqDistance) {
            bullets->kill(i);
            Hp--;
            InvincibleTime = 0.05f;
        }
    }
}
void PLAYER::draw() {
    rectMode(CENTER);
    if (InvincibleTime > 0) {
        imageColor(255, 0, 0);
        InvincibleTime -= delta;
    }
    else {
        imageColor(255);
    }
    image(Img, Pos.x, Pos.y, Angle);
    fill(0, 255, 0);
    noStroke();
    rect(Pos.x, Pos.y-120, Hp * 30.0f, 15.0f);
#ifdef _DEBUG
    fill(255, 255, 255, 64);
    for (int i = 0; i < 3; i++) {
        circle(Pos.x, Pos.y, BCRadius * 2);
    }
#endif
}
int PLAYER::hp() {
    return Hp;
}
void PLAYER::initForTitle() {
    init();
    Hp = 0;
}
