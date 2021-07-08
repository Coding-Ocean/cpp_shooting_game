#pragma once
#include"COLOR.h"
#include"VECTOR2.h"
class MESSAGE {
private:
    COLOR Color;
    float Size = 0;
    char String[20] = "";
    VECTOR2 Pos;
    //•Ï‰»
    float FadeInSpeed = 0;
    float FadeOutSpeed = 0;
    int FadeSw = 0;
    float InitPosY = 0;
    float TargetPosY = 0;
    float VecY = 0;
public:
    void calcPosDispCenter();
    void setString(const char* str);
    void setColor(const COLOR& color) { Color = color; }
    void setSize(float size) { Size = size; }
    void setFadeInSpeed(float fadeInSpeed) { FadeInSpeed = fadeInSpeed; }
    void setFadeOutSpeed(float fadeOutSpeed) { FadeOutSpeed = fadeOutSpeed; }
    void setFadeSw(int fadeSw) { FadeSw = fadeSw; }
    void setInitPosY(float y) { InitPosY = y; }
    void setTargetPosY(float y) { TargetPosY = y; }
    void setVecY(float y) { VecY = y; }
    void setEditString(const char* preMsg, int n, const char* sufMsg);
    //fade
    void initFadeIn();
    int fadeIn();
    int fadeOut();
    void initFadeInOut();
    void fadeInOut();
    //move
    void initMove();
    void move();
    //draw
    void draw();
};

