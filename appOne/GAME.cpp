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
    for (int i = 0; i < STATE_NUM; i++) {
        GameStates[i] = 0;
    }
}
GAME::~GAME() {
    destroy();
}
void GAME::create() {
    window(1920, 1080, full);
    hideCursor();
    //コンテナ
    Container = new CONTAINER;
    Container->loadGraphics();
    //キャラクタ
    Player = new PLAYER(this);
    Enemies = new ENEMIES(this);
    PlayerBullets = new PLAYER_BULLETS(this);
    EnemyBullets = new ENEMY_BULLETS(this);
    Player->prepare();
    Enemies->prepare();
    PlayerBullets->prepare();
    EnemyBullets->prepare();
    //シーケンス
    GameStates[STATE_TITLE] = new TITLE(this);
    GameStates[STATE_PLAY] = new PLAY(this);
    CurState = STATE_PLAY;
    GameStates[CurState]->init();
}
void GAME::destroy() {
    //シーケンス
    for (int i = 0; i < STATE_NUM; i++) {
        SAFE_DELETE(GameStates[i]);
    }
    //キャラクタ
    SAFE_DELETE(EnemyBullets);
    SAFE_DELETE(Enemies);
    SAFE_DELETE(PlayerBullets);
    SAFE_DELETE(Player);
    //コンテナ
    SAFE_DELETE(Container);
}
void GAME::run() {
    while (notQuit) {
        GameStates[CurState]->proc();
    }
}
void GAME::changeGameState(STATE state) {
    CurState = state;
    GameStates[CurState]->init();
}
CONTAINER* GAME::container() {
    return Container;
}
//キャラクタ
void GAME::draw() {
    Enemies->isDrawn();
    Player->isDrawn();
    PlayerBullets->isDrawn();
    EnemyBullets->isDrawn();
}
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

