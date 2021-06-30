#include "HP_GAUGE.h"
HP_GAUGE::HP_GAUGE() 
:Color(0, 255, 0)
,Danger(255,0,0)
,Height(15)
,CoWidth(30){
}
void HP_GAUGE::draw(const VECTOR2& pos, const VECTOR2& offset, int hp ) {
    noStroke();
    if (hp > 1) {
        fill(Color);
    }
    else {
        fill(Danger);
    }
    rect(pos.x + offset.x, pos.y + offset.y, hp * CoWidth, Height);
}
