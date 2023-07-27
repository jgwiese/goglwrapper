#include "../include/texture_f.h"
#include <iostream>
#include <gassets/gassets.h>


t_texture_f::t_texture_f(const unsigned int width, const unsigned int height, const std::string name, const float *data) : t_texture(width, height, name) {
    glGenTextures(1, &this->id);
    glBindTexture(GL_TEXTURE_2D, this->id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_FLOAT, data);
    //glGenerateMipmap(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    std::cout << "texture " << this->name << " created, id: " << this->id << std::endl;
}

void t_texture_f::use(unsigned int i) {
    glActiveTexture(GL_TEXTURE0 + i);
    glBindTexture(GL_TEXTURE_2D, this->id);
}

t_texture_f* t_texture_f::from_image(std::string path, std::string name) {
    t_image *p_image = t_image::from_file(path);
    t_texture_f *p_texture = new t_texture_f(p_image->get_width(), p_image->get_height(), name, p_image->get_data());
    return p_texture;
}
