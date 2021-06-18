#include"libOne.h"
#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMIES.h"
#include"ENEMY_BULLETS.h"
#include"GAME.h"
#include"PLAY.h"
void PLAY::init(class GAME* game) {
    Player = game->player();
    PlayerBullets = game->playerBullets();
    Enemies = game->enemies();
    EnemyBullets = game->enemyBullets();

    Player->start();
    Enemies->start();
    PlayerBullets->init(game);
    EnemyBullets->init(game);
}
void PLAY::proc(class GAME* game) {
    //update
    Player->move();
    Enemies->move();
    //draw
    clear(50,150,230);
    game->draw();
    print("PLAY");
    //next state
}

