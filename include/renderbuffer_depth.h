#ifndef RENDERBUFFER_DEPTH_H
#define RENDERBUFFER_DEPTH_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "renderbuffer_ms_depth.h"


class t_renderbuffer_depth : public t_renderbuffer_ms_depth
{
public:
    t_renderbuffer_depth(const unsigned int width, const unsigned int height, const std::string name);
};

#endif // RENDERBUFFER_DEPTH_H
