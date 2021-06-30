#pragma once
#include "SCENE.h"
class TITLE :
    public SCENE
{
public:
    struct DATA {
        COLOR backColor;
        COLOR textColor;
        float textSize = 0;
        float px = 0, py = 0;
        char string[12];
    };
private:
    struct DATA Title;
public:
    TITLE(class GAME* game);
    ~TITLE();
    void create();
    void init();
    void draw();
    void nextScene();
};

