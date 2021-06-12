#include"libOne.h"
#include"GAME.h"
#include "TITLE.h"
void TITLE::init(class GAME* game) {
}
void TITLE::proc(class GAME* game) {
    clear();
    print("TITLE");
    if (isTrigger(KEY_SPACE)) {
        game->changeGameState(GAME_STATE::ID::PLAY);
    }
}
