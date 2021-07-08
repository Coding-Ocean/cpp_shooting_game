#pragma once
#include "GAME_OBJECT.h"
#include "VECTOR2.h"
class EXPLOSIONS :
    public GAME_OBJECT
{
public:
    //���L�f�[�^
    struct DATA {
        int totalNum = 0;
        int curNum = 0;
        int numImgs = 0;
        int* imgs = 0;
        float scale = 0;
        COLOR color;
        //�摜�؂�ւ��Ԋu
        float interval = 0;
        int startIdx = 0;
    };
private:
    DATA Explosion;
    //�ʃf�[�^
    struct EXPLOSION {
        VECTOR2 pos;
        int idx=0;
        float angle = 0;
        float elapsedTime=0;
    };
    EXPLOSION* Explosions;
public:
    EXPLOSIONS(class GAME* game);
    ~EXPLOSIONS();
    void create();
    void init();
    void trigger(const VECTOR2& pos);
    void update();
    void draw();
};

