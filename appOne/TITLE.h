#pragma once
#include "GAME_STATE.h"
class TITLE :
    public GAME_STATE
{
public:
    TITLE(class GAME* game);
    ~TITLE();
    void init();
    void proc();
};

