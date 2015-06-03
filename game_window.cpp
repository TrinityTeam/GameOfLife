#include "game_window.h"
#include <GL/gl.h>


GameWindow::GameWindow():
    OpenGL_Window("Game Of Life") {
    initGL();
    start();
}



void GameWindow::initGL() {

}



void GameWindow::renderGL() {
    glClear(GL_COLOR_BUFFER_BIT);
}
