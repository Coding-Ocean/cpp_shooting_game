#pragma once
#include"GAME.h"
#include"TITLE.h"
#include"STAGE.h"
#include"STAGE_CLEAR.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"PLAYER.h"
#include"ENEMIES.h"
#include"BULLETS.h"
#include"HP_GAUGE.h"
#include"EXPLOSIONS.h"
class CONTAINER {
private:
    struct ALL_DATA {
        //GAME
        GAME::DATA game;
        //シーン
        TITLE::SCENE::DATA titleScene;
        STAGE::SCENE::DATA stageScene;
        STAGE::DATA stage;//STAGEクラスで用意したデータ
        STAGE_CLEAR::SCENE::DATA stageClearScene;
        STAGE_CLEAR::DATA stageClear;
        GAME_CLEAR::SCENE::DATA gameClearScene;
        GAME_OVER::SCENE::DATA gameOverScene;
        //キャラクタ
        PLAYER::DATA player;
        ENEMIES::DATA enemy;
        BULLETS::DATA playerBullet;
        BULLETS::DATA enemyBullet;
        HP_GAUGE::DATA hpGauge;
        EXPLOSIONS::DATA explosion;
    };
    struct ALL_DATA Data;
    void SetData();
    void LoadData();
    void LoadGraphics();
public:
    ~CONTAINER();
    void load();
    const ALL_DATA& data() { return Data; }
};