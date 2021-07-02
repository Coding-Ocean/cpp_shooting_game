#include"libOne.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"PLAYER.h"
#include "TITLE.h"
TITLE::TITLE(class GAME* game)
    :SCENE(game){
}
void TITLE::create() {
    Scene = game()->container()->title();
}
void TITLE::init() {
    game()->player()->init();
}
void TITLE::draw() {
    clear(Scene.backColor);
    SCENE::draw();
    game()->player()->draw();
}
void TITLE::nextScene(){
    if (isTrigger(KEY_J)) {
        game()->changeScene(GAME::STAGE_ID);
    }
}
