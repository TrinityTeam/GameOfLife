#include <GL/glew.h>
#include "game_window.h"
#include <fstream>
#include <iostream>
#include <assert.h>



GameWindow::GameWindow():
    OpenGL_Window("Game Of Life") {
    initGL();
}



void GameWindow::setField(const std::array<std::bitset<100>, 100>* field) {
    this->field = field;
}



void GameWindow::initGL() {
    glewInit();

    createVBO();
    createShaders();

    worldLocation = glGetUniformLocation(shaderProgram, "world");
    assert(worldLocation != 0xFFFFFFFF);

    liveLocation = glGetUniformLocation(shaderProgram, "isLive");
    assert(liveLocation != 0xFFFFFFFF);
}



void GameWindow::renderGL() {
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float)*3, 0);

    for(float c = 0; c < 2; c+=0.01f) {
        for(float i = 0; i > -2; i-=0.01f) {
            glDrawArrays(GL_QUADS, 0, 4);
            pipeline.setWorldPosition(c, i, 0.0f);
            glUniformMatrix4fv(worldLocation, 1, GL_TRUE, (const GLfloat*)&pipeline.getTransformation());
            glUniform1i(liveLocation, (GLint)(*field)[c*100/2][-i*100/2]);
        }
    }

    glDisableVertexAttribArray(0);
    glFlush();
}



void GameWindow::createShaders() {
    std::ifstream fin("shaders/vertex.glsl");
    if(not fin.is_open()) std::cerr << "File vertex.glsl not found";
    std::string vertexShader;
    char c;
    while(not fin.eof()) {
        fin.get(c);
        vertexShader += c;
    }
    fin.close();

    fin.open("shaders/fragment.glsl");
    if(not fin.is_open()) std::cerr << "File fragment.glsl not found";
    std::string fragmentShader;
    while(not fin.eof()) {
        fin.get(c);
        fragmentShader += c;
    }

    shaderProgram = glCreateProgram();
    createShader(shaderProgram, GL_VERTEX_SHADER, vertexShader.c_str());
    createShader(shaderProgram, GL_FRAGMENT_SHADER, fragmentShader.c_str());
    glValidateProgram(shaderProgram);
    glUseProgram(shaderProgram);
}



void GameWindow::createVBO() {
    array<Vertex, 4> vertices;
    vertices[0] = {-1.0f, 1.0f, 0.0f};
    vertices[1] = {-0.99f, 1.0f, 0.0f};
    vertices[2] = {-0.99f, 0.99f, 0.0f};
    vertices[3] = {-1.0f, 0.99f, 0.0f};

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
}



void GameWindow::createIBO() {
    /*unsigned int indices[] = {
        3, 2, 1,    1, 0, 3,
    };
    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/
}
