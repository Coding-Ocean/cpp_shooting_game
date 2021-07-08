#pragma once
#include "SCENE.h"
class STAGE_CLEAR :
    public SCENE
{
public:
    struct DATA {
        char preMsg[16];
        char sufMsg[16];
    };
private:
    DATA StageClear;
public:
    STAGE_CLEAR(class GAME* game);
    void create();
    void init();
    void update();
    void draw();
    void nextScene();
};

