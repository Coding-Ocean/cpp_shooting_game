#pragma once
#include "GAME_STATE.h"
class CLEAR :
    public GAME_STATE
{
    void init(class GAME* game);
    void proc(class GAME* game);
};

