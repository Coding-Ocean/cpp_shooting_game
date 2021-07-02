#pragma once
#include"libOne.h"
#include "SCENE.h"
class STAGE 
    : public SCENE
{
public:
    struct DATA{
        int stageNum;
        int stageCnt;
    };
private:
    STAGE::DATA Stage;
public:
    STAGE(class GAME* game);
    ~STAGE();
    void create();
    void init();
    void update();
    void draw();
    void nextScene();
    int stageCnt();
};

