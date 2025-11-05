#ifndef RENDERBUFFER_MS_H
#define RENDERBUFFER_MS_H

#include "render_target.h"

class t_renderbuffer_ms : public t_render_target {
public:
  t_renderbuffer_ms(const unsigned int width, const unsigned int height,
                    const std::string name, GLenum internalformat,
                    unsigned int samples);
  ~t_renderbuffer_ms() override;
  void use(unsigned int i) override;
};

#endif // RENDERBUFFER_MS_H
