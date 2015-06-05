#pragma once
#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "opengl_window.h"
#include <GL/gl.h>
#include <array>
#include <bitset>
#include "pipeline.h"



class GameWindow: public OpenGL_Window {
    using Vertex = std::array<float, 3>;

public:
    GameWindow();

    void setField(const std::array<std::bitset<100>, 100>* field);

protected:
    virtual void renderGL() override;

private:
    void initGL();

    void createVBO();
    void createIBO();
    void createShaders();

    const std::array<std::bitset<100>, 100>* field;

    Pipeline pipeline;
    GLuint shaderProgram;
    GLuint VBO;
    GLuint IBO;
    GLuint worldLocation;
    GLuint liveLocation;
};

#endif // GAMEWINDOW_H
