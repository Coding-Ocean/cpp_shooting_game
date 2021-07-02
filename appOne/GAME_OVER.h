#pragma once
#include "SCENE.h"
class GAME_OVER :
    public SCENE
{
public:
    GAME_OVER(class GAME* game);
    void create();
    void update();
    void draw();
    void nextScene();
};

