#include"libOne.h"
#include"GAME.h"
#include"CONTAINER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMY_BULLETS.h"
#include"ENEMIES.h"
#include"PLAYER.h"
#include "GAME_OVER.h"
GAME_OVER::GAME_OVER(class GAME* game)
    :GAME_STATE(game) {
}
GAME_OVER::~GAME_OVER() {
}
void GAME_OVER::create() {
    BackColor = game()->container()->data.stageBackColor;
}
void GAME_OVER::proc(){
    //update
    game()->playerBullets()->update();
    game()->enemyBullets()->update();
    game()->enemies()->move();
    //draw
    clear(BackColor);
    game()->draw();
    float size = 200;
    textSize(size);
    fill(220, 0, 0);
    text("Game Over", (width-size/2*9)/2, 400);
    //next sequaence
    if (isTrigger(KEY_ENTER)) {
        game()->changeGameState(GAME::STATE_TITLE);
    }
}
