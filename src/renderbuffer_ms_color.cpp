#include "../include/renderbuffer_ms_color.h"


t_renderbuffer_ms_color::t_renderbuffer_ms_color(const unsigned int width, const unsigned int height, const std::string name, unsigned int samples) : t_renderbuffer_ms(width, height, name, GL_RGBA, samples) {

}
