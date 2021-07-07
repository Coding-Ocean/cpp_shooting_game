#pragma once
#include"input.h"
class GAME
{
//コンテナ
private:
    class CONTAINER* Container = 0;
public:
    class CONTAINER* container() { return Container; }
//シーケンス遷移
public:
    enum SCENE_ID{ 
        TITLE_ID,
        STAGE_ID,
        STAGE_CLEAR_ID,
        GAME_CLEAR_ID,
        GAME_OVER_ID,
        STATE_NUM
    };
    struct DATA {
        INPUT_CODE changeSceneKey;
        SCENE_ID firstSceneId;
    };
private:
    DATA Game;
    class SCENE* Scenes[STATE_NUM];
    SCENE_ID CurSceneId = TITLE_ID;
public:
    void changeScene(SCENE_ID state);
    SCENE_ID curSceneId() { return CurSceneId; }
    int stageNo();
    int nextKeyPushed();
//キャラクタ
private:
    class PLAYER* Player = 0;
    class PLAYER_BULLETS* PlayerBullets = 0;
    class ENEMIES* Enemies = 0;
    class ENEMY_BULLETS* EnemyBullets = 0;
    class HP_GAUGE* HpGauge = 0;
    class EXPLOSIONS* Explosions = 0;
public:
    void draw();
    class PLAYER* player() { return Player; }
    class PLAYER_BULLETS* playerBullets() { return PlayerBullets; }
    class ENEMIES* enemies() { return Enemies; }
    class ENEMY_BULLETS* enemyBullets() { return EnemyBullets; }
    class HP_GAUGE* hpGauge() { return HpGauge; }
    class EXPLOSIONS* explosions() { return Explosions; }
//ゲームマネージャー
public:
    GAME();
    ~GAME();
    void run();
};
