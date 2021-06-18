#pragma once
#include "GAME_STATE.h"
class PLAY :
    public GAME_STATE
{
    class PLAYER* Player = 0;
    class ENEMIES* Enemies = 0;
    class PLAYER_BULLETS* PlayerBullets = 0;
    class ENEMY_BULLETS* EnemyBullets = 0;
    void init(class GAME* game);
    void proc(class GAME* game);
};

