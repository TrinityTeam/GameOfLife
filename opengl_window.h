#pragma once
#ifndef OPENGL_WINDOW_H
#define OPENGL_WINDOW_H
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>



class OpenGL_Window {
public:
    OpenGL_Window(const char* windowTitle = "OpenGL render");
    ~OpenGL_Window();

    void renderOneFrame();
    bool isRunning() const;

protected:
    virtual void renderGL() = 0;
    virtual void processEvent(SDL_Event& event);
    void createShader(GLuint shaderProgram, GLint shaderType, const std::string& shaderText);

private:
    void initSDL();
    void initGL();
    bool running = true;

    SDL_Window* window;
    SDL_GLContext context;
    SDL_Event event;

};

#endif // OPENGL_WINDOW_H
