#include"CHARACTER.h"
CHARACTER::CHARACTER(class GAME* game)
    :Game(game) {
}
CHARACTER::~CHARACTER() {
    Game = 0;
}
class GAME* CHARACTER::game() {
    return Game;
}
