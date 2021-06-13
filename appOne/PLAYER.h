#pragma once
#include"FLOAT2.h"
class PLAYER
{
private:
    int Img;
    FLOAT2 Pos;
    FLOAT2 Vec;
    float Angle, AngSpeed, AdvSpeed;
    //launch bullet
    int TriggerCnt;
    int TriggerInterval;
    //collision
    float CollisionOffset = 0;
public:
    void create(int img);
    void init(class GAME* game);
    void move();
    void launch(class BULLETS* bullets);
    void draw();
    FLOAT2 pos() { return Pos; }
    float cpx(int i);
    float cpy(int i);
};

