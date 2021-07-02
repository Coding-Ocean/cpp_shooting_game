#include"libOne.h"
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
    Scene = game()->container()->data()->stageScene;
    Stage = game()->container()->data()->stage;
}
void STAGE::init() {
    game()->player()->init();
    game()->enemies()->init();
    game()->playerBullets()->init();
    game()->enemyBullets()->init();
    Scene.textColor.a = game()->container()->data()->stageScene.textColor.a;
    if (Stage.stageCnt >= Stage.stageNum) {
        strcpy_s(Scene.string, "最後のステージ");
    }
    else {
        sprintf_s(Scene.string,"あと %d ステージ",
            Stage.stageNum - Stage.stageCnt + 1);
    }
    Scene.pos = game()->container()->calcPos(Scene.string, Scene.textSize);
}
void STAGE::update() {
    game()->playerBullets()->update();
    game()->enemyBullets()->update();
    game()->player()->update();
    game()->enemies()->update();
}
void STAGE::draw() {
    clear(Scene.backColor);
    game()->draw();
    if (Scene.textColor.a >= 0) {
        SCENE::draw();
        Scene.textColor.a -= Scene.transSpeed * delta;
    }
}
void STAGE::nextScene() {
    if (game()->enemies()->curNum() <= 0) {
        if (Stage.stageCnt >= Stage.stageNum) {
            game()->changeScene(GAME::GAME_CLEAR_ID);
            Stage.stageCnt = game()->container()->data()->stage.stageCnt;
        }
        else {
            game()->changeScene(GAME::STAGE_CLEAR_ID);
            Stage.stageCnt++;
        }
    }
    else if (game()->player()->hp() <= 0) {
        game()->changeScene(GAME::GAME_OVER_ID);
        Stage.stageCnt = game()->container()->data()->stage.stageCnt;
    }
}
int STAGE::stageCnt() {
    return Stage.stageCnt;
}