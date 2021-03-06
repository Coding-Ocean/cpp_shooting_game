#pragma once
#include"GAME_OBJECT.h"
#include"VECTOR2.h"
class ENEMIES : 
    public GAME_OBJECT
{
public:
    struct DATA {
        int img = 0;
        int totalNum = 0;
        int hp = 0;
        int curNum = 0;//----init
        //位置決め用データ
        VECTOR2 centerPos;//---init
        float fallSpeedY = 0;
        float arrivalY = 0;
        float majRadius = 0;
        float minRadius = 0;
        float refTheta = 0;
        float refThetaSpeed = 0;
        //発射間隔時間
        float triggerInterval = 0;
        //当たり判定用 境界円(Bounding Circle)の半径
        float bcRadius = 0;
        float invincibleTime = 0;
        COLOR collisionColor;
        COLOR normalColor;
        VECTOR2 hpGaugeOffset;
    };
private:
    //敵共通データ
    DATA Enemy;
    //敵単体データ配列
    struct ENEMY {
        VECTOR2 pos;
        float angle = 0;
        int hp = 0;
        float ofstTheta = 0;//位置決め用角の大きさ
        float triggerElapsedTime = 0;//発射経過時間
        float invincibleRestTime = 0;//無敵残り時間
        COLOR color;
    }* Enemies=0;
public:
    ENEMIES(class GAME* game);
    ~ENEMIES();
    void create();
    void init();
    void update();
        void move();
        void launch();
        void collision();
    void draw();
    //getter
    int curNum() { return Enemy.curNum; }
};
