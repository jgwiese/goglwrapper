#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include "renderbuffer.h"
#include "texture.h"
#include "texture_ms.h"
#include "texture_ms_depth.h"
#include "texture_ub_depth.h"


class t_framebuffer {
public:
    t_framebuffer(std::string name);
    ~t_framebuffer();
    void attach_texture(t_texture *p_texture);
    void attach_texture_ms(t_texture_ms *p_texture_ms);
    void attach_texture_ms_depth(t_texture_ms_depth *p_texture_ms_depth);
    void attach_texture_ub_depth(t_texture_ub_depth *p_texture_ub_depth);
    void attach_renderbuffer(t_renderbuffer *p_renderbuffer);
    void check();
    void use();
    void reset();
    void blit(t_framebuffer *p_framebuffer, unsigned int width, unsigned int height);
    unsigned int get_id();
    t_texture *get_color_attachment(unsigned int i);
    t_texture_ub_depth *get_depth_attachment();

private:
    std::string name;
    GLuint id;
    std::vector<t_texture *> v_textures;
    t_texture_ub_depth *p_texture_ub_depth;
    std::vector<t_renderbuffer *> v_renderbuffers;
};

#endif // FRAMEBuFFER_H


