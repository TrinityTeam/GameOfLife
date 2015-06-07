#include "texture.h"
#include <SDL2/SDL_image.h>

Texture::Texture(GLenum textureTarget):
    textureTarget(textureTarget) {
}



Texture::~Texture() {
    SDL_FreeSurface(image);
    //if(image)delete image;

}


#include <iostream>
void Texture::load(const std::string& fileName) {
    image = IMG_Load(fileName.c_str());
    //image = SDL_ConvertSurfaceFormat(image, SDL_PIXELFORMAT_RGB444, 0);

    glGenTextures(1, &textureObject);
    glBindTexture(textureTarget, textureObject);
    glTexImage2D(textureTarget, 0, GL_RGB,
                 image->w, image->h,
                 0, GL_RGB, GL_UNSIGNED_BYTE,
                 image->pixels);
    glTexParameterf(textureTarget, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(textureTarget, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}



void Texture::bind(GLenum textureUnit) {
    glActiveTexture(textureUnit);
    glBindTexture(textureTarget, textureObject);
}
