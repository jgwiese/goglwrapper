#ifndef TEXTURE_DEPTH_H
#define TEXTURE_DEPTH_H

#include "texture.h"


class t_texture_depth : public t_texture {
public:
    t_texture_depth(const unsigned int width, const unsigned int height, const std::string name);
};

#endif // TEXTURE_DEPTH_H

