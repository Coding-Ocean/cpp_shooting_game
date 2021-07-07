//コンテナ
#include"CONTAINER.h"
//シーケンス
#include"TITLE.h"
#include"STAGE.h"
#include"STAGE_CLEAR.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
//キャラクタ
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMIES.h"
#include"ENEMY_BULLETS.h"
#include"HP_GAUGE.h"
#include"EXPLOSIONS.h"
//ゲームマネージャー
#include "GAME.h"
GAME::GAME() {
    //コンテナ
    Container = new CONTAINER;
    //シーケンス
    Scenes[TITLE_ID] = new TITLE(this);
    Scenes[STAGE_ID] = new STAGE(this);
    Scenes[STAGE_CLEAR_ID] = new STAGE_CLEAR(this);
    Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
    Scenes[GAME_OVER_ID] = new GAME_OVER(this);
    //キャラクタ
    Player = new PLAYER(this);
    Enemies = new ENEMIES(this);
    PlayerBullets = new PLAYER_BULLETS(this);
    EnemyBullets = new ENEMY_BULLETS(this);
    HpGauge = new HP_GAUGE(this);
    Explosions = new EXPLOSIONS(this);
}
GAME::~GAME() {
    //キャラクタ
    SAFE_DELETE(Explosions);
    SAFE_DELETE(HpGauge);
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
    Game = Container->game();
    for (int i = 0; i < STATE_NUM; i++) {
        Scenes[i]->create();
    }
    Player->create();
    Enemies->create();
    PlayerBullets->create();
    EnemyBullets->create();
    HpGauge->create();
    Explosions->create();
    //最初のステート
    changeScene(Game.firstSceneId);
    initDeltaTime();
    //ゲームループ
    while (notQuit) {
        setDeltaTime();
        Scenes[CurSceneId]->proc();
    }
}

//以下、他のクラスから呼び出されるメンバ
//　シーケンス
void GAME::changeScene(SCENE_ID stateId) {
    CurSceneId = stateId;
    Scenes[CurSceneId]->init();
}
void GAME::draw() {
    Enemies->draw();
    Player->draw();
    PlayerBullets->draw();
    EnemyBullets->draw();
    Explosions->draw();
}
int GAME::stageNo() {
    //Enemiesの数をステージカウンターと同じにするためのメンバ
    STAGE* stage = dynamic_cast<STAGE*>(Scenes[STAGE_ID]);
    return stage->stageNo();
}
int GAME::nextKeyPushed() {
    return isTrigger(Game.changeSceneKey);
}

