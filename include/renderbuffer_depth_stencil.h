#ifndef RENDERBUFFER_DEPTH_STENCIL_H
#define RENDERBUFFER_DEPTH_STENCIL_H

#include "renderbuffer_ms_depth_stencil.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>

class t_renderbuffer_depth_stencil : public t_renderbuffer_ms_depth_stencil {
public:
  t_renderbuffer_depth_stencil(const unsigned int width,
                               const unsigned int height,
                               const std::string name);
};

#endif // RENDERBUFFER_DEPTH_STENCIL_H
