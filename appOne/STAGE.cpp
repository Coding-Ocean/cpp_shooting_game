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
    //ƒXƒ^[ƒgƒƒbƒZ[ƒW‚Ì•ÒW
    if (Stage.stageNo >= Stage.stageNum) {
        Scene.message.setString(Stage.startMsg2);
    }
    else {
        //Žc‚èƒXƒe[ƒW”‚ð‘SŠp‚Ì”Žš‚É•ÏŠ·
        int i = Stage.stageNum - Stage.stageNo + 1;
        char ws[24]="‚O‚P‚Q‚R‚S‚T‚U‚V‚W‚X";
        char s[4] = { ws[i * 2], ws[i * 2 + 1],'\0' };
        //•ÒW
        char buf[24];
        sprintf_s(buf, "%s%s%s", Stage.startPreMsg1, s, Stage.startMsg1);
        Scene.message.setString(buf);
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