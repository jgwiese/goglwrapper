#ifndef TEXTURE_CUBEMAP_H
#define TEXTURE_CUBEMAP_H

#include <vector>
#include "render_target.h"
#include "texture_color.h"


// TODO actually it is not a render target as far as i know
class t_texture_cubemap : public t_render_target {
public:
    t_texture_cubemap(std::string name, std::vector<std::string> paths);
    void use(unsigned int i) override;

private:
    t_texture_color *a_textures[6];
};

#endif // TEXTURE_CUBEMAP_H
