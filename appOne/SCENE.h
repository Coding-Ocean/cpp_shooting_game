#pragma once
#include"GAME_OBJECT.h"
#include"graphic.h"
#include"VECTOR2.h"
class SCENE:
    public GAME_OBJECT
{
public:
    struct DATA {
        COLOR backColor;
        COLOR textColor;
        float transSpeed = 0;
        float textSize = 0;
        VECTOR2 pos;
        char string[16] = "";
    };
protected:
    DATA Scene;
public:
    SCENE(class GAME* game);
    virtual ~SCENE();
    virtual void create();
    virtual void init();
    virtual void proc();
    virtual void update();
    virtual void draw();
    virtual void nextScene();
};

