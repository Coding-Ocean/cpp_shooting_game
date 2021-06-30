#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include"GAME_CLEAR.h"
GAME_CLEAR::GAME_CLEAR(class GAME* game) :
    SCENE(game) {
}
GAME_CLEAR::~GAME_CLEAR() {
}
void GAME_CLEAR::create() {
    BackColor = game()->container()->data()->stageBackColor;
}
void GAME_CLEAR::update() {
    game()->playerBullets()->update();
    game()->enemyBullets()->update();
}
void GAME_CLEAR::draw() {
    clear(60);
    game()->draw();
    float size = 200;
    textSize(size);
    fill(250, 250, 0);
    text("Game Clear", (width - size / 2 * 10) / 2, 400);
}
void GAME_CLEAR::nextScene(){
    if (isTrigger(KEY_J)) {
        game()->changeScene(GAME::TITLE_ID);
    }
}
