#pragma once
#include"FLOAT2.h"
#include"CHARACTER.h"
class PLAYER 
    : public CHARACTER
{
private:
    int Img = 0;
    FLOAT2 Pos;
    FLOAT2 Dir;//プレイヤの向いている方向ベクトル
    float Angle = 0, AngSpeed = 0, AdvSpeed = 0;
    int MoveMode = 0;
    int Hp = 0;
    //launch bullet
    float TriggerElapsedTime = 0;
    float TriggerInterval = 0;
    //collision
    float InvincibleTime = 0;
    float BCRadius=0;
public:
    PLAYER(class GAME* game);
    ~PLAYER();
    void create();
    void init();
    void update();
    void move();
    void rotate();
    void launch();
    void collision();
    void draw();
    FLOAT2 pos() { return Pos; }
    int hp();
    void initForTitle();
};

