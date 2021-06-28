#pragma once
#include"VECTOR2.h"
#include"CHARACTER.h"
class ENEMIES : public CHARACTER
{
public:
    struct DATA {
        int hp = 0;
        float ofstTime = 0;
        int totalNum = 0;
        int curNum = 0;
        //位置決め用データ
        float centerX = 0;
        float centerY = 0;
        float majRadius = 0;
        float minRadius = 0;
        float refTheta = 0;
        //発射間隔時間
        float triggerInterval = 0;
        //当たり判定用 境界円(Bounding Circle)の半径
        float bcRadius = 0;
        float invincibleTime = 0;
    };
private:
    //敵共通データ
    int Img = 0;
    struct DATA Enemy;
    //敵単体データ
    struct ENEMY {
        VECTOR2 pos;
        float angle = 0;
        int hp = 0;
        float ofstTheta = 0;//位置決め用角の大きさ
        float triggerElapsedTime = 0;//発射経過時間
        float invincibleRestTime = 0;//無敵残り時間
    };
    ENEMY* Enemies=0;
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
    int curNum() { return Enemy.curNum; }
    VECTOR2 pos(int i) { return Enemies[i].pos; }
};

