#include"libOne.h"
#include"GAME.h"
#include "TITLE.h"
TITLE::TITLE(class GAME* game)
    :GAME_STATE(game){
}
TITLE::~TITLE() {
}
void TITLE::init() {
}
void TITLE::proc() {
    clear();
    printSize(780);
    print("TITLE");
    if (isTrigger(KEY_SPACE)) {
        game()->changeGameState(GAME::STATE_PLAY);
    }
}
