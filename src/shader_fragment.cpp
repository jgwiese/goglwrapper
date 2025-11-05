#include "../include/shader_fragment.h"

namespace oglwrapper {
t_shader_fragment::t_shader_fragment(std::vector<std::string> paths,
                                     std::string name)
    : t_shader(paths, GL_FRAGMENT_SHADER, name) {}
} // namespace oglwrapper
