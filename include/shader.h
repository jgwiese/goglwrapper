#ifndef OGLWRAPPER_SHADER_H
#define OGLWRAPPER_SHADER_H

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <string>

namespace oglwrapper {
class t_shader {
public:
    GLuint id;
    t_shader(std::string path, GLenum shader_type, std::string name);
    ~t_shader();

private:
    std::string name;
    GLenum shader_type;
};
}

#endif // OGLWRAPPER_SHADER_H
