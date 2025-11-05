#ifndef OGLWRAPPER_SHADER_VERTEX_H
#define OGLWRAPPER_SHADER_VERTEX_H

#include "shader.h"

namespace oglwrapper {
class t_shader_vertex : public t_shader {
public:
  t_shader_vertex(std::vector<std::string> paths, std::string name);
};
} // namespace oglwrapper

#endif // OGLWRAPPER_SHADER_VERTEX_H
