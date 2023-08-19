#include "../include/texture_ms.h"
#include <glad/glad.h>
#include <iostream>


// TODO: no this inheritance does not make sense, if at all then the other way round.
t_texture_ms::t_texture_ms(const unsigned int width, const unsigned int height, const std::string name, const unsigned int samples) : t_texture(width, height, name), samples(samples) {
    glGenTextures(1, &this->id);
    glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, this->id);
    // TODO: changed GL_RGB to GL_RGBA
    glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, this->samples, GL_RGBA, width, height, GL_TRUE);
    glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, 0);
    std::cout << "msaa texture " << this->name << " created, id: " << this->id << std::endl;
}

void t_texture_ms::use(unsigned int i) {
    glActiveTexture(GL_TEXTURE0 + i);
    glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, this->id);
}
