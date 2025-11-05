#include "../include/renderbuffer_ms.h"

t_renderbuffer_ms::t_renderbuffer_ms(const unsigned int width,
                                     const unsigned int height,
                                     const std::string name,
                                     GLenum internalformat,
                                     unsigned int samples)
    : t_render_target(width, height, name) {
  glGenRenderbuffers(1, &this->id);
  glBindRenderbuffer(GL_RENDERBUFFER, this->id);
  glRenderbufferStorageMultisample(GL_RENDERBUFFER, samples, internalformat,
                                   width, height);
  glBindRenderbuffer(GL_RENDERBUFFER, 0);
}

t_renderbuffer_ms::~t_renderbuffer_ms() {}

void t_renderbuffer_ms::use(unsigned int i) {
  glBindRenderbuffer(GL_RENDERBUFFER, this->id);
}
