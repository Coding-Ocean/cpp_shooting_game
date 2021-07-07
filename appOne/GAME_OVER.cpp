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
    Scene.textColor.a = 0;
}
void GAME_OVER::update() {
    game()->playerBullets()->update();
    game()->enemyBullets()->update();
    game()->explosions()->update();
    game()->enemies()->update();
    game()->player()->updateForGameOver();
    if (Scene.textColor.a < 255) {
        Scene.textColor.a += Scene.transSpeed * delta;
    }
}
void GAME_OVER::draw() {
    clear(Scene.backColor);
    game()->draw();
    SCENE::draw();
}
void GAME_OVER::nextScene() {
    if (game()->nextKeyPushed()) {
        game()->changeScene(GAME::TITLE_ID);
    }
}
