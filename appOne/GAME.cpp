//�R���e�i
#include"CREATE_BIN.h"
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
    GameStates[STATE_TITLE] = new TITLE(this);
    GameStates[STATE_STAGE] = new STAGE(this);
    GameStates[STATE_GAME_CLEAR] = new GAME_CLEAR(this);
    GameStates[STATE_GAME_OVER] = new GAME_OVER(this);
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
        SAFE_DELETE(GameStates[i]);
    }
    //�R���e�i
    SAFE_DELETE(Container);
}
void GAME::run() {
    window(1920, 1080, full);
    hideCursor();

    CREATE_BIN bin;
    bin.createBinary();

    //�ǂݍ���
    Container->loadGraphics();
    Container->loadData();
    //�S�v�f������
    for (int i = 0; i < STATE_NUM; i++) {
        GameStates[i]->create();
    }
    Player->create();
    Enemies->create();
    PlayerBullets->create();
    EnemyBullets->create();
    //�ŏ��̃X�e�[�g
    CurStateId = STATE_TITLE;
    GameStates[CurStateId]->init();
    initDeltaTime();
    //�Q�[�����[�v
    while (notQuit) {
        setDeltaTime();
        GameStates[CurStateId]->proc();
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
void GAME::changeGameState(STATE_ID stateId) {
    CurStateId = stateId;
    GameStates[CurStateId]->init();
}
void GAME::draw() {
    Enemies->draw();
    Player->draw();
    PlayerBullets->draw();
    EnemyBullets->draw();
}
//�@�L�����N�^ getter
PLAYER* GAME::player(){
    return (PLAYER*)Player;
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
