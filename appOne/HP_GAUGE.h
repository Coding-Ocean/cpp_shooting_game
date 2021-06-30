#pragma once
#include"graphic.h"
#include"VECTOR2.h"
class HP_GAUGE
{
private:
    COLOR Color;
    COLOR Danger;
    float Height;
    float CoWidth;
public:
    HP_GAUGE();
    void draw(const VECTOR2& pos, const VECTOR2& offset, int hp);
};

