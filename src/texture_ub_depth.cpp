#include "../include/texture_ub_depth.h"
#include <iostream>


t_texture_ub_depth::t_texture_ub_depth(const unsigned int width, const unsigned int height, const std::string name, const unsigned char *data) : t_texture(width, height, name) {
    glGenTextures(1, &this->id);
    glBindTexture(GL_TEXTURE_2D, this->id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, this->width, this->height, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);

    std::cout << "texture ub depth created, id: " << this->id << std::endl;
}

void t_texture_ub_depth::use(unsigned int i) {
    glActiveTexture(GL_TEXTURE0 + i);
    glBindTexture(GL_TEXTURE_2D, this->id);
}
