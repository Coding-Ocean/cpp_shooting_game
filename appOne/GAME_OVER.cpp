#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include"ENEMIES.h"
//#include"PLAYER.h"
#include "GAME_OVER.h"
GAME_OVER::GAME_OVER(class GAME* game)
    :SCENE(game) {
}
GAME_OVER::~GAME_OVER() {
}
void GAME_OVER::create() {
    BackColor = game()->container()->data()->stageBackColor;
}
void GAME_OVER::update() {
    game()->playerBullets()->update();
    game()->enemyBullets()->update();
    game()->enemies()->move();
}
void GAME_OVER::draw() {
    clear(BackColor);
    game()->draw();
    float size = 200;
    textSize(size);
    fill(220, 0, 0);
    text("Game Over", (width - size / 2 * 9) / 2, 400);
}
void GAME_OVER::nextScene() {
    if (isTrigger(KEY_J)) {
        game()->changeScene(GAME::TITLE_ID);
    }
}
