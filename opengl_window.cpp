#include "opengl_window.h"
#include <GL/gl.h>



OpenGL_Window::OpenGL_Window(const std::string& windowTitle) {
    window = SDL_CreateWindow(windowTitle.c_str(),
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              800,800,
                              SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    context = SDL_GL_CreateContext(window);

    initSDL();
    initGL();
}



void OpenGL_Window::initGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
}



void OpenGL_Window::renderGL() {
    glClear(GL_COLOR_BUFFER_BIT);
}



void OpenGL_Window::initSDL() {
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetSwapInterval(1);
}



void OpenGL_Window::processEvent(SDL_Event& event) {
    switch(event.type) {
    case SDL_QUIT:
        running = false;
        break;
    }
}



OpenGL_Window::~OpenGL_Window() {
    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
}



void OpenGL_Window::start() {
    SDL_Event event;
    while(running) {
        while(SDL_PollEvent(&event)) {
            processEvent(event);
        }
        renderGL();
        SDL_GL_SwapWindow(window);
    }
}
