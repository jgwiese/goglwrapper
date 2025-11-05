#ifndef RENDERBUFFER_DEPTH_STENCIL_H
#define RENDERBUFFER_DEPTH_STENCIL_H

#include "gl.h"
#include "renderbuffer_ms_depth_stencil.h"

class t_renderbuffer_depth_stencil : public t_renderbuffer_ms_depth_stencil {
public:
  t_renderbuffer_depth_stencil(const unsigned int width,
                               const unsigned int height,
                               const std::string name);
};

#endif // RENDERBUFFER_DEPTH_STENCIL_H
