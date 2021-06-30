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
    BackColor = game()->container()->data()->stageBackColor;
}
void STAGE::init() {
    game()->player()->init();
    game()->enemies()->init();
    game()->playerBullets()->init();
    game()->enemyBullets()->init();
}
void STAGE::update() {
    game()->playerBullets()->update();
    game()->enemyBullets()->update();
    game()->player()->update();
    game()->enemies()->update();
}
void STAGE::draw() {
    clear(BackColor);
    game()->draw();
}
void STAGE::nextScene() {
    if (game()->enemies()->curNum() <= 0) {
        game()->changeScene(GAME::GAME_CLEAR_ID);
        game()->stageCntUp();
    }
    else if (game()->player()->hp() <= 0) {
        game()->changeScene(GAME::GAME_OVER_ID);
        game()->resetStageCnt();
    }
}