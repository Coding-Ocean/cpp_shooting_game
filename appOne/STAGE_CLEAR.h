#pragma once
#include "SCENE.h"
class STAGE_CLEAR :
    public SCENE
{
public:
    STAGE_CLEAR(class GAME* game);
    void create();
    void init();
    void update();
    void draw();
    void nextScene();
};

