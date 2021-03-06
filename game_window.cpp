#include <GL/glew.h>
#include "game_window.h"
#include <fstream>
#include <iostream>
#include <assert.h>



GameWindow::GameWindow():
    OpenGL_Window("Game Of Life"),
    texture(GL_TEXTURE_2D){
    initGL();
}



void GameWindow::setField(const std::array<std::array<char, 100>, 100>* field) {
    this->field = field;
}



void GameWindow::initGL() {
    glewInit();

    createVBOs();
    createShaders();

    texture.load("life_cell.bmp");

    worldLocation = glGetUniformLocation(shaderProgram.getGLProgram(), "world");
    assert(worldLocation != 0xFFFFFFFF);

    stateLocation = glGetUniformLocation(shaderProgram.getGLProgram(), "cellState");
    assert(stateLocation != 0xFFFFFFFF);

    samplerLocation = glGetUniformLocation(shaderProgram.getGLProgram(), "sampler");
    assert(samplerLocation != 0xFFFFFFFF);
    glUniform1i(samplerLocation, 0);
}



void GameWindow::renderGL() {
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    pipeline.setWorldPosition(0.0f, 0.0f, 0.0f);
    glUniformMatrix4fv(worldLocation, 1, GL_TRUE, (const GLfloat*)&pipeline.getTransformation());

    for(short c = 0; c < 100; c++) {
        for(short i = 0; i < 100; i++) {

            glBindBuffer(GL_ARRAY_BUFFER, VBO[c][i]);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)(sizeof(GLfloat)*3));

            texture.bind(GL_TEXTURE0);

            glDrawArrays(GL_QUADS, 0, 4);

            glUniform1i(stateLocation, (GLint)(*field)[c][i]);
        }
    }
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
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

    shaderProgram.addShader(GL_VERTEX_SHADER, vertexShader.c_str());
    shaderProgram.addShader(GL_FRAGMENT_SHADER, fragmentShader.c_str());
    shaderProgram.useProgram();

}



void GameWindow::createVBOs() {
    for(short c = 0; c < 100; c++) {
        glGenBuffers(100, VBO[c]);
    }

    for(short c = 0; c < 100; c++) {
        for(short i = 0; i < 100; i++) {
            int id[2] = {c, i};
            float x = c/100.0f*2.0f;
            float y = -i/100.0f*2.0f;
            createVBO(id, {x-1, y+1, 0.0f});
        }
    }
}



void GameWindow::createVBO(int id[2], const Vertex& leftTopCorner) {
    std::array<Vertex, 4> vertices;
    vertices[0] = leftTopCorner;
    vertices[0].u = 0.0f; vertices[0].v = 1.0f;
    vertices[1] = Vertex(leftTopCorner.x+0.02f, leftTopCorner.y, 0.0f,
                         1.0f, 1.0f);
    vertices[2] = Vertex(leftTopCorner.x+0.02f, leftTopCorner.y-0.02f, 0.0f,
                         1.0f, 0.0f);
    vertices[3] = Vertex(leftTopCorner.x, leftTopCorner.y-0.02f, 0.0f,
                         0.0f, 0.0f);

    glBindBuffer(GL_ARRAY_BUFFER, VBO[id[0]][id[1]]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices, GL_STATIC_DRAW);
}
