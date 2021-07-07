#pragma once
#include"GAME_OBJECT.h"
#include"COLOR.h"
#include"VECTOR2.h"
#include"MESSAGE.h"
class SCENE:
    public GAME_OBJECT
{
public:
    struct DATA {
        COLOR backColor;
        MESSAGE message;
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

