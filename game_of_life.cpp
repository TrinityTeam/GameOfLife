#include "game_of_life.h"



GameOfLife::GameOfLife() {
    std::array<std::bitset<100>, 100> field;
    GameWindow screen;
    screen.setField(&field);

    while(screen.isRunning()) {
        screen.renderOneFrame();
        field[0][1] = 0;
    }

}
