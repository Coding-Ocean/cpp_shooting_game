#pragma once
#include"libOne.h"
#include "SCENE.h"
class STAGE 
    : public SCENE
{
public:
    struct DATA{
        int stageNum;
        int stageNo;
        char startPreMsg1[8];
        char startMsg1[16];
        char startMsg2[16];
        int FadeFlag;
    };
private:
    DATA Stage;
public:
    STAGE(class GAME* game);
    ~STAGE();
    void create();
    void init();
    void update();
    void draw();
    void nextScene();
    int stageNo();
};

