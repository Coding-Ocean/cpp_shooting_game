#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include"STAGE_CLEAR.h"
STAGE_CLEAR::STAGE_CLEAR(class GAME* game) :
    SCENE(game) {
}
void STAGE_CLEAR::create() {
    Scene = game()->container()->data().stageClearScene;
    StageClear = game()->container()->data().stageClear;
}
void STAGE_CLEAR::init() {
    game()->player()->initForStageClear();

    int no = game()->stageNo();
    Scene.message.setEditString(StageClear.preMsg, no, StageClear.sufMsg);
    Scene.message.calcPosDispCenter();
    Scene.message.initFadeIn();
}
void STAGE_CLEAR::update() {
    game()->playerBullets()->update();
    game()->enemyBullets()->update();
    game()->explosions()->update();
    Scene.message.fadeIn();
}
void STAGE_CLEAR::draw() {
    clear(Scene.backColor);
    game()->draw();
    Scene.message.draw();
}
void STAGE_CLEAR::nextScene(){
    if (game()->nextKeyPushed()) {
        game()->changeScene(GAME::STAGE_ID);
    }
}
