#include "opengl_window.h"



OpenGL_Window::OpenGL_Window(const std::string& windowTitle) {
    initSDL();
    initGL();
}



void OpenGL_Window::initGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

    glewInit();
}



void OpenGL_Window::initSDL() {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("OpenGL render",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              800, 800,
                              SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    context = SDL_GL_CreateContext(window);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetSwapInterval(1);
}



void OpenGL_Window::processEvent(SDL_Event& event) {
    switch(event.type) {
    case SDL_QUIT:
        running = false;
        break;
    }
}



OpenGL_Window::~OpenGL_Window() {
    SDL_DestroyWindow(window);
    SDL_GL_DeleteContext(context);
    SDL_Quit();
}



void OpenGL_Window::renderOneFrame() {
    if(running) {
        while(SDL_PollEvent(&event)) {
            processEvent(event);
        }
        renderGL();
        SDL_GL_SwapWindow(window);
    }
}



void OpenGL_Window::createShader(GLuint shaderProgram, GLint shaderType, const std::string& shaderText) {
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
        printf("Error compiling shader type %d : %s\n", shaderType, infoLog );
    }

    glAttachShader(shaderProgram, shader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (not success) {
        GLchar errorLog[1024];
        glGetProgramInfoLog(shaderProgram, sizeof(errorLog), NULL, errorLog);
        printf("Error linking shader program: %s\n", errorLog);
    }
}



bool OpenGL_Window::isRunning() const {
    return running;
}

