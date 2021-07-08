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
    Stage.stageInitNo = Stage.stageNo;
}
void STAGE::init() {
    game()->player()->init();
    game()->enemies()->init();
    game()->playerBullets()->init();
    game()->enemyBullets()->init();
    game()->explosions()->init();
    //スタートメッセージの編集
    if (Stage.stageNo >= Stage.stageNum) {
        Scene.message.setString(Stage.lastMsg);
    }
    else {
        int no = Stage.stageNum - Stage.stageNo + 1;
        if (no >= 10) {
            Scene.message.setEditString(Stage.preMsg, no, "");
        }
        else {
            Scene.message.setEditString(Stage.preMsg, no, Stage.sufMsg);
        }
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
        if (Stage.stageNo >= Stage.stageNum) {
            game()->changeScene(GAME::GAME_CLEAR_ID);
            Stage.stageNo = Stage.stageInitNo;
        }
        else {
            game()->changeScene(GAME::STAGE_CLEAR_ID);
            Stage.stageNo++;
        }
    }
    else if (game()->player()->hp() <= 0) {
        game()->changeScene(GAME::GAME_OVER_ID);
        Stage.stageNo = Stage.stageInitNo;
    }
}
int STAGE::stageNo() {
    return Stage.stageNo;
}