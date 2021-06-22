#pragma once
#include"FLOAT2.h"
#include"CHARACTER.h"
class BULLETS:public CHARACTER{
protected:
    struct BULLET {
        FLOAT2 pos, vec;
        float angle;
    };
    BULLET* Bullets = nullptr;
    int Img = 0;
    int TotalNum = 0;
    int CurNum = 0;
    float AdvSpeed = 0;
    float AngSpeed = 0;
    float OfstLaunchDist = 0;
    void SetTotalNum(int num);
    float BCRadius = 0;
public:
    BULLETS(class GAME* game);
    virtual ~BULLETS();
    void init();
    void launch(const FLOAT2& pos, const FLOAT2& vec);
    void update();
    void draw();
    FLOAT2 pos(int i);
    int curNum();
    void kill(int i);
    float bcRadius();
};

