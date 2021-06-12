#include"libOne.h"
#include"GAME.h"
#include"PLAYER.h"
#include "OVER.h"
void OVER::init(class GAME* game) {
}
void OVER::proc(class GAME* game) {
    clear(230, 40, 150);
    game->draw();
    float size = 200;
    textSize(size);
    text("GameOver", (width-size/2*8)/2, 400);
    if (isTrigger(KEY_SPACE)) {
        game->changeGameState(GAME_STATE::ID::TITLE);
    }
}
