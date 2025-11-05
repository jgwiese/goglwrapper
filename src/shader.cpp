#include "../include/shader.h"
#include <ioc/ioc.h>

namespace oglwrapper {
t_shader::t_shader(std::vector<std::string> paths, GLenum shader_type,
                   std::string name) {
  this->name = name;
  GLchar *sources[paths.size()];
  for (unsigned int i = 0; i < paths.size(); i++) {
    char *buffer;
    if (parse_file(&buffer, paths[i].c_str()) == 1) {
      printf("shader file empty\n");
    }
    sources[i] = (GLchar *)buffer;
  }

  this->id = glCreateShader(shader_type);
  glShaderSource(this->id, paths.size(), sources, NULL);
  glCompileShader(this->id);

  GLint is_compiled = 0;
  glGetShaderiv(this->id, GL_COMPILE_STATUS, &is_compiled);
  if (is_compiled == GL_FALSE) {
    GLint max_length = 0;
    glGetShaderiv(this->id, GL_INFO_LOG_LENGTH, &max_length);
    GLchar message[max_length];
    glGetShaderInfoLog(this->id, max_length, &max_length, message);
    printf("not compiled: %s", message);
    glDeleteShader(this->id);
  }
}

t_shader::~t_shader() {}
} // namespace oglwrapper
