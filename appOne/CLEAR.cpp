#include"libOne.h"
#include"GAME.h"
#include"PLAYER.h"
#include "CLEAR.h"
void CLEAR::init(class GAME* game) {
}
void CLEAR::proc(class GAME* game) {
    clear(230, 230, 40);
    game->draw();
    float size = 200;
    textSize(size);
    text("GameClear", (width - size / 2 * 9) / 2, 400);
    if (isTrigger(KEY_SPACE)) {
        game->changeGameState(GAME_STATE::ID::TITLE);
    }
}
