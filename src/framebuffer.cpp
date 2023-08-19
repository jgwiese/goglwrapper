#include "../include/framebuffer.h"
#include <glad/glad.h>
#include <iostream>


t_framebuffer::t_framebuffer(std::string name) {
    this->name = name;
    glGenFramebuffers(1, &this->id);
    
    std::cout << "framebuffer created, id: " << this->id << std::endl;
}

t_framebuffer::~t_framebuffer() {
    // TODO make renderbuffer be managed by resource_manager as well
    //for (unsigned int i = 0; i < this->a_renderbuffers_size; i++) {
        //delete this->a_renderbuffers[i];
    //}
}

void t_framebuffer::check() {
    this->use();
    GLenum value = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    switch(value) {
        case GL_FRAMEBUFFER_UNDEFINED:
            printf("error: framebuffer undefined\n");
            break;
        case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
            printf("error: framebuffer incomplete attachment\n");
            break;
        case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
            printf("error: framebuffer incomplete missing attachment\n");
            break;
        case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:
            printf("error: framebuffer incomplete draw buffer\n");
            break;
        case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:
            printf("error: framebuffer incomplete read buffer\n");
            break;
        case GL_FRAMEBUFFER_UNSUPPORTED:
            printf("error: framebuffer unsupported\n");
            break;
        case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE:
            printf("error: framebuffer incomplete multisample\n");
            break;
        case GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS:
            printf("error: framebuffer incomplete layer targets\n");
            break;
        default:
            printf("success: framebuffer is complete\n");
            break;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void t_framebuffer::use() {
    glBindFramebuffer(GL_FRAMEBUFFER, this->id);
}

void t_framebuffer::reset() {
    this->use();
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // depth testing
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    // blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO);

    // face culling
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    //glFrontFace(GL_CW);
    
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //glEnable(GL_MULTISAMPLE);
}

void t_framebuffer::blit(t_framebuffer *p_framebuffer, unsigned int width, unsigned int height) {
    glBindFramebuffer(GL_READ_FRAMEBUFFER, this->id);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, p_framebuffer->get_id());
    //glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
    glReadBuffer(GL_COLOR_ATTACHMENT0);
    glDrawBuffer(GL_COLOR_ATTACHMENT0);
    glBlitFramebuffer(0, 0, width, height, 0, 0, width, height, GL_COLOR_BUFFER_BIT, GL_NEAREST);
    glBlitFramebuffer(0, 0, width, height, 0, 0, width, height, GL_DEPTH_BUFFER_BIT, GL_NEAREST);
    for (unsigned int i = 1; i < this->v_textures.size(); i++) {
        glReadBuffer(GL_COLOR_ATTACHMENT0 + i);
        glDrawBuffer(GL_COLOR_ATTACHMENT0 + i);
        glBlitFramebuffer(0, 0, width, height, 0, 0, width, height, GL_COLOR_BUFFER_BIT, GL_NEAREST);
    }
    glBindFramebuffer(GL_READ_FRAMEBUFFER, 0);
    glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
}

void t_framebuffer::setup_draw_buffers() {
    this->use();
    GLenum attachments[this->v_textures.size()];
    for (unsigned int i = 0; i < this->v_textures.size(); i++) {
        attachments[i] = GL_COLOR_ATTACHMENT0 + i;
    }
    glDrawBuffers(this->v_textures.size(), attachments);
}

void t_framebuffer::attach_texture(t_texture *p_texture) {
    this->use();
    unsigned int i = this->v_textures.size();
    this->v_textures.push_back(p_texture);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, p_texture->get_id(), 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    this->setup_draw_buffers();
}

void t_framebuffer::attach_texture(t_texture_ms *p_texture_ms) {
    this->use();
    unsigned int i = this->v_textures.size();
    this->v_textures.push_back(p_texture_ms);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D_MULTISAMPLE, p_texture_ms->get_id(), 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    this->setup_draw_buffers();
}

void t_framebuffer::attach_texture_depth(t_texture_ms_depth *p_texture_depth) {
    this->use();
    this->p_texture_depth = p_texture_depth;
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D_MULTISAMPLE, p_texture_depth->get_id(), 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void t_framebuffer::attach_texture_depth(t_texture_ub_depth *p_texture_depth) {
    this->use();
    this->p_texture_depth = p_texture_depth;
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, p_texture_depth->get_id(), 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void t_framebuffer::attach_renderbuffer(t_renderbuffer *p_renderbuffer) {
    this->use();
    unsigned int i = this->v_renderbuffers.size();
    this->v_renderbuffers.push_back(p_renderbuffer);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, p_renderbuffer->id); // TODO: +i?
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    this->setup_draw_buffers();
}

unsigned int t_framebuffer::get_id() {
    return this->id;
}

t_texture *t_framebuffer::get_color_attachment(unsigned int i) {
    return this->v_textures[i];
}

t_texture *t_framebuffer::get_depth_attachment() {
    return this->p_texture_depth;
}

