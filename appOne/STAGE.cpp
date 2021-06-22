#include"libOne.h"
#include"CONTAINER.h"
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMIES.h"
#include"ENEMY_BULLETS.h"
#include"GAME.h"
#include"STAGE.h"
STAGE::STAGE(class GAME* game)
    :GAME_STATE(game) {
}
STAGE::~STAGE() {
}
void STAGE::create() {
    BackColor = game()->container()->data.stageBackColor;
}
void STAGE::init() {
    game()->player()->init();
    game()->enemies()->init();
    game()->playerBullets()->init();
    game()->enemyBullets()->init();
}
void STAGE::proc() {
    //update
    game()->playerBullets()->update();
    game()->enemyBullets()->update();
    game()->player()->update();
    game()->enemies()->update();
    //draw
    clear(BackColor);
    game()->draw();
#ifdef _DEBUG
    fill(255);
    print((let)"CurNum="+ game()->playerBullets()->curNum());
#endif
    //next state
    if (game()->enemies()->curNum() <= 0) {
        game()->changeGameState(GAME::STATE_GAME_CLEAR);
    }
    else if (game()->player()->hp() <= 0) {
        game()->changeGameState(GAME::STATE_GAME_OVER);
    }
}