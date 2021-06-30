#pragma once
#include"libOne.h"
#include "SCENE.h"
class STAGE 
    : public SCENE
{
    COLOR BackColor;
public:
    STAGE(class GAME* game);
    ~STAGE();
    void create();
    void init();
    void update();
    void draw();
    void nextScene();
};

