#pragma once
#include "SCENE.h"
class STAGE 
    : public SCENE
{
public:
    struct DATA{
        int num;
        int no;
        int initNo;
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
    int no();
};

