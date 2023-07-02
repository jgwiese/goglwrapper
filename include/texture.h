#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>


class t_texture {
public:
    GLuint id;
    t_texture(const unsigned int width, const unsigned int height, const std::string name, const unsigned char *data);
    t_texture(const unsigned int width, const unsigned int height, const std::string name, const float *data);
    t_texture(const std::string path, const std::string name);
    ~t_texture();
    void use();
    std::string get_name();

private:
    std::string name;
    unsigned int width;
    unsigned int height;
};


#endif // TEXTURE_H

