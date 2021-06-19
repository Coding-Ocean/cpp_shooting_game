#pragma once
#include"FLOAT2.h"
#include"CHARACTER.h"
class PLAYER 
    : public CHARACTER
{
private:
    int Img = 0;
    FLOAT2 Pos;
    FLOAT2 Vec;//プレイヤの向いている方向ベクトル
    float Angle = 0, AngSpeed = 0, AdvSpeed = 0;
    int MoveMode = 0;
    //launch bullet
    int TriggerCnt = 0;
    int TriggerInterval = 0;
    //collision
    float CollisionOffset = 0;
    int ColCnt = 0;
public:
    PLAYER(class GAME* game);
    ~PLAYER();
    void initOnce();
    void init();
    void update();
    void moveLeftRight();
    void rotate();
    void launch();
    void collision();
    void draw();
    FLOAT2 pos() { return Pos; }
    float cpx(int i);
    float cpy(int i);
};

