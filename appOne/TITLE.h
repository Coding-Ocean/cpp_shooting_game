#pragma once
#include "SCENE.h"
class TITLE :
    public SCENE
{
public:
    TITLE(class GAME* game);
    void create();
    void init();
    void update();
    void draw();
    void nextScene();
};

