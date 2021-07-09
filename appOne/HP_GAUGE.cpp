#include"graphic.h"
#include"CONTAINER.h"
#include"GAME.h"
#include "HP_GAUGE.h"
HP_GAUGE::HP_GAUGE(GAME*game):
    GAME_OBJECT(game){ 
}
void HP_GAUGE::create() {
    HpGauge = game()->container()->data().hpGauge;
}
void HP_GAUGE::draw() {
    noStroke();
    if (HpGauge.hp > HpGauge.warningHp) {
        fill(HpGauge.green);
    }
    else if (HpGauge.hp > HpGauge.dangerHp) {
        fill(HpGauge.yellow);
    }
    else {
        fill(HpGauge.red);
    }
    rect(HpGauge.pos.x, HpGauge.pos.y,
        HpGauge.hp * HpGauge.coWidth, HpGauge.hi);
}
