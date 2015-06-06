#pragma once
#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "opengl_window.h"
#include <GL/gl.h>
#include <array>
#include <bitset>
#include "pipeline.h"
#include "shader_program.h"
struct Vertex {
    Vertex()=default;
    Vertex(float x, float y, float z) : x(x), y(y), z(z){
    }
    Vertex(float coords[3]) : x(coords[0]), y(coords[1]), z(coords[2]){
    }
    float x, y, z;
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
    GLuint VBO[100][100];
    GLuint worldLocation;
    GLuint stateLocation;
};

#endif // GAMEWINDOW_H
