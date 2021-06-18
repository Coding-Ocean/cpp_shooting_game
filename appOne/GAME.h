#pragma once
#include"GAME_STATE.h"
class GAME
{
//コンテナ
private:
    class CONTAINER* Container = 0;
public:
    class CONTAINER* contanier();
//シーケンス遷移
private:
    class GAME_STATE* CurrentGameState = 0;
    class GAME_STATE* GameStates[GAME_STATE::NUM];
public:
    GAME();
    ~GAME();
    void create();
    void destroy();
    void run();
    void draw();
    void changeGameState(GAME_STATE::ID id);
//キャラクタ
private:
    class PLAYER* Player = 0;
    class PLAYER_BULLETS* PlayerBullets = 0;
    class ENEMIES* Enemies = 0;
    class ENEMY_BULLETS* EnemyBullets = 0;
public:
    class PLAYER* player();
    class PLAYER_BULLETS* playerBullets();
    class ENEMIES* enemies();
    class ENEMY_BULLETS* enemyBullets();
};
