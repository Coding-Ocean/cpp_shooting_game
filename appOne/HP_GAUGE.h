#pragma once
#include"GAME_OBJECT.h"
#include"COLOR.h"
#include"VECTOR2.h"
class HP_GAUGE:
    public GAME_OBJECT
{
public:
    struct DATA {
        COLOR color;
        COLOR danger;
        float coWidth;
        float h;
    };
private:
    DATA HpGauge;
public:
    HP_GAUGE(GAME* game);
    void create();
    void draw(const VECTOR2& pos, const VECTOR2& offset, int hp);
};

