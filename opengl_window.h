#pragma once
#ifndef OPENGL_WINDOW_H
#define OPENGL_WINDOW_H
#include <string>
#include <SDL2/SDL.h>



class OpenGL_Window {
public:
    OpenGL_Window(const std::string& windowTitle);
    ~OpenGL_Window();

protected:
    virtual void renderGL();
    virtual void processEvent(SDL_Event& event);
    void start();

private:
    void initGL();
    void initSDL();
    bool running = true;

    SDL_Window* window;
    SDL_GLContext context;

};

#endif // OPENGL_WINDOW_H
