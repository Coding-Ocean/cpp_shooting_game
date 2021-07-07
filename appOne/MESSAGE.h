#pragma once
#include"COLOR.h"
#include"VECTOR2.h"
class MESSAGE{
public:
        COLOR color;
        float size = 0;
        char string[16] = "";
        VECTOR2 pos;
        //•Ï‰»
        VECTOR2 vec;
        float transSpeed = 0;
        int fadeSw = 0;
private:
    void CalcPos();
public:
    void create();
    void init();
    void update();
    void draw();
};

