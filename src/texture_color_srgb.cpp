#include "../include/texture_color_srgb.h"
#include <gassets/gassets.h>

// t_texture_color_srgb::t_texture_color_srgb(const unsigned int width,
//                                            const unsigned int height,
//                                            const std::string name,
//                                            const float *data)
//     : t_texture(width, height, name, GL_RGB_ALPHA, GL_RGBA, (void *)data) {}
//
// t_texture_color_srgb *t_texture_color_srgb::from_image(std::string path,
//                                                        std::string name) {
//   t_image *p_image = t_image::from_file(path);
//   t_texture_color_srgb *p_texture = new t_texture_color_srgb(
//       p_image->get_width(), p_image->get_height(), name,
//       p_image->get_data());
//   return p_texture;
// }
