#ifndef RENDERBUFFER_COLOR_H
#define RENDERBUFFER_COLOR_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "renderbuffer_ms_color.h"


class t_renderbuffer_color : public t_renderbuffer_ms_color {
public:
    t_renderbuffer_color(const unsigned int width, const unsigned int height, const std::string name);
};

#endif // RENDERBUFFER_COLOR_H

