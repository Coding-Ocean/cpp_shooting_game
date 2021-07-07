#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include"GAME_CLEAR.h"
GAME_CLEAR::GAME_CLEAR(class GAME* game) :
    SCENE(game) {
}
void GAME_CLEAR::create() {
    Scene = game()->container()->data().gameClearScene;
}
void GAME_CLEAR::init() {
    game()->player()->initForGameClear();
    Scene.message.initMove();
}
void GAME_CLEAR::update() {
    game()->playerBullets()->update();
    game()->enemyBullets()->update();
    game()->explosions()->update();
    game()->player()->updateForGameClear();
    Scene.message.move();
}
void GAME_CLEAR::draw() {
    clear(Scene.backColor);
    game()->draw();
    Scene.message.draw();
}
void GAME_CLEAR::nextScene(){
    if (game()->nextKeyPushed()) {
        game()->changeScene(GAME::TITLE_ID);
    }
}
