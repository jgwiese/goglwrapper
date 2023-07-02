#include "../include/framebuffer.h"
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
    glBindFramebuffer(GL_FRAMEBUFFER, this->id);
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        printf("error: framebuffer is not complete\n");
    else
        printf("success: framebuffer is complete\n");
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void t_framebuffer::use() {
    glBindFramebuffer(GL_FRAMEBUFFER, this->id);
}

void t_framebuffer::attach_texture(t_texture *p_texture) {
    glBindFramebuffer(GL_FRAMEBUFFER, this->id);
    unsigned int i = this->v_textures.size();
    this->v_textures.push_back(p_texture);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, p_texture->id, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void t_framebuffer::attach_depth_texture(t_depth_texture *p_depth_texture) {
    // TODO: what was i thinking here?
    /*
    if (this->p_depth_texture != NULL) {
        this->p_depth_texture->~t_depth_texture(); // TODO: is this right usage of destructor?
    }
    */
    glBindFramebuffer(GL_FRAMEBUFFER, this->id);
    unsigned int i = this->v_textures.size();
    this->p_depth_texture = p_depth_texture;
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, p_depth_texture->id, 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void t_framebuffer::attach_renderbuffer(t_renderbuffer *p_renderbuffer) {
    glBindFramebuffer(GL_FRAMEBUFFER, this->id);
    unsigned int i = this->v_renderbuffers.size();
    this->v_renderbuffers.push_back(p_renderbuffer);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, p_renderbuffer->id); // TODO: +i?
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

t_texture *t_framebuffer::get_color_attachment(unsigned int i) {
    return this->v_textures[i];
}

t_depth_texture *t_framebuffer::get_depth_attachment() {
    return this->p_depth_texture;
}

