#include "../include/program.h"
#include <glad/glad.h>
#include <string>
#include <iostream>


namespace oglwrapper {
t_program::t_program(t_shader *p_shader_vertex, t_shader *p_shader_fragment, std::string name) {
    this->id = glCreateProgram();
    this->name = name;
    glAttachShader(this->id, p_shader_vertex->id);
    glAttachShader(this->id, p_shader_fragment->id);
    glLinkProgram(this->id);

    std::cout << "program created, id: " << this->id << std::endl;
}

t_program::~t_program() {

}

void t_program::use() {
    glUseProgram(this->id);
}

void t_program::set_bool(std::string name, bool v) {
    this->use();
    if (v)
        glUniform1i(glGetUniformLocation(this->id, name.c_str()), 1);
    else
        glUniform1i(glGetUniformLocation(this->id, name.c_str()), 0);
    //glUseProgram(0);
}

void t_program::set_float(std::string name, float v) {
    this->use();
    glUniform1f(glGetUniformLocation(this->id, name.c_str()), v);
    //glUseProgram(0);
}

void t_program::set_uint(std::string name, unsigned int v) {
    this->use();
    glUniform1ui(glGetUniformLocation(this->id, name.c_str()), v);
}

void t_program::set_vec3(std::string name, glm::vec3 v) {
    this->use();
    glUniform3fv(glGetUniformLocation(this->id, name.c_str()), 1, &v[0]);
    //glUseProgram(0);
}

void t_program::set_transformation(std::string name, glm::mat4 transformation) {
    this->use();
    glUniformMatrix4fv(glGetUniformLocation(this->id, name.c_str()), 1, GL_FALSE, &transformation[0][0]);
    //glUseProgram(0);
}

void t_program::set_texture(t_texture *p_texture, unsigned int i) {
    this->use();
    glUniform1i(glGetUniformLocation(this->id, p_texture->get_name().c_str()), i);
    //glUseProgram(0);
}

unsigned int t_program::get_id() {
    return this->id;
}

std::string t_program::get_name() {
    return this->name;
}
}
