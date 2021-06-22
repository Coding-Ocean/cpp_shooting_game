#pragma once
#include "BULLETS.h"
class PLAYER_BULLETS : public BULLETS{
public:
    PLAYER_BULLETS(class GAME* game);
    ~PLAYER_BULLETS();
    void create();
};

