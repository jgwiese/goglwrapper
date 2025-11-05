#ifndef RENDERBUFFER_MS_DEPTH_H
#define RENDERBUFFER_MS_DEPTH_H

#include "renderbuffer_ms.h"

class t_renderbuffer_ms_depth : public t_renderbuffer_ms {
public:
  t_renderbuffer_ms_depth(const unsigned int width, const unsigned int height,
                          const std::string name, unsigned int samples);
};

#endif // RENDERBUFFER_MS_DEPTH_H
