#include"libOne.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"PLAYER.h"
#include "TITLE.h"
TITLE::TITLE(class GAME* game)
    :GAME_STATE(game){
}
TITLE::~TITLE() {
}
void TITLE::create() {
    Data = game()->container()->data.title;
    String = game()->container()->titleString;
}
void TITLE::init() {
    game()->player()->initForTitle();
}
void TITLE::proc() {
    //Draw
    clear(Data.backColor);
    fill(Data.textColor);
    textSize(Data.textSize);
    text(String.c_str(), Data.px, Data.py);
    game()->player()->draw();
    //Next Sequaence
    if (isTrigger(KEY_ENTER)) {
        game()->changeGameState(GAME::STATE_STAGE);
    }
}
