#pragma once
#include"FLOAT2.h"
#include"CHARACTER.h"
class ENEMIES : public CHARACTER
{
private:
    int Img = 0;
    int Num = 0;
    struct ENEMY {
        FLOAT2 pos;
        float angle = 0;
        int hp = 0;
    };
    ENEMY* Enemies=0;

    //位置決め用データ
    float DivTheta = 0;
    float Cx = 0;
    float Cy = 0;
    float Radius = 0;
    float Theta = 0;

    //launch bullet
    int TriggerCnt = 0;
    int TriggerInterval = 0;

public:
    ENEMIES(class GAME* game);
    ~ENEMIES();
    void create();
    void destroy();
    void prepare();
    void start();
    void move();
    void launch();
    void collision();
    void isDrawn();
    int num() { return Num; }
    FLOAT2 pos(int i) { return Enemies[i].pos; }
};

