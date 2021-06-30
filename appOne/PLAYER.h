#pragma once
#include"GAME_OBJECT.h"
#include"VECTOR2.h"
#include"HP_GAUGE.h"
class PLAYER
    : public GAME_OBJECT
{
public:
    struct DATA {
        int img = 0;
        VECTOR2 pos;
        float angle = 0;
        float advSpeed = 0;
        //launch bullet
        VECTOR2 launchVec;//���˕���
        float triggerElapsedTime = 0;//���ˌ�o�ߎ���
        float triggerInterval = 0;//���ˊԊu����
        //collision
        float invincibleTime = 0;//���G����
        float invincibleRestTime = 0;//���G�c�莞��
        float bcRadius = 0;//�Փ˔���p�~���a
        COLOR collisionColor;
        COLOR normalColor;
        int hp = 0;
        VECTOR2 hpGaugeOffset;
        //others
        VECTOR2 posForTitle;
    };
private:
    DATA Player;
    HP_GAUGE HpGauge;
public:
    PLAYER(class GAME* game);
    ~PLAYER();
    void create();
    void init();
    void update();
        void move();
        void launch();
        void collision();
    void draw();
    //for title
    void initForTitle();
    //getter
    VECTOR2 pos() { return Player.pos; }
    int hp() { return Player.hp; }
};

