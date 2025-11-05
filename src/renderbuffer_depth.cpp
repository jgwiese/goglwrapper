#include "../include/renderbuffer_depth.h"

t_renderbuffer_depth::t_renderbuffer_depth(const unsigned int width,
                                           const unsigned int height,
                                           const std::string name)
    : t_renderbuffer_ms_depth(width, height, name, 0) {}
