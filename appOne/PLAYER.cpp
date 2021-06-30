#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include"PLAYER.h"
PLAYER::PLAYER(class GAME* game)
:GAME_OBJECT(game) {
}
PLAYER::~PLAYER() {
}
void PLAYER::create() {
    Player = game()->container()->data()->player;
}
void PLAYER::init() {
    const DATA& player = game()->container()->data()->player;
    Player.pos = player.pos;
    Player.hp = player.hp;
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
    //���������Ɣ��肷��Œ�����
    float distance = Player.bcRadius + bullets->bcRadius();
    float sqDistance = distance * distance;
    //�G�e�Ƃ̓����蔻��
    int curNum = bullets->curNum();
    for (int i = curNum - 1; i >= 0; i--) {
        VECTOR2 vec = Player.pos - bullets->pos(i);
        if (Player.invincibleRestTime<=0 && sqLength(vec) < sqDistance) {
            Player.hp--;
            Player.invincibleRestTime = Player.invincibleTime;
            bullets->kill(i);
        }
    }
}
void PLAYER::draw() {
    rectMode(CENTER);
    if (Player.invincibleRestTime > 0) {
        imageColor(Player.collisionColor);
        Player.invincibleRestTime -= delta;
    }
    else {
        imageColor(Player.normalColor);
    }
    image(Player.img, Player.pos.x, Player.pos.y, Player.angle);
    //HP gauge
    HpGauge.draw(Player.pos, Player.hpGaugeOffset, Player.hp);
#ifdef _DEBUG
    fill(255, 255, 255, 64);
    circle(Player.pos.x, Player.pos.y, Player.bcRadius * 2);
#endif
}
void PLAYER::initForTitle() {
    Player.pos = game()->container()->data()->player.posForTitle;
    Player.hp = 0;
}
