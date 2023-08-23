#ifndef OGLWRAPPER_SHADER_GEOMETRY_H
#define OGLWRAPPER_SHADER_GEOMETRY_H

#include "shader.h"


namespace oglwrapper {
class t_shader_geometry : public t_shader{
public:
    t_shader_geometry(std::vector<std::string> paths, std::string name);
};
}

#endif // OGLWRAPPER_SHADER_GEOMETRY_H
