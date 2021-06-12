#pragma once
#include "CHARACTER.h"
class PLAYER :
    public CHARACTER
{
private:
    int Img;
    float Angle, Vx, Vy, AngSpeed, AdvSpeed;
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
    float cpx(int i);
    float cpy(int i);
};

