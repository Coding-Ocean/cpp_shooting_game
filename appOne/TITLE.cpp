#include"graphic.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"PLAYER.h"
#include "TITLE.h"
TITLE::TITLE(class GAME* game)
    :SCENE(game){
}
void TITLE::create() {
    Scene = game()->container()->data().titleScene;
}
void TITLE::init() {
    game()->player()->initForTitle();
    Scene.message.initFadeIn();
}
void TITLE::update() {
    Scene.message.fadeIn();
}
void TITLE::draw() {
    clear(Scene.backColor);
    Scene.message.draw();
    game()->player()->draw();
}
void TITLE::nextScene(){
    if (game()->nextKeyPushed()) {
        game()->changeScene(GAME::STAGE_ID);
    }
}
