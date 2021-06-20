#include"libOne.h"
#include"GAME.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include"ENEMIES.h"
#include"PLAYER.h"
#include "OVER.h"
OVER::OVER(class GAME* game)
    :GAME_STATE(game) {
}
OVER::~OVER() {
}
void OVER::init(){
}
void OVER::proc(){
    game()->playerBullets()->update();
    game()->enemyBullets()->update();
    game()->enemies()->move();
    clear(60);
    game()->draw();
    float size = 200;
    textSize(size);
    fill(220, 0, 0);
    text("GameOver", (width-size/2*8)/2, 400);
    if (isTrigger(KEY_ENTER)) {
        game()->changeGameState(GAME::STATE_TITLE);
    }
}
