#include "opengl_window.h"



OpenGL_Window::OpenGL_Window(const char* windowTitle) {
    initSDL();
    SDL_SetWindowTitle(window, windowTitle);
    initGL();
}



void OpenGL_Window::initGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glewInit();
}



void OpenGL_Window::initSDL() {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("OpenGL render",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              600, 600,
                              SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    context = SDL_GL_CreateContext(window);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetSwapInterval(1);
}



void OpenGL_Window::processEvent(SDL_Event& event) {
    switch(event.type) {
    case SDL_QUIT:
        running = false;
        break;
    case SDL_WINDOWEVENT:

        int w, h;
        SDL_GetWindowSize(window, &w, &h);
        glViewport(0, 0, w, h);
        break;
    }
}



OpenGL_Window::~OpenGL_Window() {
    SDL_DestroyWindow(window);
    SDL_GL_DeleteContext(context);
    SDL_Quit();
}



void OpenGL_Window::renderOneFrame() {
    if(running) {
        while(SDL_PollEvent(&event)) {
            processEvent(event);
        }
        renderGL();
        SDL_GL_SwapWindow(window);
    }
}



bool OpenGL_Window::isRunning() const {
    return running;
}

