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
}
void PLAYER::init() {
    Player.advSpeed = 300;
    Player.triggerElapsedTime = 0.1f;
    Player.triggerInterval = 0.1f;
    Player.bcRadius = 40;
    Player.invincibleTime = 0.05f;
    Player.pos.x = 960;
    Player.pos.y = 975;
    Player.angle = 0;
    Player.hp = 5;
    Player.launchVec.x = 0;
    Player.launchVec.y = -1;
}
void PLAYER::update() {
    move();
    launch();
    collision();
}
void PLAYER::move() {
    float leftRange = Player.bcRadius;
    float rightRange = width - Player.bcRadius;
    if (Player.pos.x < rightRange && isPress(KEY_D)) {
        Player.pos.x += Player.advSpeed * delta;
    }
    else if (Player.pos.x > leftRange && isPress(KEY_A)) {
        Player.pos.x += -Player.advSpeed * delta;
    }
}
void PLAYER::launch(){
    if (isPress(KEY_SPACE)) {
        Player.triggerElapsedTime += delta;
        if (Player.triggerElapsedTime > Player.triggerInterval) {
            game()->playerBullets()->launch(Player.pos, Player.launchVec);
            Player.triggerElapsedTime = 0;
        }
    }
    else {
        Player.triggerElapsedTime = Player.triggerInterval;
    }
}
void PLAYER::collision() {
    BULLETS* bullets = game()->enemyBullets();
    //“–‚½‚Á‚½‚Æ”»’è‚·‚éÅ’·‹——£
    float distance = Player.bcRadius + bullets->bcRadius();
    float sqDistance = distance * distance;
    //“G’e‚Æ‚Ì“–‚½‚è”»’è
    int curNum = bullets->curNum();
    for (int i = curNum - 1; i >= 0; i--) {
        VECTOR2 vec = Player.pos - bullets->pos(i);
        if (Player.invincibleRestTime<=0 && sqLength(vec) < sqDistance) {
            bullets->kill(i);
            Player.hp--;
            Player.invincibleRestTime = Player.invincibleRestTime;
        }
    }
}
void PLAYER::draw() {
    rectMode(CENTER);
    if (Player.invincibleRestTime > 0) {
        imageColor(255, 0, 0);
        Player.invincibleRestTime -= delta;
    }
    else {
        imageColor(255);
    }
    image(Img, Player.pos.x, Player.pos.y, Player.angle);
    //HP gauge
    noStroke();
    fill(0, 255, 0);
    rect(Player.pos.x, Player.pos.y-120, Player.hp * 30.0f, 15.0f);
#ifdef _DEBUG
    fill(255, 255, 255, 64);
    for (int i = 0; i < 3; i++) {
        circle(Player.pos.x, Player.pos.y, Player.bcRadius * 2);
    }
#endif
}
void PLAYER::initForTitle() {
    init();
    Player.hp = 0;
}

