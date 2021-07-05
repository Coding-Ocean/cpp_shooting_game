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
    Scene = game()->container()->gameOverScene();
}
void GAME_OVER::init() {
    game()->player()->initForGameOver();
}
void GAME_OVER::update() {
    game()->playerBullets()->update();
    game()->enemyBullets()->update();
    game()->enemies()->update();
    game()->player()->updateForGameOver();
}
void GAME_OVER::draw() {
    clear(Scene.backColor);
    game()->draw();
    SCENE::draw();
}
void GAME_OVER::nextScene() {
    if (isTrigger(KEY_J)) {
        game()->changeScene(GAME::TITLE_ID);
    }
}
