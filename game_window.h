#pragma once
#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "opengl_window.h"
#include <GL/gl.h>
#include <array>
#include <bitset>
#include "pipeline.h"



class GameWindow: public OpenGL_Window {
    template <class T, size_t N> using array = std::array<T, N>;
    template <size_t N> using bitset = std::bitset<N>;
    using Vertex = array<float, 3>;

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

    const array<bitset<100>, 100>* field;

    Pipeline pipeline;
    GLuint shaderProgram;
    GLuint VBO;
    GLuint IBO;
    GLuint worldLocation;
    GLuint liveLocation;
};

#endif // GAMEWINDOW_H
