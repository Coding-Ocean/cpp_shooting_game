#pragma once
#include "SCENE.h"
class GAME_OVER :
    public SCENE
{
    COLOR BackColor;
public:
    GAME_OVER(class GAME* game);
    ~GAME_OVER();
    void create();
    void update();
    void draw();
    void nextScene();
};

