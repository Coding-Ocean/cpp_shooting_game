#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include"GAME_CLEAR.h"
GAME_CLEAR::GAME_CLEAR(class GAME* game) :
    SCENE(game) {
}
void GAME_CLEAR::create() {
    Scene = game()->container()->data()->gameClear;
}
void GAME_CLEAR::update() {
    game()->playerBullets()->update();
    game()->enemyBullets()->update();
}
void GAME_CLEAR::draw() {
    clear(Scene.backColor);
    game()->draw();
    SCENE::draw();
}
void GAME_CLEAR::nextScene(){
    if (isTrigger(KEY_J)) {
        game()->changeScene(GAME::TITLE_ID);
    }
}
