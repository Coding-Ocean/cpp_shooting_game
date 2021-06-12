#pragma once
#include "GAME_STATE.h"
class TITLE :
    public GAME_STATE
{
    void init(class GAME* game);
    void proc(class GAME* game);
};

