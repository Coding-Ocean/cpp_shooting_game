#pragma once
#include "GAME_STATE.h"
class GAME_OVER :
    public GAME_STATE
{
    COLOR BackColor;
public:
    GAME_OVER(class GAME* game);
    ~GAME_OVER();
    void create();
    void proc();
};

