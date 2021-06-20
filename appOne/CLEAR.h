#pragma once
#include "GAME_STATE.h"
class CLEAR :
    public GAME_STATE
{
public:
    CLEAR(class GAME* game);
    ~CLEAR();
    void init();
    void proc();
};

