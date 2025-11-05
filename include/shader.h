#ifndef OGLWRAPPER_SHADER_H
#define OGLWRAPPER_SHADER_H

#include "gl.h"
#include <string>
#include <vector>

namespace oglwrapper {
class t_shader {
public:
  GLuint id;
  t_shader(std::vector<std::string> paths, GLenum shader_type,
           std::string name);
  ~t_shader();

private:
  std::string name;
  GLenum shader_type;
};
} // namespace oglwrapper

#endif // OGLWRAPPER_SHADER_H
