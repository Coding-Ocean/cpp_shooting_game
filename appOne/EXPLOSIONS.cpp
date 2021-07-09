#include"common.h"
#include"rand.h"
#include"window.h"
#include"graphic.h"
#include"GAME.h"
#include"CONTAINER.h"
#include "EXPLOSIONS.h"
EXPLOSIONS::EXPLOSIONS(class GAME* game):
GAME_OBJECT(game){
}
EXPLOSIONS::~EXPLOSIONS(){
    SAFE_DELETE_ARRAY(Explosions);
}
void EXPLOSIONS::create(){
    Explosion = game()->container()->data().explosion;
    Explosions = new EXPLOSION[Explosion.totalNum];
}
void EXPLOSIONS::init(){
    Explosion.curNum = 0;
}
void EXPLOSIONS::trigger(const VECTOR2& pos){
    if (Explosion.curNum < Explosion.totalNum) {
        int i = Explosion.curNum;
        Explosions[i].pos = pos;
        Explosions[i].idx = Explosion.startIdx;
        Explosions[i].elapsedTime = 0;
        Explosions[i].angle = float(random() % 7);
        Explosion.curNum++;
    }
}
void EXPLOSIONS::update(){
    //Explosion.intervalŽžŠÔŒo‰ß‚µ‚½‚ç
    //Explosions[i].idx‚ðŽŸ‚Ì‰æ‘œ‚ÉØ‚è‘Ö‚¦‚é
    //ÅŒã‚Ü‚Å•\Ž¦‚µ‚Ä‚¢‚½‚çÁ‚·
    for (int i = Explosion.curNum - 1; i >= 0; i--) {
        Explosions[i].elapsedTime += delta;
        if (Explosions[i].elapsedTime > Explosion.interval) {
            Explosions[i].idx++;
            Explosions[i].elapsedTime -= Explosion.interval;
            if (Explosions[i].idx >= Explosion.numImgs) {
                Explosion.curNum--;
                Explosions[i] = Explosions[Explosion.curNum];
            }
        }
    }
}
void EXPLOSIONS::draw(){
    imageColor(Explosion.color);
    for (int i = 0; i < Explosion.curNum; i++) {
        int idx = Explosions[i].idx;
        image(Explosion.imgs[idx], Explosions[i].pos.x, Explosions[i].pos.y,
            Explosions[i].angle, Explosion.scale);
    }
}
