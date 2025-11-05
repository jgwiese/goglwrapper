#include "../include/texture_ms.h"

// t_texture_ms::t_texture_ms(const unsigned int width, const unsigned int
// height,
//                            const std::string name, unsigned int samples,
//                            GLenum internalformat)
//     : t_render_target(width, height, name), samples(samples) {
//   glGenTextures(1, &this->id);
//   glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, this->id);
//   glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, this->samples,
//                           internalformat, width, height, GL_TRUE);
//   glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, 0);
// }
//
// void t_texture_ms::use(unsigned int i) {
//   glActiveTexture(GL_TEXTURE0 + i);
//   glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, this->id);
// }
