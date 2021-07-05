#pragma once
#include "SCENE.h"
class GAME_OVER :
    public SCENE
{
public:
    GAME_OVER(class GAME* game);
    void create();
    void init();
    void update();
    void draw();
    void nextScene();
};

