#pragma once
#include"GAME_OBJECT.h"
#include"COLOR.h"
#include"VECTOR2.h"
class HP_GAUGE:
    public GAME_OBJECT
{
public:
    struct DATA {
        int hp;
        VECTOR2 pos;
        COLOR green;
        COLOR yellow;
        COLOR red;
        float coWidth;
        float hi;
        int warningHp;
        int dangerHp;
    };
private:
    DATA HpGauge;
public:
    HP_GAUGE(GAME* game);
    void create();
    void draw();
    //setter
    void setHp(int hp) { HpGauge.hp = hp; }
    void setPos(const VECTOR2& pos) { HpGauge.pos = pos; }
    void setGreen(const COLOR& c) { HpGauge.green = c; }
    void setYellow(const COLOR& c) { HpGauge.yellow = c; }
    void setRed(const COLOR& c) { HpGauge.red = c; }
    void setCoWidth(float coWidth) { HpGauge.coWidth = coWidth; }
    void setHeight(float hi) { HpGauge.hi = hi; }
    void setWarningHp(int warningHp) { HpGauge.warningHp = warningHp; }
    void setDangerHp(int dangerHp) { HpGauge.dangerHp = dangerHp; }
};

