#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>



class Texture {
public:
    Texture(GLenum textureTarget);
    ~Texture();

    void load(const std::string& fileName);

    void bind(GLenum textureUnit);

private:
    GLenum textureTarget;
    GLuint textureObject;
    SDL_Surface* image;
    //Magick::Image* image;
    //Magick::Blob blob;

};

#endif // TEXTURE_H
