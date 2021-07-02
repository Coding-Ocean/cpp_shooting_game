#include"CONTAINER.h"
#include"GAME.h"
#include "HP_GAUGE.h"
HP_GAUGE::HP_GAUGE(GAME*game):
    GAME_OBJECT(game){ 
}
void HP_GAUGE::create() {
    HpGauge = game()->container()->data()->hpGauge;
}
void HP_GAUGE::draw(const VECTOR2& pos, const VECTOR2& offset, int hp ) {
    noStroke();
    if (hp > 1) {
        fill(HpGauge.color);
    }
    else {
        fill(HpGauge.danger);
    }
    rect(pos.x + offset.x, pos.y + offset.y, 
        hp * HpGauge.coWidth, HpGauge.h);
}
