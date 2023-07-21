#include "../include/texture.h"
#include <glad/glad.h>


t_texture::t_texture(const unsigned int width, const unsigned int height, const std::string name) {
    this->width = width;
    this->height = height;
    this->name = name;
}

unsigned int t_texture::get_id() {
    return this->id;
}

std::string t_texture::get_name() {
    return this->name;
}

unsigned int t_texture::get_width() {
    return this->width;
}

unsigned int t_texture::get_height() {
    return this->height;
}
