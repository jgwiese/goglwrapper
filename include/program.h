#ifndef PROGRAM_H
#define PROGRAM_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <glm/glm.hpp>
#include "shader.h"


class t_program {
public:
    GLuint id;
    std::string name;
    t_program(t_shader *p_shader_vertex, t_shader *p_shader_fragment, std::string name);
    ~t_program();
    void set_float(std::string name, float v);
    void set_vec3(std::string name, glm::vec3 v);
    void set_transformation(std::string name, glm::mat4 transformation);

private:
};

#endif // PROGRAM_H

