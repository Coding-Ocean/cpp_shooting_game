#include"libOne.h"
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMIES.h"
#include"ENEMY_BULLETS.h"
#include"GAME.h"
#include"PLAY.h"
PLAY::PLAY(class GAME* game)
    :GAME_STATE(game) {
}
PLAY::~PLAY() {
}
void PLAY::init() {
    game()->player()->init();
    game()->enemies()->init();
    game()->playerBullets()->init();
    game()->enemyBullets()->init();
}
void PLAY::proc() {
    //update
    game()->playerBullets()->update();
    game()->enemyBullets()->update();
    game()->player()->update();
    game()->enemies()->update();
    //draw
    clear(60);
    game()->draw();
#ifdef _DEBUG
    printSize(50);
    print((let)"CurNum="+ game()->playerBullets()->curNum());
#endif
    //next state
    if (game()->enemies()->curNum() <= 0) {
        game()->changeGameState(GAME::STATE_CLEAR);
    }
    else if (game()->player()->hp() <= 0) {
        game()->changeGameState(GAME::STATE_OVER);
    }
}