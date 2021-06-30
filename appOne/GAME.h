#pragma once
class GAME
{
//コンテナ
private:
    class CONTAINER* Container = 0;
public:
    class CONTAINER* container();
//シーケンス遷移
public:
    enum SCENE_ID{ 
        TITLE_ID,
        STAGE_ID,
        GAME_CLEAR_ID,
        GAME_OVER_ID,
        STATE_NUM
    };
private:
    class SCENE* Scenes[STATE_NUM];
    SCENE_ID CurSceneId = TITLE_ID;
    int StageCnt = 0;
public:
    void changeScene(SCENE_ID state);
    int stageCnt();
    void resetStageCnt();
    void stageCntUp();
//キャラクタ
private:
    class PLAYER* Player = 0;
    class PLAYER_BULLETS* PlayerBullets = 0;
    class ENEMIES* Enemies = 0;
    class ENEMY_BULLETS* EnemyBullets = 0;
public:
    void draw();
    class PLAYER* player();
    class PLAYER_BULLETS* playerBullets();
    class ENEMIES* enemies();
    class ENEMY_BULLETS* enemyBullets();
//ゲームマネージャー
public:
    GAME();
    ~GAME();
    void run();
};
