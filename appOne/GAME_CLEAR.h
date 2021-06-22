#pragma once
#include "GAME_STATE.h"
class GAME_CLEAR :
    public GAME_STATE
{
    COLOR BackColor;
public:
    GAME_CLEAR(class GAME* game);
    ~GAME_CLEAR();
    void create();
    void proc();
};

