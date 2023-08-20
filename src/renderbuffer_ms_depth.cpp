#include "../include/renderbuffer_ms_depth.h"


t_renderbuffer_ms_depth::t_renderbuffer_ms_depth(const unsigned int width, const unsigned int height, const std::string name, unsigned int samples) : t_renderbuffer_ms(width, height, name, GL_DEPTH_COMPONENT, samples) {

}
