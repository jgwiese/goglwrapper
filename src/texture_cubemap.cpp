#include "../include/texture_cubemap.h"
#include <glm/common.hpp>
#include <format>
#include <gassets/image.h>


t_texture_cubemap::t_texture_cubemap(std::string name, std::vector<std::string> paths) : t_render_target(2.0, 2.0, name) {
    assert(paths.size() == 6);
    glGenTextures(1, &this->id);
    glBindTexture(GL_TEXTURE_CUBE_MAP, this->id);

    t_image *p_image;
    for (unsigned int i = 0; i < paths.size(); i++) {
        p_image = t_image::from_file(paths[i]);
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA, p_image->get_width(), p_image->get_height(), 0, GL_RGBA, GL_FLOAT, p_image->get_data());
        // TODO destruct old image
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE); 

    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

t_texture_cubemap::t_texture_cubemap(std::string name) : t_render_target(2.0, 2.0, name) {
    glGenTextures(1, &this->id);
    glBindTexture(GL_TEXTURE_CUBE_MAP, this->id);

    float *data = new float[4]{0.0, 0.0, 0.0, 1.0};
    for (unsigned int i = 0; i < 6; i++) {
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGBA, 1, 1, 0, GL_RGBA, GL_FLOAT, data);
        // TODO destruct old image
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE); 

    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

void t_texture_cubemap::use(unsigned int i) {
    glActiveTexture(GL_TEXTURE0 + i);
    glBindTexture(GL_TEXTURE_CUBE_MAP, this->id);
}
