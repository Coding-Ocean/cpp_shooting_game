#include"libOne.h"
#include"GAME.h"
#include"PLAYER.h"
#include "TITLE.h"
TITLE::TITLE(class GAME* game)
    :GAME_STATE(game){
}
TITLE::~TITLE() {
}
void TITLE::init() {
    game()->player()->init();
    game()->player()->setZeroHp();
}
void TITLE::proc() {
    clear();
    fill(0, 255, 0);
    printSize(500);
    print("KUNOICHI");
    game()->player()->draw();
    if (isTrigger(KEY_ENTER)) {
        game()->changeGameState(GAME::STATE_PLAY);
    }
}
