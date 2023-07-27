#ifndef TEXTURE_UB_H
#define TEXTURE_UB_H

#include "texture.h"


class t_texture_ub : public t_texture {
public:
    t_texture_ub(const unsigned int width, const unsigned int height, const std::string name, const unsigned char *data);
    ~t_texture_ub();
    void use(unsigned int i) override;
};

#endif // TEXTURE_UB_H
