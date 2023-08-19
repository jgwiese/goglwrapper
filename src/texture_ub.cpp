#include "../include/texture_ub.h"
#include <iostream>


t_texture_ub::t_texture_ub(const unsigned int width, const unsigned int height, const std::string name, const unsigned char *data) : t_texture(width, height, name) {
    glGenTextures(1, &this->id);
    glBindTexture(GL_TEXTURE_2D, this->id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);

    std::cout << "texture ub " << this->name << " created, id: " << this->id << std::endl;
}

void t_texture_ub::use(unsigned int i) {
    glBindTexture(GL_TEXTURE_2D, this->id);
}
