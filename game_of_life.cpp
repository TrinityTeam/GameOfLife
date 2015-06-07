#include "game_of_life.h"



GameOfLife::GameOfLife() {

    GameWindow screen;
    Logic logic;
    screen.setField(&logic.getField());
    logic.randomizeField();
    while(screen.isRunning()) {
        screen.renderOneFrame();
        //SDL_Delay(10000);
        logic.updateField();
    }
}
