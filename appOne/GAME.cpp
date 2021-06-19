//�R���e�i
#include"CONTAINER.h"
//�V�[�P���X
#include"TITLE.h"
#include"PLAY.h"
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
    GameStates[STATE_PLAY] = new PLAY(this);
    //�L�����N�^
    Player = new PLAYER(this);
    Enemies = new ENEMIES(this);
    PlayerBullets = new PLAYER_BULLETS(this);
    EnemyBullets = new ENEMY_BULLETS(this);
}
GAME::~GAME() {
    //�V�[�P���X
    for (int i = 0; i < STATE_NUM; i++) {
        SAFE_DELETE(GameStates[i]);
    }
    //�L�����N�^
    SAFE_DELETE(EnemyBullets);
    SAFE_DELETE(Enemies);
    SAFE_DELETE(PlayerBullets);
    SAFE_DELETE(Player);
    //�R���e�i
    SAFE_DELETE(Container);
}
void GAME::run() {
    window(1920, 1080, full);
    hideCursor();
    //�J�n�O����
    Container->loadGraphics();
    Player->initOnce();
    Enemies->initOnce();
    PlayerBullets->initOnce();
    EnemyBullets->initOnce();
    //�ŏ��̃X�e�[�g
    CurState = STATE_PLAY;
    GameStates[CurState]->init();
    while (notQuit) {
        GameStates[CurState]->proc();
    }
}

//�ȉ��A���̃N���X����Ăяo����郁���o
//�@�R���e�i
CONTAINER* GAME::container() {
    return Container;
}
//�@�V�[�P���X
void GAME::changeGameState(STATE state) {
    CurState = state;
    GameStates[CurState]->init();
}
void GAME::draw() {
    Enemies->draw();
    Player->draw();
    PlayerBullets->draw();
    EnemyBullets->draw();
}
//�@�L�����N�^
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

