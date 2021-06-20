#include"libOne.h"
#include"GAME.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include"CLEAR.h"
CLEAR::CLEAR(class GAME* game) :
    GAME_STATE(game) {
}
CLEAR::~CLEAR() {
}
void CLEAR::init() {
}
void CLEAR::proc() {
    game()->playerBullets()->update();
    game()->enemyBullets()->update();
    clear(60);
    game()->draw();
    float size = 200;
    textSize(size);
    fill(250, 250, 0);
    text("GameClear", (width - size / 2 * 9) / 2, 400);
    if (isTrigger(KEY_ENTER)) {
        game()->changeGameState(GAME::STATE_TITLE);
    }
}
