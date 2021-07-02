#pragma once
#include "SCENE.h"
class GAME_CLEAR :
    public SCENE
{
public:
    GAME_CLEAR(class GAME* game);
    void create();
    void update();
    void draw();
    void nextScene();
};

