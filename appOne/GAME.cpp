//コンテナ
#include"CREATE_BIN.h"
#include"CONTAINER.h"
//シーケンス
#include"TITLE.h"
#include"STAGE.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
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
    GameStates[STATE_STAGE] = new STAGE(this);
    GameStates[STATE_GAME_CLEAR] = new GAME_CLEAR(this);
    GameStates[STATE_GAME_OVER] = new GAME_OVER(this);
    //キャラクタ
    Player = new PLAYER(this);
    Enemies = new ENEMIES(this);
    PlayerBullets = new PLAYER_BULLETS(this);
    EnemyBullets = new ENEMY_BULLETS(this);
}
GAME::~GAME() {
    //キャラクタ
    SAFE_DELETE(EnemyBullets);
    SAFE_DELETE(Enemies);
    SAFE_DELETE(PlayerBullets);
    SAFE_DELETE(Player);
    //シーケンス
    for (int i = 0; i < STATE_NUM; i++) {
        SAFE_DELETE(GameStates[i]);
    }
    //コンテナ
    SAFE_DELETE(Container);
}
void GAME::run() {
    window(1920, 1080, full);
    hideCursor();

    CREATE_BIN bin;
    bin.createBinary();

    //読み込み
    Container->loadGraphics();
    Container->loadData();
    //全要素をつくる
    for (int i = 0; i < STATE_NUM; i++) {
        GameStates[i]->create();
    }
    Player->create();
    Enemies->create();
    PlayerBullets->create();
    EnemyBullets->create();
    //最初のステート
    CurStateId = STATE_TITLE;
    GameStates[CurStateId]->init();
    initDeltaTime();
    //ゲームループ
    while (notQuit) {
        setDeltaTime();
        GameStates[CurStateId]->proc();
        fill(255);
        print(delta);
    }
}

//以下、他のクラスから呼び出されるメンバ
//　コンテナ getter
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
//　キャラクタ getter
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
