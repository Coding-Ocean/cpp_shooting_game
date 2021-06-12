#include"libOne.h"
#include"GAME.h"
void gmain() {
    window(1920, 1080, full);
    hideCursor();
    GAME game;
    game.create();
    while (notQuit) {
        game.proc();
    }
}

