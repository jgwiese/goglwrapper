#include "../include/renderbuffer.h"


t_renderbuffer::t_renderbuffer(const int width, const int height) {
    glGenRenderbuffers(1, &this->id);
    glBindRenderbuffer(GL_RENDERBUFFER, this->id);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
}

t_renderbuffer::~t_renderbuffer() {

}

