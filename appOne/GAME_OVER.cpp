#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include"ENEMIES.h"
#include "GAME_OVER.h"
GAME_OVER::GAME_OVER(class GAME* game)
    :SCENE(game) {
}
void GAME_OVER::create() {
    Scene = game()->container()->data().gameOverScene;
}
void GAME_OVER::init() {
    game()->player()->initForGameOver();
    Scene.message.initFadeIn();
}
void GAME_OVER::update() {
    game()->playerBullets()->update();
    game()->enemyBullets()->update();
    game()->explosions()->update();
    game()->enemies()->update();
    game()->player()->updateForGameOver();
    Scene.message.fadeIn();
}
void GAME_OVER::draw() {
    clear(Scene.backColor);
    game()->draw();
    Scene.message.draw();
}
void GAME_OVER::nextScene() {
    if (game()->nextKeyPushed()) {
        game()->changeScene(GAME::TITLE_ID);
    }
}
