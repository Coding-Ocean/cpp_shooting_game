#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include"GAME_CLEAR.h"
GAME_CLEAR::GAME_CLEAR(class GAME* game) :
    GAME_STATE(game) {
}
GAME_CLEAR::~GAME_CLEAR() {
}
void GAME_CLEAR::create() {
    BackColor = game()->container()->data.stageBackColor;
}
void GAME_CLEAR::proc() {
    //update
    game()->playerBullets()->update();
    game()->enemyBullets()->update();
    //draw
    clear(60);
    game()->draw();
    float size = 200;
    textSize(size);
    fill(250, 250, 0);
    text("Game Clear", (width - size / 2 * 10) / 2, 400);
    //next sequence
    if (isTrigger(KEY_ENTER)) {
        game()->changeGameState(GAME::STATE_TITLE);
    }
}
