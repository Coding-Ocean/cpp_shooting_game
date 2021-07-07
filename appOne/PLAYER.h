#pragma once
#include"GAME_OBJECT.h"
#include"VECTOR2.h"
class PLAYER
    : public GAME_OBJECT
{
public:
    struct DATA {
        int img = 0;
        VECTOR2 pos;
        float angle = 0;
        float advSpeed = 0;
        float limmitRange = 0;
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
        COLOR color;
        int hp = 0;
        VECTOR2 hpGaugeOffset;
        //others
        VECTOR2 posForTitle;
        //game clear
        float standingRestTime = 0;
        float standingTime = 0;
        float angSpeed = 0;
        VECTOR2 lastPos;
        float launchAngle = 0;
        float launchAngleSpeed = 0;
        float triggerInterval2 = 0;//���ˊԊu����
        //game over
        float fallSpeed=0;
        float fallLimmit = 0;
        float rollingSpeed = 0;
        float rollingLimmit = 0;
        float changeRedColorSpeed = 0;
        float changeGreenColorSpeed = 0;
    };
private:
    DATA Player;
public:
    PLAYER(class GAME* game);
    ~PLAYER();
    void create();
    //stage
    void init();
    void update();
        void move();
        void launch();
        void collision();
    void draw();
    //title
    void initForTitle();
    //stage clear
    void initForStageClear();
    //game clear
    void initForGameClear();
    void updateForGameClear();
    //game over
    void initForGameOver();
    void updateForGameOver();
    //getter
    VECTOR2 pos() { return Player.pos; }
    int hp() { return Player.hp; }
};

