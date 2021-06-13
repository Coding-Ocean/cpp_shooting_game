#pragma once
#include "BULLETS.h"
class PLAYER_BULLETS :
    public BULLETS
{
public:
    PLAYER_BULLETS();
    ~PLAYER_BULLETS();
    void create(int img);
};

