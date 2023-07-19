#ifndef TEXTURE_UB_H
#define TEXTURE_UB_H

#include "texture.h"


class t_texture_ub : public t_texture {
public:
    t_texture_ub(const unsigned int width, const unsigned int height, const std::string name, const unsigned char *data);
    static t_texture_ub* from_image(const std::string path, const std::string name);
    ~t_texture_ub();
};

#endif // TEXTURE_UB_H
