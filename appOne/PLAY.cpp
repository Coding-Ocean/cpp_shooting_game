#include"libOne.h"
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMIES.h"
#include"ENEMY_BULLETS.h"
#include"GAME.h"
#include"PLAY.h"
void PLAY::init(class GAME* game) {
    game->player()->init(game);
    game->playerBullets()->init(game);
    game->enemies()->init(game);
    game->enemyBullets()->init(game);
}
void PLAY::proc(class GAME* game) {
    //update
    PLAYER* player = game->player();
    PLAYER_BULLETS* playerBullets = game->playerBullets();
    ENEMIES* enemies = game->enemies();
    ENEMY_BULLETS* enemyBullets = game->enemyBullets();
    player->move();
    player->launch(playerBullets);
    enemies->move(game);
    enemies->launch(enemyBullets, player);
    //collision
    int flag = collision(game);
    //draw
    clear(50,150,230);
    game->draw();
    print("PLAY");
    //next state
    if (flag) {
        //game->changeGameState(GAME_STATE::ID::OVER);
    }
    //else if (player->py() < height/3) {
    //    game->changeGameState(GAME_STATE::ID::CLEAR);
    //}
}
int PLAY::collision(class GAME* game) {
    PLAYER* player = game->player();
    ENEMIES* enemies = game->enemies();
    int num = enemies->num();
    int flag = 0;
    float sqMin = 130 * 130;
    for (int i = 0; i < num && flag == 0; i++) {
        for (int j = 0; j < 3 && flag == 0; j++) {
            float x = enemies->px(i) - (player->cpx(j));
            float y = enemies->py(i) - (player->cpy(j));
            float sqDistance = x * x + y * y;
            if (sqDistance < sqMin)flag = 1;
        }
    }
    return flag;
}

