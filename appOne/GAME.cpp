//�R���e�i
#include"CONTAINER.h"
//�V�[�P���X
#include"TITLE.h"
#include"STAGE.h"
#include"STAGE_CLEAR.h"
#include"GAME_CLEAR.h"
#include"GAME_OVER.h"
//�L�����N�^
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMIES.h"
#include"ENEMY_BULLETS.h"
#include"HP_GAUGE.h"
#include"EXPLOSIONS.h"
//�Q�[���}�l�[�W���[
#include "GAME.h"
GAME::GAME() {
    //�R���e�i
    Container = new CONTAINER;
    //�V�[�P���X
    Scenes[TITLE_ID] = new TITLE(this);
    Scenes[STAGE_ID] = new STAGE(this);
    Scenes[STAGE_CLEAR_ID] = new STAGE_CLEAR(this);
    Scenes[GAME_CLEAR_ID] = new GAME_CLEAR(this);
    Scenes[GAME_OVER_ID] = new GAME_OVER(this);
    //�L�����N�^
    Player = new PLAYER(this);
    Enemies = new ENEMIES(this);
    PlayerBullets = new PLAYER_BULLETS(this);
    EnemyBullets = new ENEMY_BULLETS(this);
    HpGauge = new HP_GAUGE(this);
    Explosions = new EXPLOSIONS(this);
}
GAME::~GAME() {
    //�L�����N�^
    SAFE_DELETE(Explosions);
    SAFE_DELETE(HpGauge);
    SAFE_DELETE(EnemyBullets);
    SAFE_DELETE(Enemies);
    SAFE_DELETE(PlayerBullets);
    SAFE_DELETE(Player);
    //�V�[�P���X
    for (int i = 0; i < STATE_NUM; i++) {
        SAFE_DELETE(Scenes[i]);
    }
    //�R���e�i
    SAFE_DELETE(Container);
}
void GAME::run() {
    window(1920, 1080, full);
    hideCursor();
    //�ǂݍ���
    Container->load();
    //�S�v�f������
    Game = Container->data().game;
    for (int i = 0; i < STATE_NUM; i++) {
        Scenes[i]->create();
    }
    Player->create();
    Enemies->create();
    PlayerBullets->create();
    EnemyBullets->create();
    HpGauge->create();
    Explosions->create();
    //�ŏ��̃X�e�[�g
    changeScene(Game.firstSceneId);
    initDeltaTime();
    //�Q�[�����[�v
    int max = 0;
    while (notQuit) {
        setDeltaTime();
        Scenes[CurSceneId]->proc();
        if (PlayerBullets->curNum() > max)max = PlayerBullets->curNum();
        print(max);
    }
}

//�ȉ��A���̃N���X����Ăяo����郁���o
//�@�V�[�P���X
void GAME::changeScene(SCENE_ID stateId) {
    CurSceneId = stateId;
    Scenes[CurSceneId]->init();
}
void GAME::draw() {
    Enemies->draw();
    Player->draw();
    PlayerBullets->draw();
    EnemyBullets->draw();
    Explosions->draw();
}
int GAME::stageNo() {
    //Enemies�̐����X�e�[�W�J�E���^�[�Ɠ����ɂ��邽�߂̃����o
    STAGE* stage = dynamic_cast<STAGE*>(Scenes[STAGE_ID]);
    return stage->stageNo();
}
int GAME::nextKeyPushed() {
    return isTrigger(Game.changeSceneKey);
}

