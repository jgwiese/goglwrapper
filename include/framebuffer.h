#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include "renderbuffer.h"
#include "texture.h"
#include "depth_texture.h"


class t_framebuffer {
public:
    t_framebuffer(std::string name);
    ~t_framebuffer();
    void attach_texture(t_texture *p_texture);
    void attach_depth_texture(t_depth_texture *p_depth_texture);
    void attach_renderbuffer(t_renderbuffer *p_renderbuffer);
    void check();
    void use();
    t_texture *get_color_attachment(unsigned int i);
    t_depth_texture *get_depth_attachment();

private:
    std::string name;
    GLuint id;
    std::vector<t_texture *> v_textures;
    t_depth_texture *p_depth_texture;
    std::vector<t_renderbuffer *> v_renderbuffers;
};

#endif // FRAMEBuFFER_H


