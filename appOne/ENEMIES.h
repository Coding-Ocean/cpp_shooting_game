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
        //�ʒu���ߗp�f�[�^
        float centerX = 0;
        float centerY = 0;
        float majRadius = 0;
        float minRadius = 0;
        float refTheta = 0;
        //���ˊԊu����
        float triggerInterval = 0;
        //�����蔻��p ���E�~(Bounding Circle)�̔��a
        float bcRadius = 0;
        float invincibleTime = 0;
    };
private:
    //�G���ʃf�[�^
    int Img = 0;
    struct DATA Enemy;
    //�G�P�̃f�[�^
    struct ENEMY {
        VECTOR2 pos;
        float angle = 0;
        int hp = 0;
        float ofstTheta = 0;//�ʒu���ߗp�p�̑傫��
        float triggerElapsedTime = 0;//���ˌo�ߎ���
        float invincibleRestTime = 0;//���G�c�莞��
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

