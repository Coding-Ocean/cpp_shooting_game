#pragma once
#include"FLOAT2.h"
#include"CHARACTER.h"
class ENEMIES : public CHARACTER
{
private:
    //敵データ
    int Img = 0;
    struct ENEMY {
        FLOAT2 pos;
        float angle = 0;
        int hp = 0;
        float ofstTheta = 0;//位置決め用角の大きさ
        float triggerElapsedTime = 0;//発射経過時間
        float invincibleTime = 0;//無敵時間
    };
    ENEMY* Enemies=0;
    int TotalNum = 0;
    int CurNum = 0;
    //位置決め用データ
    float Cx = 0;
    float Cy = 0;
    float MajRadius = 0;
    float MinRadius = 0;
    float RefTheta = 0;
    //発射間隔時間
    float TriggerInterval = 0;
    //当たり判定用 境界円(Bounding Circle)の半径
    float BCRadius = 0;
    float SqDistance = 0;
public:
    ENEMIES(class GAME* game);
    ~ENEMIES();
    void destroy();
    void create();
    void init();
    void update();
    void move();
    void launch();
    void collision();
    void draw();
    int curNum() { return CurNum; }
    FLOAT2 pos(int i) { return Enemies[i].pos; }
};

