#include "../include/shader.h"
#include <ioc/ioc.h>
#include <iostream>


t_shader::t_shader(std::string path, GLenum shader_type, std::string name) {
    this->name = name;
    char *buffer;
    if (parse_file(&buffer, path.c_str()) == 1) {
        printf("shader file empty\n");
    }
    this->id = glCreateShader(shader_type);
    glShaderSource(this->id, 1, (const GLchar **) &buffer, NULL);
    glCompileShader(this->id);
    
    GLint is_compiled = 0;
    glGetShaderiv(this->id, GL_COMPILE_STATUS, &is_compiled);
    if (is_compiled == GL_FALSE) {
        GLint max_length = 0;
        glGetShaderiv(this->id, GL_INFO_LOG_LENGTH, &max_length);
        GLchar message[max_length];
        glGetShaderInfoLog(this->id, max_length, &max_length, message);
        printf("%s", message);
        glDeleteShader(this->id);
    }

    std::cout << "shader created, id: " << this->id << std::endl;
}

t_shader::~t_shader() {

}
