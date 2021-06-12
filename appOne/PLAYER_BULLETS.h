#pragma once
#include "BULLETS.h"
class PLAYER_BULLETS :
    public BULLETS
{
protected:
    struct BULLET {
        float px, py, angle, vx, vy;
        int hp;
    };
    int Num;
    BULLET* Bullets;
    int Img;
    float AdvSpeed;
    float AngSpeed;
    int OfstLaunchPos;
public:
    PLAYER_BULLETS();
    ~PLAYER_BULLETS();
    virtual void create(int img);
    void init(class GAME* game);
    void launch(float px, float py, float vx, float vy);
    void move();
    void draw();
};

