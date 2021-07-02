#pragma once
#include"TITLE.h"
#include"STAGE.h"
#include"STAGE_CLEAR.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
#include"PLAYER.h"
#include"ENEMIES.h"
#include"BULLETS.h"
#include"HP_GAUGE.h"
class CONTAINER {
private:
    struct ALL_DATA {
        TITLE::DATA title;
        STAGE_CLEAR::DATA stageClear;
        STAGE::SCENE::DATA stageScene;
        STAGE::DATA stage;
        GAME_CLEAR::DATA gameClear;
        GAME_OVER::DATA gameOver;
        PLAYER::DATA player;
        ENEMIES::DATA enemy;
        BULLETS::DATA playerBullet;
        BULLETS::DATA enemyBullet;
        HP_GAUGE::DATA hpGauge;
    };
    struct ALL_DATA Data;
public:
    const ALL_DATA* data()const { return &Data; }
    const TITLE::DATA& title()const { return Data.title; }
    const STAGE_CLEAR::DATA& stageClear()const { return Data.stageClear; }
    const PLAYER::DATA& player()const { return Data.player; }
    void load();
    void setData();
    void loadGraphics();
    VECTOR2 calcPos(const char* str, float size);
};