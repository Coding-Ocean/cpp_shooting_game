#pragma once
#include "GAME_STATE.h"
class PLAY :
    public GAME_STATE
{
    void init(class GAME* game);
    void proc(class GAME* game);
    int  collision(class GAME* game);
};

