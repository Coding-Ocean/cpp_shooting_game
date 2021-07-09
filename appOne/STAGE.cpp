#include"graphic.h"
#include"CONTAINER.h"
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMIES.h"
#include"ENEMY_BULLETS.h"
#include"GAME.h"
#include"STAGE.h"
STAGE::STAGE(class GAME* game)
    :SCENE(game) {
}
STAGE::~STAGE() {
}
void STAGE::create() {
    Scene = game()->container()->data().stageScene;
    Stage = game()->container()->data().stage;
    Stage.initNo = Stage.no;
}
void STAGE::init() {
    game()->player()->init();
    game()->enemies()->init();
    game()->playerBullets()->init();
    game()->enemyBullets()->init();
    game()->explosions()->init();
    if (Stage.no >= Stage.num) {
        Scene.message.last();
    }
    else {
        int no = Stage.num - Stage.no + 1;
        Scene.message.edit(no);
    }
    Scene.message.calcPosDispCenter();
    Scene.message.initFadeInOut();
}
void STAGE::update() {
    game()->playerBullets()->update();
    game()->enemyBullets()->update();
    game()->explosions()->update();
    game()->player()->update();
    game()->enemies()->update();
    Scene.message.fadeInOut();
}
void STAGE::draw() {
    clear(Scene.backColor);
    game()->draw();
    Scene.message.draw();
}
void STAGE::nextScene() {
    if (game()->enemies()->curNum() <= 0) {
        if (Stage.no >= Stage.num) {
            game()->changeScene(GAME::GAME_CLEAR_ID);
            Stage.no = Stage.initNo;
        }
        else {
            game()->changeScene(GAME::STAGE_CLEAR_ID);
            Stage.no++;
        }
    }
    else if (game()->player()->hp() <= 0) {
        game()->changeScene(GAME::GAME_OVER_ID);
        Stage.no = Stage.initNo;
    }
}
int STAGE::no() {
    return Stage.no;
}