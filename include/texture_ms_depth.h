#ifndef TEXTURE_MS_DEPTH_H
#define TEXTURE_MS_DEPTH_H

#include "texture.h"


class t_texture_ms_depth : public t_texture {
public:
    t_texture_ms_depth(const unsigned int width, const unsigned int height, const std::string name, const unsigned int samples);
    void use(unsigned int i) override;

private:
    unsigned int samples;
};

#endif // TEXTURE_MS_DEPTH_H

