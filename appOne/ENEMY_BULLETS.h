#pragma once
#include "BULLETS.h"
class ENEMY_BULLETS : 
    public BULLETS
{
public:
    ENEMY_BULLETS(class GAME* game);
    void create();
};

