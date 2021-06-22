#pragma once
#include"libOne.h"
#include "GAME_STATE.h"
class STAGE 
    : public GAME_STATE
{
    COLOR BackColor;
public:
    STAGE(class GAME* game);
    ~STAGE();
    void create();
    void init();
    void proc();
};

