#pragma once
#include "SCENE.h"
class STAGE 
    : public SCENE
{
public:
    struct DATA{
        int stageNum;
        int stageNo;
        int stageInitNo;
        char preMsg[16];//prefix message
        char sufMsg[16];//suffix message
        char lastMsg[16];
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

