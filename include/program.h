#ifndef OGLWRAPPER_PROGRAM_H
#define OGLWRAPPER_PROGRAM_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <glm/glm.hpp>
#include "shader.h"
#include "texture.h"
#include "texture_cubemap.h"


namespace oglwrapper {
class t_program {
public:
    t_program(t_shader *p_shader_vertex, t_shader *p_shader_fragment, std::string name);
    ~t_program();
    void use();
    void set_bool(std::string name, bool v);
    void set_uint(std::string name, unsigned int v);
    void set_float(std::string name, float v);
    void set_vec3(std::string name, glm::vec3 v);
    void set_transformation(std::string name, glm::mat4 transformation);
    void set_texture(t_texture *p_texture, unsigned int i);
    void set_texture(t_texture_cubemap *p_texture, unsigned int i);
    unsigned int get_id();
    std::string get_name();

private:
    GLuint id;
    std::string name;
};
}

#endif // OGLWRAPPER_PROGRAM_H
