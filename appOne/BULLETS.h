#pragma once
#include"FLOAT2.h"
class BULLETS{
protected:
    struct BULLET {
        FLOAT2 pos, vec;
        float angle;
        int hp;
    };
    BULLET* Bullets = nullptr;
    int Img = 0;
    int Num = 0;
    float AdvSpeed = 0;
    float AngSpeed = 0;
    float OfstLaunchDist = 0;
    void AllocateMemory();
public:
    BULLETS();
    virtual ~BULLETS();
    virtual void create(int img) = 0;
    void init(class GAME* game);
    void launch(const FLOAT2& pos, const FLOAT2& vec);
    void move();
    void draw();
};

