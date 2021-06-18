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
    game()->player()->start();
    game()->enemies()->start();
    game()->playerBullets()->start();
    game()->enemyBullets()->start();
}
void PLAY::proc() {
    //update
    game()->player()->move();
    game()->enemies()->move();
    game()->playerBullets()->move();
    game()->enemyBullets()->move();
    //draw
    clear(60);
    game()->draw();
    printSize(50);
    print((let)"CurNum="+ game()->playerBullets()->curNum());
    //next state
    if (game()->enemies()->curNum() <= 0) {
        game()->changeGameState(GAME::STATE_TITLE);
    }
}