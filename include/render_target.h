#ifndef RENDER_TARGET_H
#define RENDER_TARGET_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>


class t_render_target {
public:
    t_render_target(const unsigned int width, const unsigned int height, const std::string name);
    virtual ~t_render_target();
    unsigned int get_id();
    std::string get_name();
    unsigned int get_width();
    unsigned int get_height();
    virtual void use(unsigned int i) = 0; // TODO {} or =0?

protected:
    GLuint id;
    std::string name;
    unsigned int width;
    unsigned int height;
};

#endif // RENDER_TARGET_H
