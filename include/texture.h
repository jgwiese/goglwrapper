#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>


class t_texture {
public:
    t_texture(const unsigned int width, const unsigned int height, const std::string name);
    unsigned int get_id();
    std::string get_name();
    unsigned int get_width();
    unsigned int get_height();
    void use();

protected:
    GLuint id;
    std::string name;
    unsigned int width;
    unsigned int height;
};


#endif // TEXTURE_H

