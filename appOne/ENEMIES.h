#pragma once
#include"GAME_OBJECT.h"
#include"HP_GAUGE.h"
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
        //�ʒu���ߗp�f�[�^
        VECTOR2 centerPos;//---init
        float fallSpeedY = 0;
        float arrivalY = 0;
        float majRadius = 0;
        float minRadius = 0;
        float refTheta = 0;
        float refThetaSpeed = 0;
        //���ˊԊu����
        float triggerInterval = 0;
        //�����蔻��p ���E�~(Bounding Circle)�̔��a
        float bcRadius = 0;
        float invincibleTime = 0;
        COLOR collisionColor;
        COLOR normalColor;
        VECTOR2 hpGaugeOffset;
    };
private:
    //�G���ʃf�[�^
    DATA Enemy;
    HP_GAUGE HpGauge;
    //�G�P�̃f�[�^�z��
    struct ENEMY {
        VECTOR2 pos;
        float angle = 0;
        int hp = 0;
        float ofstTheta = 0;//�ʒu���ߗp�p�̑傫��
        float triggerElapsedTime = 0;//���ˌo�ߎ���
        float invincibleRestTime = 0;//���G�c�莞��
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
        void kill(int i);
    void draw();
    int curNum() { return Enemy.curNum; }
    VECTOR2 pos(int i) { return Enemies[i].pos; }
};

