#pragma once
#include"FLOAT2.h"
class ENEMIES
{
private:
    struct ENEMY {
        FLOAT2 pos;
        float angle = 0;
    };
    ENEMY* Enemies=0;
    float Theta = 0;
    int Img = 0;
    int Num = 0;

    //位置決め用データ
    float DivTheta = 0;
    float Cx = 0;
    float Cy = 0;
    float Radius = 0;

    //launch bullet
    int TriggerCnt = 0;
    int TriggerInterval = 0;

public:
    ENEMIES();
    ~ENEMIES();
    void create(int img);
    void destroy();
    void init(class GAME* game);
    void move();
    void launch(class BULLETS* bullets, const FLOAT2& target);
    void draw();
    int num() { return Num; }
    FLOAT2 pos(int i) { return Enemies[i].pos; }
};

