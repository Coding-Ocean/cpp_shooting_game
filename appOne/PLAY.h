#pragma once
#include "GAME_STATE.h"
class PLAY 
    : public GAME_STATE
{
public:
    PLAY(class GAME* game);
    ~PLAY();
    void init();
    void proc();
};

