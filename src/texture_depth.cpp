#include "../include/texture_depth.h"


t_texture_depth::t_texture_depth(const unsigned int width, const unsigned int height, const std::string name) : t_texture(width, height, name, GL_DEPTH_COMPONENT, GL_DEPTH_COMPONENT, NULL) {


}
