#ifndef SHADER_H
#define SHADER_H

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <string>


class t_shader {
public:
    GLuint id;
    t_shader(std::string path, GLenum shader_type, std::string name);
    ~t_shader();

private:
    std::string name;
    GLenum shader_type;
};

#endif // SHADER_H

