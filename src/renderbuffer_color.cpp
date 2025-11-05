#include "../include/renderbuffer_color.h"

t_renderbuffer_color::t_renderbuffer_color(const unsigned int width,
                                           const unsigned int height,
                                           const std::string name)
    : t_renderbuffer_ms_color(width, height, name, 0) {}
