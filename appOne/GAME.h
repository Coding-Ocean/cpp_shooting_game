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
    enum STATE { STATE_TITLE, STATE_PLAY, STATE_NUM };
private:
    class GAME_STATE* GameStates[STATE_NUM];
    STATE CurState = STATE_TITLE;
public:
    GAME();
    ~GAME();
    void run();
    void draw();
    void changeGameState(STATE state);
//キャラクタ
private:
    class CHARACTER* Player = 0;
    class PLAYER_BULLETS* PlayerBullets = 0;
    class ENEMIES* Enemies = 0;
    class ENEMY_BULLETS* EnemyBullets = 0;
public:
    class PLAYER* player();
    class PLAYER_BULLETS* playerBullets();
    class ENEMIES* enemies();
    class ENEMY_BULLETS* enemyBullets();
};
