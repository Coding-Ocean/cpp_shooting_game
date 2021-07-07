#include "graphic.h"
#include "window.h"
#include "MESSAGE.h"
//•¶Žš—ñ‚ð’†‰›‚É•\Ž¦‚·‚é‚½‚ß‚ÌÀ•WŒvŽZ
void MESSAGE::calcPosDispCenter() {
    size_t len = strlen(String);
    if (len > 0 && Size > 0) {
        Pos.x = (width - Size / 2 * len) / 2;
        Pos.y = (height - Size) / 2 - 100;
        TargetPosY = Pos.y;
    }
    else {
        Pos.x = 0;
        Pos.y = 0;
        TargetPosY = 0;
    }
}
void MESSAGE::setString(const char* str) {
    strcpy_s(String, str);
}

void MESSAGE::initFadeIn(){
    Color.a = 0;
}
int MESSAGE::fadeIn(){
    if (Color.a < 255) {
        Color.a += FadeInSpeed * delta;
        return 0;
    }
    return 1;
}
int MESSAGE::fadeOut() {
    if (Color.a > 0) {
        Color.a -= FadeOutSpeed * delta;
        return 0;
    }
    return 1;
}
void MESSAGE::initFadeInOut() {
    Color.a = 0;
    FadeSw = 0;
}
void MESSAGE::fadeInOut() {
    if (FadeSw == 0) {
        if (fadeIn()) {
            FadeSw = 1;
        }
    }
    else {
        fadeOut();
    }
}

void MESSAGE::initMove() {
    Pos.y = InitPosY;
}
void MESSAGE::move() {
    if (Pos.y > TargetPosY) {
        Pos.y += VecY * delta;
    }
}

void MESSAGE::draw() {
    if (Color.a > 0) {
        fill(Color);
        textSize(Size);
        textMode(TOP);
        text(String, Pos.x, Pos.y);
    }
}
