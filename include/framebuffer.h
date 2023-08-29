#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <vector>
#include "render_target.h"
#include "texture.h"
#include "texture_ms.h"
#include "texture_depth.h"
#include "texture_ms_depth.h"
#include "renderbuffer_ms_depth.h"
#include "renderbuffer_ms_depth_stencil.h"



class t_framebuffer {
public:
    t_framebuffer(std::string name);
    ~t_framebuffer();
    void setup_draw_buffers();
    void disable_draw_buffer();
    void disable_read_buffer();
    void attach_render_target_color(t_texture *p_texture);
    void attach_render_target_color(t_texture_ms *p_texture);
    void attach_render_target_depth(t_texture_depth *p_texture);
    void attach_render_target_depth(t_texture_ms_depth *p_texture);
    void attach_render_target_depth(t_renderbuffer_ms_depth *p_renderbuffer);
    void attach_render_target_depth(t_renderbuffer_ms_depth_stencil *p_renderbuffer);
    void check();
    void use();
    void reset();
    void cull_face_disable();
    void cull_face_front();
    void cull_face_back();
    void set_viewport(unsigned int width, unsigned int height);
    void set_depth_mask(bool value);
    void blit(t_framebuffer *p_framebuffer, unsigned int width, unsigned int height);
    unsigned int get_id();
    t_render_target *get_color_attachment(unsigned int i);
    t_render_target *get_depth_attachment();

private:
    std::string name;
    GLuint id;
    std::vector<t_render_target *> v_render_targets;
    t_render_target *p_render_target_depth;
};

#endif // FRAMEBuFFER_H


