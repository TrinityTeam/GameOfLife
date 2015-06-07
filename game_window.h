#pragma once
#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "opengl_window.h"
#include <GL/gl.h>
#include <array>
#include <bitset>
#include "pipeline.h"
#include "shader_program.h"
#include "texture.h"

struct Vertex {
    Vertex() {
        x = y = z = u = v = 0.0f;
    }

    Vertex(float x, float y, float z):
        x(x), y(y), z(z), u(0.0f), v(0.0f) {}

    Vertex(float x, float y, float z, float u, float v):
        x(x), y(y), z(z), u(u), v(v) {}

    Vertex(float coords[3], float tex_coords[2]):
        x(coords[0]), y(coords[1]), z(coords[2]),
        u(tex_coords[0]), v(tex_coords[1]){}

    float x, y, z;
    float u, v;
};



class GameWindow: public OpenGL_Window {
public:
    GameWindow();

    void setField(const std::array<std::array<char, 100>, 100>* field);

protected:
    virtual void renderGL() override;

private:
    void initGL();

    void createVBOs();
    void createVBO(int id[2], const Vertex& leftTopCorner);
    void createShaders();

    const std::array<std::array<char, 100>, 100>* field;

    Pipeline pipeline;
    ShaderProgram shaderProgram;
    Texture texture;
    GLuint VBO[100][100];
    GLuint worldLocation;
    GLuint stateLocation;
    GLuint samplerLocation;
};

#endif // GAMEWINDOW_H
