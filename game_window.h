#pragma once
#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include "opengl_window.h"



class GameWindow: public OpenGL_Window {
public:
    GameWindow();

protected:
    virtual void renderGL() override;

private:
    void initGL();

};

#endif // GAMEWINDOW_H
