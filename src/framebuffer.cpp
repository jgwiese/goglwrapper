#include "../include/framebuffer.h"
#include <iostream>
#include <string>

t_framebuffer::t_framebuffer(std::string name, glm::vec4 color_clear)
    : name(name), color_clear(color_clear) {
  std::cout << "name: " << name << std::endl;
  if (this->name.compare("default") != 0) {
    glGenFramebuffers(1, &this->id);
    // this->id = 0;
  }
  this->use();

  // depth testing
  glEnable(GL_DEPTH_TEST);
  // glDepthFunc(GL_LESS);
  glDepthFunc(GL_LEQUAL);

  // blending
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  // glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO);

  // face culling
  // glEnable(GL_CULL_FACE);
  // glFrontFace(GL_CCW);
  // this->cull_face_back();

  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  // glEnable(GL_MULTISAMPLE);
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

t_framebuffer::~t_framebuffer() {
  // TODO make renderbuffer be managed by resource_manager as well
  // for (unsigned int i = 0; i < this->a_renderbuffers_size; i++) {
  // delete this->a_renderbuffers[i];
  //}
}

void t_framebuffer::check() {
  this->use();
  GLenum value = glCheckFramebufferStatus(GL_FRAMEBUFFER);
  switch (value) {
  case GL_FRAMEBUFFER_UNDEFINED:
    std::cout << "error: framebuffer undefined" << std::endl;
    break;
  case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:
    std::cout << "error: framebuffer incomplete attachment" << std::endl;
    break;
  case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:
    std::cout << "error: framebuffer incomplete missing attachment"
              << std::endl;
    break;
  // case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:
  //   std::cout << "error: framebuffer incomplete draw buffer" << std::endl;
  //   break;
  // case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:
  //   std::cout << "error: framebuffer incomplete read buffer" << std::endl;
  //   break;
  case GL_FRAMEBUFFER_UNSUPPORTED:
    std::cout << "error: framebuffer unsupported" << std::endl;
    break;
  case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE:
    std::cout << "error: framebuffer incomplete multisample" << std::endl;
    break;
  // case GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS:
  //   std::cout << "error: framebuffer incomplete layer targets" << std::endl;
  //   break;
  default:
    std::cout << "success: framebuffer is complete" << std::endl;
    break;
  }

  glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void t_framebuffer::use() {
  glBindFramebuffer(GL_FRAMEBUFFER, this->id);
  glClearColor(this->color_clear.x, this->color_clear.y, this->color_clear.z,
               this->color_clear.w);
}

void t_framebuffer::clear() {
  this->use();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void t_framebuffer::set_viewport(unsigned int width, unsigned int height) {
  glViewport(0, 0, width, height);
}

void t_framebuffer::set_depth_mask(bool value) {
  glDepthMask((GLboolean)value);
}

// void t_framebuffer::blit(t_framebuffer *p_framebuffer, unsigned int width,
//                          unsigned int height) {
//   glBindFramebuffer(GL_READ_FRAMEBUFFER, this->id);
//   glBindFramebuffer(GL_DRAW_FRAMEBUFFER, p_framebuffer->get_id());
//   // glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
//   glReadBuffer(GL_COLOR_ATTACHMENT0);
//   glDrawBuffer(GL_COLOR_ATTACHMENT0);
//   glBlitFramebuffer(0, 0, width, height, 0, 0, width, height,
//                     GL_COLOR_BUFFER_BIT, GL_NEAREST);
//   glBlitFramebuffer(0, 0, width, height, 0, 0, width, height,
//                     GL_DEPTH_BUFFER_BIT, GL_NEAREST);
//   for (unsigned int i = 1; i < this->v_render_targets.size(); i++) {
//     glReadBuffer(GL_COLOR_ATTACHMENT0 + i);
//     glDrawBuffer(GL_COLOR_ATTACHMENT0 + i);
//     glBlitFramebuffer(0, 0, width, height, 0, 0, width, height,
//                       GL_COLOR_BUFFER_BIT, GL_NEAREST);
//   }
//   glBindFramebuffer(GL_READ_FRAMEBUFFER, 0);
//   glBindFramebuffer(GL_DRAW_FRAMEBUFFER, 0);
// }

void t_framebuffer::setup_draw_buffers() {
  // TODO make renderbuffer and texture parent class.
  this->use();
  GLenum attachments[this->v_render_targets.size()];
  for (unsigned int i = 0; i < this->v_render_targets.size(); i++) {
    attachments[i] = GL_COLOR_ATTACHMENT0 + i;
  }
  glDrawBuffers(this->v_render_targets.size(), attachments);
}

// void t_framebuffer::disable_draw_buffer() {
//   this->use();
//   glDrawBuffer(GL_NONE);
// }

void t_framebuffer::disable_read_buffer() {
  this->use();
  glReadBuffer(GL_NONE);
}

void t_framebuffer::attach_render_target_color(t_texture *p_texture) {
  unsigned int i = this->v_render_targets.size();
  this->v_render_targets.push_back(p_texture);
  this->set_render_target_color(i, p_texture);
  this->setup_draw_buffers();
}

void t_framebuffer::set_render_target_color(unsigned int i,
                                            t_texture *p_texture) {
  this->use();
  glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i,
                         GL_TEXTURE_2D, p_texture->get_id(), 0);
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

// void t_framebuffer::attach_render_target_color(t_texture_ms *p_texture) {
//   this->use();
//   unsigned int i = this->v_render_targets.size();
//   this->v_render_targets.push_back(p_texture);
//   glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i,
//                          GL_TEXTURE_2D_MULTISAMPLE, p_texture->get_id(), 0);
//   glBindFramebuffer(GL_FRAMEBUFFER, 0);
//   this->setup_draw_buffers();
// }

void t_framebuffer::attach_render_target_depth(t_texture_depth *p_texture) {
  this->use();
  this->p_render_target_depth = p_texture;
  glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D,
                         p_texture->get_id(), 0);
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

// void t_framebuffer::attach_render_target_depth(t_texture_ms_depth *p_texture)
// {
//   this->use();
//   this->p_render_target_depth = p_texture;
//   glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,
//                          GL_TEXTURE_2D_MULTISAMPLE, p_texture->get_id(), 0);
//   glBindFramebuffer(GL_FRAMEBUFFER, 0);
// }

void t_framebuffer::attach_render_target_depth(
    t_renderbuffer_ms_depth *p_renderbuffer) {
  this->use();
  this->p_render_target_depth = p_renderbuffer;
  glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,
                            GL_RENDERBUFFER, p_renderbuffer->get_id());
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void t_framebuffer::attach_render_target_depth(
    t_renderbuffer_ms_depth_stencil *p_renderbuffer) {
  this->use();
  this->p_render_target_depth = p_renderbuffer;
  glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT,
                            GL_RENDERBUFFER, p_renderbuffer->get_id());
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

unsigned int t_framebuffer::get_id() { return this->id; }

t_render_target *t_framebuffer::get_color_attachment(unsigned int i) {
  return this->v_render_targets[i];
}

t_render_target *t_framebuffer::get_depth_attachment() {
  return this->p_render_target_depth;
}

void t_framebuffer::cull_face_front() {
  glEnable(GL_CULL_FACE);
  glCullFace(GL_FRONT);
}

void t_framebuffer::cull_face_back() {
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
}

void t_framebuffer::cull_face_disable() { glDisable(GL_CULL_FACE); }
