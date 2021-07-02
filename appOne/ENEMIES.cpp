#include"libOne.h"
#include"GAME.h"
#include"STAGE.h"
#include"CONTAINER.h"
#include"HP_GAUGE.h"
#include"PLAYER.h"
#include"ENEMIES.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
ENEMIES::ENEMIES(class GAME* game)
:GAME_OBJECT(game){
}
ENEMIES::~ENEMIES(){
    SAFE_DELETE_ARRAY(Enemies);
}
void ENEMIES::create(){
    Enemy = game()->container()->data()->enemy;
    Enemies = new ENEMY[Enemy.totalNum];
}
void ENEMIES::init(){
    //集団の中心位置初期化
    Enemy.centerPos = game()->container()->data()->enemy.centerPos;
    //ステージ数を敵の数とする
    if (game()->stageCnt() < Enemy.totalNum) {
        Enemy.curNum = game()->stageCnt();
    }
    else {
        Enemy.curNum = Enemy.totalNum;
    }
    //各敵の初期化
    float divTheta = M_2PI / Enemy.curNum;
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
            Enemies[i].triggerElapsedTime = 0;
        }
    }
}
void ENEMIES::collision() {
    BULLETS* bullets = game()->playerBullets();
    float distance = Enemy.bcRadius + bullets->bcRadius();
    float sqDistance = distance * distance;
    for (int i = Enemy.curNum - 1; i >= 0; i--) {
        for (int j = bullets->curNum() - 1; j >= 0; j--) {
            VECTOR2 vec = Enemies[i].pos - bullets->pos(j);
            if (Enemies[i].invincibleRestTime <= 0 && sqLength(vec) < sqDistance) {
                Enemies[i].hp--;
                Enemies[i].invincibleRestTime = Enemy.invincibleTime;
                if (Enemies[i].hp <= 0) {
                    Enemy.curNum--;
                    Enemies[i] = Enemies[Enemy.curNum];
                }
                bullets->kill(j);
                j = 0;
            }
        }
    }
}
void ENEMIES::draw(){
    for (int i = 0; i < Enemy.curNum; i++) {
        if (Enemies[i].invincibleRestTime > 0) {
            imageColor(Enemy.collisionColor);
            Enemies[i].invincibleRestTime -= delta;
        }
        else {
            imageColor(Enemy.normalColor);
        }
        image(Enemy.img, Enemies[i].pos.x, Enemies[i].pos.y, Enemies[i].angle);
        //hp gauge
        game()->hpGauge()->draw(Enemies[i].pos, Enemy.hpGaugeOffset, Enemies[i].hp);
#ifdef _DEBUG
        fill(255, 255, 255, 64);
        circle(Enemies[i].pos.x, Enemies[i].pos.y, Enemy.bcRadius*2);
#endif
    }
}
