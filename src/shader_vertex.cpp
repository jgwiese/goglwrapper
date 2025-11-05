#include "../include/shader_vertex.h"

namespace oglwrapper {
t_shader_vertex::t_shader_vertex(std::vector<std::string> paths,
                                 std::string name)
    : t_shader(paths, GL_VERTEX_SHADER, name) {}
} // namespace oglwrapper
