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
    enum STATE_ID{ 
        STATE_TITLE, 
        STATE_PLAY, 
        STATE_CLEAR,
        STATE_OVER,
        STATE_NUM 
    };
private:
    class GAME_STATE* GameStates[STATE_NUM];
    STATE_ID CurStateId = STATE_TITLE;
public:
    void changeGameState(STATE_ID state);
//キャラクタ
private:
    class CHARACTER* Player = 0;
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
