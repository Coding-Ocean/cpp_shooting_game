#pragma once
#include"libOne.h"
class FLOAT2
{
public:
    float x, y;
    FLOAT2() : x(0) ,y(0) {
    }
    FLOAT2(float x, float y) {
        this->x = x;
        this->y = y;
    }
    FLOAT2 operator+(const FLOAT2& f2)const {
        return FLOAT2(x + f2.x, y + f2.y);
    }
    FLOAT2 operator-(const FLOAT2& f2)const {
        return FLOAT2(x - f2.x, y - f2.y);
    }
    FLOAT2 operator*(float f) const {
        return FLOAT2(x * f, y * f);
    }
    void operator+=(const FLOAT2& f2) {
        x += f2.x;
        y += f2.y;
    }
    FLOAT2 normalize() {
        float mag = sqrt(x * x + y * y);
        x /= mag;
        y /= mag;
        return FLOAT2(x, y);
    }
};


/*
“®‰æ‚Åà–¾‚µ‚½ƒo[ƒWƒ‡ƒ“
class FLOAT2 {
public:
    float x=0, y=0;
    FLOAT2(){
    }
    FLOAT2(float x, float y) {
        this->x = x;
        this->y = y;
    }
    FLOAT2 operator+(FLOAT2& f2) {
        return FLOAT2(x + f2.x, y + f2.y);
    }
    FLOAT2 operator-(FLOAT2& f2) {
        return FLOAT2(x - f2.x, y - f2.y);
    }
    FLOAT2 operator*(float f) {
        return FLOAT2(x * f, y * f);
    }
    void operator+=(const FLOAT2& f2) {
        x += f2.x;
        y += f2.y;
    }
    void normalize() {
        float mag = sqrt(x * x + y * y);
        x /= mag;
        y /= mag;
    }
};
*/


