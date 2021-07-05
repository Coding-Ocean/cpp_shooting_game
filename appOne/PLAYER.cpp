#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include"HP_GAUGE.h"
#include"PLAYER.h"
PLAYER::PLAYER(class GAME* game)
:GAME_OBJECT(game){
}
PLAYER::~PLAYER() {
}
void PLAYER::create() {
    Player = game()->container()->player();
}
void PLAYER::init() {
    const DATA& player = game()->container()->player();
    Player.pos = player.pos;
    Player.hp = player.hp;
}
void PLAYER::update() {
    move();
    launch();
    collision();
}
void PLAYER::move() {
    if (Player.pos.x < width - Player.limmitRange && isPress(KEY_D)) {
        Player.pos.x += Player.advSpeed * delta;
    }
    else if (Player.pos.x > Player.limmitRange && isPress(KEY_A)) {
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
    if (Player.invincibleRestTime > 0) {
        Player.invincibleRestTime -= delta;
    }
    else {
        //当たったと判定する最長距離
        BULLETS* bullets = game()->enemyBullets();
        float distance = Player.bcRadius + bullets->bcRadius();
        float sqDistance = distance * distance;
        //敵弾との当たり判定
        int curNum = bullets->curNum();
        Player.color = Player.normalColor;
        for (int i = curNum - 1; i >= 0; i--) {
            VECTOR2 vec = Player.pos - bullets->pos(i);
            if (sqLength(vec) < sqDistance) {
                Player.hp--;
                Player.color = Player.collisionColor;
                Player.invincibleRestTime = Player.invincibleTime;
                bullets->kill(i);
                i = 0;
            }
        }
    }
}
void PLAYER::draw() {
    rectMode(CENTER);
    imageColor(Player.color);
    image(Player.img, Player.pos.x, Player.pos.y, Player.angle);
    //HP gauge
    game()->hpGauge()->draw(Player.pos, Player.hpGaugeOffset, Player.hp);
#ifdef _DEBUG
    fill(255, 255, 255, 64);
    circle(Player.pos.x, Player.pos.y, Player.bcRadius * 2);
#endif
}

//Stage以外での処理ーーーーーーーーーーーーーーーーーーーーーーーー
void PLAYER::initForTitle() {
    Player.pos = Player.posForTitle;
    Player.hp = 0;
    Player.angle = 0;
    Player.color = Player.normalColor;
}
void PLAYER::initForStageClear() {
    Player.color = Player.normalColor;
}
void PLAYER::initForGameClear() {
    Player.lastPos = Player.pos;
    Player.hp = 0;
    Player.color = Player.normalColor;
}
void PLAYER::updateForGameClear() {
    //回転しながらジャンプ。着地したら一定時間立っている。
    Player.standingRestTime -= delta;
    if (Player.standingRestTime <= 0) {
        Player.pos.y = Player.lastPos.y + (cos(Player.angle)-1.0f) * 100;
        Player.angle += Player.angSpeed * delta;
        if (Player.angle >= 3.1415926f * 2) {
            Player.angle = 0;
            Player.standingRestTime = Player.standingTime;
        }
    }
    //乱射
    Player.triggerElapsedTime += delta;
    if (Player.triggerElapsedTime > Player.triggerInterval2) {
        VECTOR2 vec(sin(Player.launchAngle), -cos(Player.launchAngle));
        Player.launchAngle += Player.launchAngleSpeed;
        game()->playerBullets()->launch(Player.lastPos, vec);
        Player.triggerElapsedTime = 0;
    }
}
void PLAYER::initForGameOver() {
}
void PLAYER::updateForGameOver() {
    if (Player.angle < Player.rollingLimmit) {
        Player.angle += Player.rollingSpeed*delta;
    }
    if (Player.pos.y < Player.fallLimmit) {
        Player.pos.y += Player.fallSpeed*delta;
    }
}