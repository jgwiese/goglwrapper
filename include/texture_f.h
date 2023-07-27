#ifndef TEXTURE_F_H
#define TEXTURE_F_H


#include "texture.h"

class t_texture_f : public t_texture{
public:
    // TODO: what about channels
    t_texture_f(const unsigned int width, const unsigned int height, const std::string name, const float *data);
    void use(unsigned int i) override;
    static t_texture_f* from_image(std::string path, std::string name);
};

#endif // TEXTURE_F_H
