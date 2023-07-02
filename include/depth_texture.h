#ifndef DEPTH_TEXTURE_H
#define DEPTH_TEXTURE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>


class t_depth_texture {
public:
    GLuint id;
    t_depth_texture(const unsigned int width, const unsigned int height, const std::string name, const unsigned char *data);
    ~t_depth_texture();
    void use();
    std::string get_name();

private:
    std::string name;
    unsigned int width;
    unsigned int height;
};

#endif // DEPTH_TEXTURE_H

