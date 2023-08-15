#ifndef OGLWRAPPER_SHADER_VERTEX_H
#define OGLWRAPPER_SHADER_VERTEX_H

#include "shader.h"


namespace oglwrapper {
class t_shader_vertex : public t_shader{
public:
    t_shader_vertex(std::string path, std::string name);
};
}

#endif // OGLWRAPPER_SHADER_VERTEX_H
