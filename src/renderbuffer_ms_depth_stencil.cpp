#include "../include/renderbuffer_ms_depth_stencil.h"

t_renderbuffer_ms_depth_stencil::t_renderbuffer_ms_depth_stencil(
    const unsigned int width, const unsigned int height, const std::string name,
    unsigned int samples)
    : t_renderbuffer_ms(width, height, name, GL_DEPTH24_STENCIL8, samples) {}
