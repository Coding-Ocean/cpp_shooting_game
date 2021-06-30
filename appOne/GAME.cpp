//�R���e�i
#include"CONTAINER.h"
//�V�[�P���X
#include"TITLE.h"
#include"STAGE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
//�L�����N�^
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMIES.h"
#include"ENEMY_BULLETS.h"
//�Q�[���}�l�[�W���[
#include "GAME.h"
GAME::GAME() {
    //�R���e�i
    Container = new CONTAINER;
    //�V�[�P���X
    Scenes[TITLE_ID] = new TITLE(this);
    Scenes[STAGE_ID] = new STAGE(this);
    Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
    Scenes[GAME_OVER_ID] = new GAME_OVER(this);
    StageCnt = 1;
    //�L�����N�^
    Player = new PLAYER(this);
    Enemies = new ENEMIES(this);
    PlayerBullets = new PLAYER_BULLETS(this);
    EnemyBullets = new ENEMY_BULLETS(this);
}
GAME::~GAME() {
    //�L�����N�^
    SAFE_DELETE(EnemyBullets);
    SAFE_DELETE(Enemies);
    SAFE_DELETE(PlayerBullets);
    SAFE_DELETE(Player);
    //�V�[�P���X
    for (int i = 0; i < STATE_NUM; i++) {
        SAFE_DELETE(Scenes[i]);
    }
    //�R���e�i
    SAFE_DELETE(Container);
}
void GAME::run() {
    window(1920, 1080, full);
    hideCursor();
    //�ǂݍ���
    Container->load();
    //�S�v�f������
    for (int i = 0; i < STATE_NUM; i++) {
        Scenes[i]->create();
    }
    Player->create();
    Enemies->create();
    PlayerBullets->create();
    EnemyBullets->create();
    //�ŏ��̃X�e�[�g
    CurSceneId = TITLE_ID;
    Scenes[CurSceneId]->init();
    initDeltaTime();
    //�Q�[�����[�v
    while (notQuit) {
        setDeltaTime();
        Scenes[CurSceneId]->proc();
        fill(255);
        print(delta);
    }
}

//�ȉ��A���̃N���X����Ăяo����郁���o
//�@�R���e�i getter
CONTAINER* GAME::container() {
    return Container;
}
//�@�V�[�P���X
void GAME::changeScene(SCENE_ID stateId) {
    CurSceneId = stateId;
    Scenes[CurSceneId]->init();
}
int GAME::stageCnt(){
    return StageCnt;
}
void GAME::stageCntUp() {
    StageCnt++;
}
void GAME::resetStageCnt() {
    StageCnt = 1;
}
void GAME::draw() {
    Enemies->draw();
    Player->draw();
    PlayerBullets->draw();
    EnemyBullets->draw();
}
//�@�L�����N�^ getter
PLAYER* GAME::player(){
    return Player;
}
PLAYER_BULLETS* GAME::playerBullets() {
    return PlayerBullets;
}
ENEMIES* GAME::enemies() {
    return Enemies;
}
ENEMY_BULLETS* GAME::enemyBullets() {
    return EnemyBullets;
}
