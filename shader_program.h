#pragma once
#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H
#include <GL/glew.h>
#include <string>



class ShaderProgram {
public:
    ShaderProgram();

    GLuint getGLProgram() const;
    void addShader(GLint shaderType, const std::string& shaderText);
    void useProgram();

private:
    GLuint shaderProgram;
};

#endif // SHADERPROGRAM_H
