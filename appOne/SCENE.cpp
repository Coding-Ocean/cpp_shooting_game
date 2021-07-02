#include"SCENE.h"
SCENE::SCENE(class GAME* game):
GAME_OBJECT(game){
}
SCENE::~SCENE() {
}
void SCENE::create() {
}
void SCENE::init() {
}
void SCENE::proc() {
    update();
    draw();
    nextScene();
}
void SCENE::update(){
}
void SCENE::draw(){
    fill(Scene.textColor);
    textSize(Scene.textSize);
    textMode(TOP);
    text(Scene.string, Scene.pos.x, Scene.pos.y);
}
void SCENE::nextScene(){
}
