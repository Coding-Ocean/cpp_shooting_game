#include"libOne.h"
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
    Enemy = game()->container()->enemy();
    Enemies = new ENEMY[Enemy.totalNum];
}
void ENEMIES::init(){
    //�W�c�̒��S�ʒu������
    Enemy.centerPos = game()->container()->enemy().centerPos;
    //�X�e�[�W����G�̐��Ƃ���
    if (game()->stageNo() < Enemy.totalNum) {
        Enemy.curNum = game()->stageNo();
    }
    else {
        Enemy.curNum = Enemy.totalNum;
    }
    //�e�G�̏�����
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
    //�ォ��W�c�ō~��Ă���
    if (Enemy.centerPos.y < Enemy.arrivalY) {
        Enemy.centerPos.y += Enemy.fallSpeedY * delta;
    }
    //�ȉ~��ɔz�u
    VECTOR2 ofstPos;
    for (int i = 0; i < Enemy.curNum; i++) {
        float theta = Enemy.refTheta + Enemies[i].ofstTheta;
        ofstPos.x = cos(theta) * Enemy.majRadius;
        ofstPos.y = sin(theta) * Enemy.minRadius;
        Enemies[i].pos = Enemy.centerPos + ofstPos;
    }
    //��ƂȂ�p���X�V
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
    for (int j = Enemy.curNum - 1; j >= 0; j--) {
        if (Enemies[j].invincibleRestTime > 0) {
            Enemies[j].invincibleRestTime -= delta;
        }
        else {
            Enemies[j].color = Enemy.normalColor;
            for (int i = bullets->curNum() - 1; i >= 0; i--) {
                VECTOR2 vec = Enemies[j].pos - bullets->pos(i);
                if (sqLength(vec) < sqDistance) {
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
        game()->hpGauge()->draw(Enemies[i].pos, Enemy.hpGaugeOffset, Enemies[i].hp);
#ifdef _DEBUG
        fill(255, 255, 255, 64);
        circle(Enemies[i].pos.x, Enemies[i].pos.y, Enemy.bcRadius*2);
#endif
    }
}
