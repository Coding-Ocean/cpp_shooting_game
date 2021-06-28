#pragma once
#include"VECTOR2.h"
#include"CHARACTER.h"
class BULLETS:public CHARACTER{
public:
    struct DATA {
        int totalNum = 0;
        int curNum = 0;
        float advSpeed = 0;
        float angSpeed = 0;
        float ofstLaunchDist = 0;
        float bcRadius = 0;
    };
protected:
    //全ての弾の共通データ
    struct DATA Bullet;
    int Img = 0;
    //弾単体データ
    struct BULLET {
        VECTOR2 pos, vec;
        float angle;
    };
    BULLET* Bullets = nullptr;
    void AllocateBullets(int Num);
public:
    BULLETS(class GAME* game);
    virtual ~BULLETS();
    void init();
    void launch(const VECTOR2& pos, const VECTOR2& vec);
    void update();
    void draw();
    VECTOR2 pos(int i);
    int curNum();
    void kill(int i);
    float bcRadius();
};

