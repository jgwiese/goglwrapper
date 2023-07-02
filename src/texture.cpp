#include "../include/texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>


t_texture::t_texture(const unsigned int width, const unsigned int height, const std::string name, const unsigned char *data) {
    this->width = width;
    this->height = height;
    this->name = name;
    glGenTextures(1, &this->id);
    glBindTexture(GL_TEXTURE_2D, this->id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);

    std::cout << "texture created, id: " << this->id << std::endl;
}

t_texture::t_texture(const unsigned int width, const unsigned int height, const std::string name, const float *data) {
    this->width = width;
    this->height = height;
    this->name = name;
    glGenTextures(1, &this->id);
    glBindTexture(GL_TEXTURE_2D, this->id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_FLOAT, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    std::cout << "texture created, id: " << this->id << std::endl;
}

t_texture::t_texture(const std::string path, const std::string name) {
    this->name = name;
    int width, height, channels;
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &channels, 0);
    if (data == NULL) {
        std::cout << "error loading the image" << std::endl;
    }
    if (channels != 4) {
        std::cout << "channels != 4" << std::endl;
    }
    this->width = width;
    this->height = height;

    glGenTextures(1, &this->id);
    glBindTexture(GL_TEXTURE_2D, this->id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);
    
    std::cout << "texture created, id: " << this->id << std::endl;
}

void t_texture::use() {
    glBindTexture(GL_TEXTURE_2D, this->id);
}

std::string t_texture::get_name() {
    return this->name;
}

t_texture::~t_texture() {
    glDeleteTextures(1, &this->id);
}

