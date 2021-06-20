//コンテナ
#include"CONTAINER.h"
//シーケンス
#include"TITLE.h"
#include"PLAY.h"
#include"CLEAR.h"
#include"OVER.h"
//キャラクタ
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMIES.h"
#include"ENEMY_BULLETS.h"
//ゲームマネージャー
#include "GAME.h"
GAME::GAME() {
    //コンテナ
    Container = new CONTAINER;
    //シーケンス
    GameStates[STATE_TITLE] = new TITLE(this);
    GameStates[STATE_PLAY] = new PLAY(this);
    GameStates[STATE_CLEAR] = new CLEAR(this);
    GameStates[STATE_OVER] = new OVER(this);
    //キャラクタ
    Player = new PLAYER(this);
    Enemies = new ENEMIES(this);
    PlayerBullets = new PLAYER_BULLETS(this);
    EnemyBullets = new ENEMY_BULLETS(this);
}
GAME::~GAME() {
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
    window(1920, 1080, full);
    hideCursor();
    //開始前準備
    Container->loadGraphics();
    Player->initOnce();
    Enemies->initOnce();
    PlayerBullets->initOnce();
    EnemyBullets->initOnce();
    //最初のステート
    //CurStateId = STATE_PLAY;
    GameStates[CurStateId]->init();
    //ゲームループ
    while (notQuit) {
        GameStates[CurStateId]->proc();
    }
}

//以下、他のクラスから呼び出されるメンバ
//　コンテナ
CONTAINER* GAME::container() {
    return Container;
}
//　シーケンス
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
//　キャラクタ
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

