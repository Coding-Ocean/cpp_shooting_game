#pragma once
#include"COLOR.h"
#include"VECTOR2.h"
class MESSAGE {
private:
    COLOR Color;
    float Size = 0;
    char String[20] = "";
    VECTOR2 Pos;
    //フェード
    float FadeInSpeed = 0;
    float FadeOutSpeed = 0;
    int FadeSw = 0;
    //移動
    float InitPosY = 0;
    float TargetPosY = 0;
    float VecY = 0;
    //STAGE,STAGE_CLEAR用
    char PreMsg[16];//prefix message
    char SufMsg[16];//suffix message
    char LastMsg[16];
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
    //STAGE,STAGE_CLEAR用
    void setPreMsg(const char*);
    void setSufMsg(const char*);
    void setLastMsg(const char*);
    void edit(int n);
    void last();
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

