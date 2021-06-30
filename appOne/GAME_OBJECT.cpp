#include"GAME_OBJECT.h"
GAME_OBJECT::GAME_OBJECT(class GAME* game)
    :Game(game) {
}
GAME_OBJECT::~GAME_OBJECT() {
    Game = 0;
}
class GAME* GAME_OBJECT::game() {
    return Game;
}
