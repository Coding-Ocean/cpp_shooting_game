#pragma once
#include "SCENE.h"
class GAME_CLEAR :
    public SCENE
{
    COLOR BackColor;
public:
    GAME_CLEAR(class GAME* game);
    ~GAME_CLEAR();
    void create();
    void update();
    void draw();
    void nextScene();
};

