#pragma once
#include"GAME_STATE.h"
class GAME
{
//�V�[�P���X�J��
private:
    class GAME_STATE* CurrentGameState = 0;
    class GAME_STATE** GameStates = 0;
public:
    GAME();
    ~GAME();
    void create();
    void destroy();
    void proc();
    void draw();
    void changeGameState(GAME_STATE::ID id);
//�L�����N�^
private:
    class PLAYER* Player = 0;;
    class PLAYER_BULLETS* PlayerBullets = 0;
    class ENEMIES* Enemies = 0;
    class ENEMY_BULLETS* EnemyBullets = 0;
public:
    class PLAYER* player();
    class PLAYER_BULLETS* playerBullets();
    class ENEMIES* enemies();
    class ENEMY_BULLETS* enemyBullets();
};

