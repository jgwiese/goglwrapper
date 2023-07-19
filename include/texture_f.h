#ifndef TEXTURE_F_H
#define TEXTURE_F_H


#include "texture.h"

class t_texture_f : public t_texture{
public:
    t_texture_f(const unsigned int width, const unsigned int height, const std::string name, const float *data);

};

#endif // TEXTURE_F_H
