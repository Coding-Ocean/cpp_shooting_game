#include"libOne.h"
#include"CONTAINER.h"
#include"GAME.h"
#include"PLAYER.h"
#include "TITLE.h"
TITLE::TITLE(class GAME* game)
    :SCENE(game){
}
void TITLE::create() {
    Scene = game()->container()->titleScene();
}
void TITLE::init() {
    Scene.textColor.a = 0;
    game()->player()->initForTitle();
}
void TITLE::draw() {
    clear(Scene.backColor);
    if (Scene.textColor.a < 255) {
        Scene.textColor.a += Scene.transSpeed * delta;
    }
    SCENE::draw();
    game()->player()->draw();
}
void TITLE::nextScene(){
    if (game()->nextKeyPushed()) {
        game()->changeScene(GAME::STAGE_ID);
    }
}
