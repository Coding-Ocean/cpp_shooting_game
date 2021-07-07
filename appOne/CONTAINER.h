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
        STAGE_CLEAR::SCENE::DATA stageClearScene;
        STAGE::SCENE::DATA stageScene;
        STAGE::DATA stage;//STAGEクラスで用意したデータ
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
    //const GAME::DATA& game() { return Data.game; }
    //const TITLE::SCENE::DATA& titleScene()const { return Data.titleScene; }
    //const STAGE_CLEAR::SCENE::DATA& stageClearScene()const { return Data.stageClearScene; }
    //const STAGE::SCENE::DATA& stageScene() { return Data.stageScene; }
    //const STAGE::DATA& stage() { return Data.stage; }
    //const GAME_CLEAR::SCENE::DATA& gameClearScene() { return Data.gameClearScene; }
    //const GAME_OVER::SCENE::DATA& gameOverScene() { return Data.gameOverScene; }
    //const PLAYER::DATA& player()const { return Data.player; }
    //const ENEMIES::DATA& enemy() { return Data.enemy; }
    //const BULLETS::DATA& playerBullet() { return Data.playerBullet; }
    //const BULLETS::DATA& enemyBullet() { return Data.enemyBullet; }
    //const HP_GAUGE::DATA& hpGauge() { return Data.hpGauge; }
    //const EXPLOSIONS::DATA& explosion() { return Data.explosion; }
};