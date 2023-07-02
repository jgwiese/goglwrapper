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

    // TODO: this does not make sense, or make these constructors
    t_shader *t_vertex_shader(std::string path, std::string name);
    t_shader *t_fragment_shader(std::string path, std::string name);

private:
    std::string name;
    GLenum shader_type;
};

#endif // SHADER_H

