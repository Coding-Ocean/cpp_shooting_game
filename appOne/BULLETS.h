#pragma once
#include"VECTOR2.h"
#include"GAME_OBJECT.h"
class BULLETS:
    public GAME_OBJECT
{
public:
    struct DATA {
        int img = 0;
        int totalNum = 0;
        int curNum = 0;
        float advSpeed = 0;
        float angSpeed = 0;
        float ofstLaunchDist = 0;
        float bcRadius = 0;
    };
private:
    //全ての弾の共通データ
    DATA Bullet;
    //弾単体データ配列
    struct BULLET {
        VECTOR2 pos;
        VECTOR2 vec;
        float angle;
    };
    BULLET* Bullets = 0;
protected:
    void SetBulletData(const DATA& data);
public:
    BULLETS(class GAME* game);
    virtual ~BULLETS();
    void init();
    void launch(const VECTOR2& pos, const VECTOR2& vec);
    void update();
    void draw();
    void kill(int i);
    //getter
    VECTOR2 pos(int i) { return Bullets[i].pos; }
    int curNum() { return Bullet.curNum; }
    float bcRadius() { return Bullet.bcRadius; }
};
