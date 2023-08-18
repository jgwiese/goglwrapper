#ifndef OGLWRAPPER_SHADER_FRAGMENT_H
#define OGLWRAPPER_SHADER_FRAGMENT_H

#include "shader.h"


namespace oglwrapper {
class t_shader_fragment : public t_shader{
public:
    t_shader_fragment(std::vector<std::string> paths, std::string name);
};
}

#endif // OGLWRAPPER_SHADER_FRAGMENT_H
