#pragma once
#include"VECTOR2.h"
#include"CHARACTER.h"
class PLAYER 
    : public CHARACTER
{
public:
    struct DATA {
        VECTOR2 pos;
        float advSpeed = 0;
        float angle = 0;
        int hp = 0;
        //launch bullet
        VECTOR2 launchVec;//���˕���
        float triggerElapsedTime = 0;//���ˌ�o�ߎ���
        float triggerInterval = 0;//���ˊԊu����
        //collision
        float invincibleTime = 0;//���G����
        float invincibleRestTime = 0;//���G�c�莞��
        float bcRadius = 0;//�Փ˔���p�~���a
    };
private:
    int Img = 0;
    struct DATA Player;
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
    //
    void initForTitle();
    //getter
    VECTOR2 pos() { return Player.pos; }
    int hp() { return Player.hp; }
};

