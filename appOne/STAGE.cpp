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
    Scene = game()->container()->stageScene();
    Stage = game()->container()->stage();
}
void STAGE::init() {
    game()->player()->init();
    game()->enemies()->init();
    game()->playerBullets()->init();
    game()->enemyBullets()->init();
    game()->explosions()->init();
    //ƒXƒ^[ƒgƒƒbƒZ[ƒW‚Ì•ÒW
    if (Stage.stageCnt >= Stage.stageNum) {
        strcpy_s(Scene.string, Stage.startMsg2);
    }
    else {
        //c‚èƒXƒe[ƒW‚Ì”‚ğ‘SŠp‚·‚é
        int i = Stage.stageNum - Stage.stageCnt + 1;
        char ws[24]="‚O‚P‚Q‚R‚S‚T‚U‚V‚W‚X";
        char s[4] = { ws[i * 2], ws[i * 2 + 1],'\0' };
        //•ÒW
        sprintf_s(Scene.string, "%s%s%s", Stage.startPreMsg1, s, Stage.startMsg1);
    }
    Scene.pos = game()->container()->calcPos(Scene.string, Scene.textSize);
    Scene.textColor.a = game()->container()->stageScene().textColor.a;
}
void STAGE::update() {
    game()->playerBullets()->update();
    game()->enemyBullets()->update();
    game()->explosions()->update();
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
            Stage.stageCnt = game()->container()->stage().stageCnt;
        }
        else {
            game()->changeScene(GAME::STAGE_CLEAR_ID);
            Stage.stageCnt++;
        }
    }
    else if (game()->player()->hp() <= 0) {
        game()->changeScene(GAME::GAME_OVER_ID);
        Stage.stageCnt = game()->container()->stage().stageCnt;
    }
}
int STAGE::stageCnt() {
    return Stage.stageCnt;
}