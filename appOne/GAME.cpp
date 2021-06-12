#include"libOne.h"

#include"TITLE.h"
#include"PLAY.h"
#include"OVER.h"
#include"CLEAR.h"

#include"PLAYER.h"
#include"PLAYER_BULLETS.h"
#include"ENEMIES.h"
#include"ENEMY_BULLETS.h"

#include "GAME.h"
GAME::GAME() {
}
GAME::~GAME() {
    destroy();
}
void GAME::create() {
    //キャラクタ
    int playerImg = loadImage("assets\\player.png");
    int playerBulletImg = loadImage("assets\\pBullet.png");
    int enemyImg = loadImage("assets\\enemy.png");
    int enemyBulletImg = loadImage("assets\\eBullet.png");
    Player = new PLAYER;
    PlayerBullets = new PLAYER_BULLETS;
    Enemies = new ENEMIES;
    EnemyBullets = new ENEMY_BULLETS;
    Player->create(playerImg);
    PlayerBullets->create(playerBulletImg);
    Enemies->create(enemyImg);
    EnemyBullets->create(enemyBulletImg);
    //シーケンス
    GameStates = new GAME_STATE*[GAME_STATE::ID::NUM]();
    GameStates[GAME_STATE::ID::TITLE] = new TITLE;
    GameStates[GAME_STATE::ID::PLAY] = new PLAY;
    GameStates[GAME_STATE::ID::OVER] = new OVER;
    GameStates[GAME_STATE::ID::CLEAR] = new CLEAR;
    changeGameState(GAME_STATE::ID::TITLE);
}
void GAME::destroy() {
    //キャラクタ
    SAFE_DELETE(EnemyBullets);
    SAFE_DELETE(Enemies);
    SAFE_DELETE(PlayerBullets);
    SAFE_DELETE(Player);
    //シーケンス
    for (int i = 0; i < GAME_STATE::ID::NUM; i++) {
        if (GameStates[i]) {
            delete GameStates[i];
            GameStates[i] = 0;
        }
    }
    if (GameStates) {
        delete[] GameStates;
        GameStates = 0;
    }
}
void GAME::proc() {
    CurrentGameState->proc(this);
}
void GAME::changeGameState(GAME_STATE::ID id) {
    CurrentGameState = GameStates[id];
    CurrentGameState->init(this);
}
//キャラクタ
void GAME::draw() {
    Enemies->draw();
    Player->draw();
    PlayerBullets->draw();
    EnemyBullets->draw();
}
PLAYER* GAME::player(){
    return Player;
}
PLAYER_BULLETS* GAME::playerBullets() {
    return PlayerBullets;
}
ENEMIES* GAME::enemies() {
    return Enemies;
}
ENEMY_BULLETS* GAME::enemyBullets() {
    return EnemyBullets;
}

