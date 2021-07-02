#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include"STAGE_CLEAR.h"
STAGE_CLEAR::STAGE_CLEAR(class GAME* game) :
    SCENE(game) {
}
void STAGE_CLEAR::create() {
    Scene = game()->container()->stageClear();
}
void STAGE_CLEAR::update() {
    game()->playerBullets()->update();
    game()->enemyBullets()->update();
}
void STAGE_CLEAR::draw() {
    clear(Scene.backColor);
    game()->draw();
    SCENE::draw();
}
void STAGE_CLEAR::nextScene(){
    if (isTrigger(KEY_J)) {
        game()->changeScene(GAME::STAGE_ID);
    }
}
