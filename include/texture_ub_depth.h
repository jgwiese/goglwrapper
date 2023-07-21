#ifndef TEXTURE_UB_DEPTH_H
#define TEXTURE_UB_DEPTH_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include "texture.h"


class t_texture_ub_depth : public t_texture{
public:
    t_texture_ub_depth(const unsigned int width, const unsigned int height, const std::string name, const unsigned char *data);
    void use(unsigned int i) override;
};

#endif // TEXTURE_UB_DEPTH_H

