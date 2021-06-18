#include"libOne.h"

#include"CONTAINER.h"

#include"TITLE.h"
#include"PLAY.h"
#include"OVER.h"
#include"CLEAR.h"

#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMIES.h"
#include"ENEMY_BULLETS.h"

#include "GAME.h"
GAME::GAME() {
}
GAME::~GAME() {
    destroy();
}
void GAME::create() {
    window(1920, 1080, full);
    hideCursor();
    //�R���e�i
    Container = new CONTAINER;
    Container->loadGraphics();
    //�L�����N�^
    Player = new PLAYER(this);
    Enemies = new ENEMIES(this);
    PlayerBullets = new PLAYER_BULLETS;
    EnemyBullets = new ENEMY_BULLETS;
    Player->prepare();
    Enemies->prepare();
    PlayerBullets->create(Container->playerBulletImg);
    EnemyBullets->create(Container->enemyBulletImg);
    //�V�[�P���X
    GameStates[GAME_STATE::TITLE] = new TITLE;
    GameStates[GAME_STATE::PLAY] = new PLAY;
    GameStates[GAME_STATE::OVER] = new OVER;
    GameStates[GAME_STATE::CLEAR] = new CLEAR;
    changeGameState(GAME_STATE::TITLE);
}
void GAME::destroy() {
    //�V�[�P���X
    for (int i = 0; i < GAME_STATE::NUM; i++) {
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
    while (notQuit) {
        CurrentGameState->proc(this);
    }
}
void GAME::changeGameState(GAME_STATE::ID id) {
    CurrentGameState = GameStates[id];
    CurrentGameState->init(this);
}
CONTAINER* GAME::contanier() {
    return Container;
}
//�L�����N�^
void GAME::draw() {
    Enemies->isDrawn();
    Player->isDrawn();
    PlayerBullets->draw();
    EnemyBullets->draw();
}
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

