#pragma once
#include "GAME_STATE.h"
class OVER :
    public GAME_STATE
{
    void init(class GAME* game);
    void proc(class GAME* game);
};

