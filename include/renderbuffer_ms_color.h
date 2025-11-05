#ifndef RENDERBUFFER_MS_COLOR_H
#define RENDERBUFFER_MS_COLOR_H

#include "renderbuffer_ms.h"

class t_renderbuffer_ms_color : public t_renderbuffer_ms {
public:
  t_renderbuffer_ms_color(const unsigned int width, const unsigned int height,
                          const std::string name, unsigned int samples);
};

#endif // RENDERBUFFER_MS_COLOR_H
