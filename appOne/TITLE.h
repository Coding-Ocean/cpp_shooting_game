#pragma once
#include<string>
#include "GAME_STATE.h"
class TITLE :
    public GAME_STATE
{
public:
    struct DATA {
        COLOR backColor;
        COLOR textColor;
        float textSize = 0;
        float px = 0, py = 0;
    };
private:
    std::string String;
    struct DATA Data;
public:
    TITLE(class GAME* game);
    ~TITLE();
    void create();
    void init();
    void proc();
};

