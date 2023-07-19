#include "../include/texture_ub.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>
#include <iostream>


t_texture_ub::t_texture_ub(const unsigned int width, const unsigned int height, const std::string name, const unsigned char *data) : t_texture(width, height, name) {
    glGenTextures(1, &this->id);
    glBindTexture(GL_TEXTURE_2D, this->id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glBindTexture(GL_TEXTURE_2D, 0);

    std::cout << "texture created, id: " << this->id << std::endl;
}

t_texture_ub* t_texture_ub::from_image(const std::string path, const std::string name) {
    int width, height, channels;
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &channels, 0);
    if (data == NULL) {
        std::cout << "error loading the image" << std::endl;
    }
    if (channels != 4) {
        std::cout << "channels != 4" << std::endl;
    }

    t_texture_ub *p_texture_ub = new t_texture_ub(width, height, name, data);
    stbi_image_free(data);
    return p_texture_ub;
}
