#include"libOne.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"PLAYER.h"
#include "TITLE.h"
TITLE::TITLE(class GAME* game)
    :SCENE(game){
}
TITLE::~TITLE() {
}
void TITLE::create() {
    Title = game()->container()->data()->title;
}
void TITLE::init() {
    game()->player()->initForTitle();
}
void TITLE::draw() {
    clear(Title.backColor);
    fill(Title.textColor);
    textSize(Title.textSize);
    text(Title.string, Title.px, Title.py);
    game()->player()->draw();
}
void TITLE::nextScene(){
    if (isTrigger(KEY_J)) {
        game()->changeScene(GAME::STAGE_ID);
    }
}
