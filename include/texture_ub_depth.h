#ifndef TEXTURE_UB_DEPTH_H
#define TEXTURE_UB_DEPTH_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>


class t_texture_ub_depth {
public:
    GLuint id;
    t_texture_ub_depth(const unsigned int width, const unsigned int height, const std::string name, const unsigned char *data);
    ~t_texture_ub_depth();
    void use();
    std::string get_name();

private:
    std::string name;
    unsigned int width;
    unsigned int height;
};

#endif // TEXTURE_UB_DEPTH_H

