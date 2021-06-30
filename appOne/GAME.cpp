//コンテナ
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
    Scenes[TITLE_ID] = new TITLE(this);
    Scenes[STAGE_ID] = new STAGE(this);
    Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
    Scenes[GAME_OVER_ID] = new GAME_OVER(this);
    StageCnt = 1;
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
        SAFE_DELETE(Scenes[i]);
    }
    //コンテナ
    SAFE_DELETE(Container);
}
void GAME::run() {
    window(1920, 1080, full);
    hideCursor();
    //読み込み
    Container->load();
    //全要素をつくる
    for (int i = 0; i < STATE_NUM; i++) {
        Scenes[i]->create();
    }
    Player->create();
    Enemies->create();
    PlayerBullets->create();
    EnemyBullets->create();
    //最初のステート
    CurSceneId = TITLE_ID;
    Scenes[CurSceneId]->init();
    initDeltaTime();
    //ゲームループ
    while (notQuit) {
        setDeltaTime();
        Scenes[CurSceneId]->proc();
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
//　キャラクタ getter
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
