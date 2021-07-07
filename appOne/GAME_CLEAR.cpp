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
    Scene = game()->container()->gameClearScene();
}
void GAME_CLEAR::init() {
    game()->player()->initForGameClear();
    Scene.pos.y = height;
}
void GAME_CLEAR::update() {
    game()->playerBullets()->update();
    game()->enemyBullets()->update();
    game()->explosions()->update();
    game()->player()->updateForGameClear();
    if (Scene.pos.y > (height - Scene.textSize) / 2) {
        Scene.pos += Scene.vec * delta;
    }
}
void GAME_CLEAR::draw() {
    clear(Scene.backColor);
    game()->draw();
    SCENE::draw();
}
void GAME_CLEAR::nextScene(){
    if (game()->nextKeyPushed()) {
        game()->changeScene(GAME::TITLE_ID);
    }
}
