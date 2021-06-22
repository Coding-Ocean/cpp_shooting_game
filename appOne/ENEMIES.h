#pragma once
#include"FLOAT2.h"
#include"CHARACTER.h"
class ENEMIES : public CHARACTER
{
private:
    //�G�f�[�^
    int Img = 0;
    struct ENEMY {
        FLOAT2 pos;
        float angle = 0;
        int hp = 0;
        float ofstTheta = 0;//�ʒu���ߗp�p�̑傫��
        float triggerElapsedTime = 0;//���ˌo�ߎ���
        float invincibleTime = 0;//���G����
    };
    ENEMY* Enemies=0;
    int TotalNum = 0;
    int CurNum = 0;
    //�ʒu���ߗp�f�[�^
    float Cx = 0;
    float Cy = 0;
    float MajRadius = 0;
    float MinRadius = 0;
    float RefTheta = 0;
    //���ˊԊu����
    float TriggerInterval = 0;
    //�����蔻��p ���E�~(Bounding Circle)�̔��a
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

