#include "MESSAGE.h"
#include "graphic.h"
void MESSAGE::create(){}
void MESSAGE::init(){}
void MESSAGE::update(){}
void MESSAGE::draw() {
    fill(color);
    textSize(size);
    textMode(TOP);
    text(string, pos.x, pos.y);
}
void MESSAGE::CalcPos() {
    size_t len = strlen(string);
    pos.x = (width - size / 2 * len) / 2;
    pos.y = (height - size) / 2 - 100;
}