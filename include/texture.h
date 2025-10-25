#ifndef TEXTURE_H
#define TEXTURE_H

#include "render_target.h"


class t_texture : public t_render_target{
public:
    t_texture(const unsigned int width, const unsigned int height, const std::string name, GLenum internalformat, GLenum format, void *data);
    void use(unsigned int i) override;
    void set(void *data);

private:
    GLenum internalformat;
    GLenum format;
};

#endif // TEXTURE_H
