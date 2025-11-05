#ifndef TEXTURE_COLOR_H
#define TEXTURE_COLOR_H

#include "texture.h"

class t_texture_color : public t_texture {
public:
  t_texture_color(const unsigned int width, const unsigned int height,
                  const std::string name, const float *data);
  static t_texture_color *from_image(std::string path, std::string name);
};

#endif // TEXTURE_COLOR_H
