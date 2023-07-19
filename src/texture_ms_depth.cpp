#include "../include/texture_ms_depth.h"
#include <glad/glad.h>
#include <iostream>


// TODO: no this inheritance does not make sense, if at all then the other way round.
t_texture_ms_depth::t_texture_ms_depth(const unsigned int width, const unsigned int height, const std::string name, const unsigned int samples) : t_texture(width, height, name), samples(samples) {
    glGenTextures(1, &this->id);
    glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, this->id);
    glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, this->samples, GL_DEPTH_COMPONENT, width, height, GL_TRUE);
    glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, 0);
    std::cout << "msaa depth texture created, id: " << this->id << std::endl;
}

