#include"GAME_STATE.h"
GAME_STATE::GAME_STATE(class GAME* game) {
    Game = game;
}
GAME_STATE::~GAME_STATE() {
    Game = 0;
}
void GAME_STATE::create() {}
void GAME_STATE::init() {}
//getter
class GAME* GAME_STATE::game() {
    return Game;
}