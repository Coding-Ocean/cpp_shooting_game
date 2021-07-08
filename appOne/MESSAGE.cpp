#include "graphic.h"
#include "window.h"
#include "MESSAGE.h"
//文字列を中央に表示するための座標計算
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
void MESSAGE::setEditString(const char* preMsg, int n, const char* sufMsg) {
    int n10 = n / 10;//10の位
    int n1 = n - n10 * 10;//1の位
    //数値を全角の数字に変換
    char ws[24] = "０一二三四五六七八九";
    char no[8] = { '\0' };
    if (n10 == 0) {
        no[0] = ws[n1 * 2];
        no[1] = ws[n1 * 2 + 1];
    }
    else {
        no[0] = ws[n10 * 2];
        no[1] = ws[n10 * 2 + 1];
        no[2] = ws[n1 * 2];
        no[3] = ws[n1 * 2 + 1];
    }
    //残りステージ数の前後に文字列をくっつけて編集
    sprintf_s(String, "%s%s%s", preMsg, no, sufMsg);
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
