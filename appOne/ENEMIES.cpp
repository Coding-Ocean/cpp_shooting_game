#include"common.h"
#include"window.h"
#include"graphic.h"
#include"mathUtil.h"
#include"GAME.h"
#include"STAGE.h"
#include"CONTAINER.h"
#include"HP_GAUGE.h"
#include"PLAYER.h"
#include"ENEMIES.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include"EXPLOSIONS.h"
ENEMIES::ENEMIES(class GAME* game)
:GAME_OBJECT(game){
}
ENEMIES::~ENEMIES(){
    SAFE_DELETE_ARRAY(Enemies);
}
void ENEMIES::create(){
    Enemy = game()->container()->data().enemy;
    Enemies = new ENEMY[Enemy.totalNum];
}
void ENEMIES::init(){
    //集団の中心位置初期化
    Enemy.centerPos = game()->container()->data().enemy.centerPos;
    //ステージ数を敵の数とする
    if (game()->stage()->no() < Enemy.totalNum) {
        Enemy.curNum = game()->stage()->no();
    }
    else {
        Enemy.curNum = Enemy.totalNum;
    }
    //各敵の初期化
    float divTheta = 3.1415926f * 2 / Enemy.curNum;
    float divInterval = Enemy.triggerInterval / Enemy.curNum;
    for (int i = 0; i < Enemy.curNum; i++) {
        Enemies[i].ofstTheta = divTheta * i;
        Enemies[i].triggerElapsedTime = divInterval * i;
        Enemies[i].hp = Enemy.hp;
    }
}
void ENEMIES::update() {
    move();
    if (game()->curSceneId() == GAME::STAGE_ID) {
        launch();
        collision();
    }
}
void ENEMIES::move() {
    //上から集団で降りてくる
    if (Enemy.centerPos.y < Enemy.arrivalY) {
        Enemy.centerPos.y += Enemy.fallSpeedY * delta;
    }
    //楕円上に配置
    VECTOR2 ofstPos;
    for (int i = 0; i < Enemy.curNum; i++) {
        float theta = Enemy.refTheta + Enemies[i].ofstTheta;
        ofstPos.x = cos(theta) * Enemy.majRadius;
        ofstPos.y = sin(theta) * Enemy.minRadius;
        Enemies[i].pos = Enemy.centerPos + ofstPos;
    }
    //基準となる角を更新
    Enemy.refTheta += Enemy.refThetaSpeed * delta;
}
void ENEMIES::launch(){
    VECTOR2 playerPos = game()->player()->pos();
    BULLETS* bullets = game()->enemyBullets();
    for (int i = 0; i < Enemy.curNum; i++) {
        Enemies[i].triggerElapsedTime += delta;
        if ( Enemies[i].triggerElapsedTime >= Enemy.triggerInterval ) {
            VECTOR2 launchVec = normalize(playerPos - Enemies[i].pos);
            bullets->launch(Enemies[i].pos, launchVec);
            Enemies[i].triggerElapsedTime -= Enemy.triggerInterval;
        }
    }
}
void ENEMIES::collision() {
    BULLETS* bullets = game()->playerBullets();
    float distance = Enemy.bcRadius + bullets->bcRadius();
    float sqDistance = distance * distance;
    for (int j = Enemy.curNum - 1; j >= 0; j--) {
        if (Enemies[j].invincibleRestTime > 0) {
            Enemies[j].invincibleRestTime -= delta;
        }
        else {
            Enemies[j].color = Enemy.normalColor;
            for (int i = bullets->curNum() - 1; i >= 0; i--) {
                VECTOR2 vec = Enemies[j].pos - bullets->pos(i);
                if (vec.sqMag() < sqDistance) {
                    Enemies[j].hp--;
                    Enemies[j].invincibleRestTime = Enemy.invincibleTime;
                    Enemies[j].color = Enemy.collisionColor;
                    if (Enemies[j].hp <= 0) {
                        game()->explosions()->trigger(Enemies[j].pos);
                        Enemy.curNum--;
                        Enemies[j] = Enemies[Enemy.curNum];
                    }
                    bullets->kill(i);
                    i = 0;
                }
            }
        }
    }
}
void ENEMIES::draw(){
    for (int i = 0; i < Enemy.curNum; i++) {
        imageColor(Enemies[i].color);
        image(Enemy.img, Enemies[i].pos.x, Enemies[i].pos.y, Enemies[i].angle);
        //hp gauge
        game()->hpGauge()->setHp(Enemies[i].hp);
        game()->hpGauge()->setPos(Enemies[i].pos + Enemy.hpGaugeOffset);
        game()->hpGauge()->draw();
#ifdef _DEBUG
        fill(255, 255, 255, 128);
        circle(Enemies[i].pos.x, Enemies[i].pos.y, Enemy.bcRadius*2);
#endif
    }
}
