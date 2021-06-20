#pragma once
#include "GAME_STATE.h"
class OVER :
    public GAME_STATE
{
public:
    OVER(class GAME* game);
    ~OVER();
    void init();
    void proc();
};

