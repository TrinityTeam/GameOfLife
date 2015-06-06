#include "shader_program.h"
#include <iostream>


ShaderProgram::ShaderProgram() {
    shaderProgram = glCreateProgram();
}



GLuint ShaderProgram::getGLProgram() const {
    return shaderProgram;
}



void ShaderProgram::useProgram() {
    glValidateProgram(shaderProgram);
    glUseProgram(shaderProgram);
}



void ShaderProgram::addShader(GLint shaderType, const std::string& shaderText) {
    GLuint shader = glCreateShader(shaderType);

    const GLchar* p = shaderText.c_str();
    GLint length = shaderText.length();
    glShaderSource(shader, 1, &p, &length);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (not success) {
        GLchar infoLog[1024];
        glGetShaderInfoLog(shader, sizeof(infoLog), NULL, infoLog);
        std::cerr << "Error compiling shader type " << shaderType << " : " << infoLog << "\n";
    }

    glAttachShader(shaderProgram, shader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (not success) {
        GLchar errorLog[1024];
        glGetProgramInfoLog(shaderProgram, sizeof(errorLog), NULL, errorLog);
        std::cerr << "Error linking shader program: " << errorLog << "\n";
    }
}
