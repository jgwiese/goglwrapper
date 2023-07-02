#ifndef RENDERBUFFER_H
#define RENDERBUFFER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>


class t_renderbuffer {
public:
    GLuint id;
    t_renderbuffer(const int width, const int height);
    ~t_renderbuffer();
};

#endif // RENDERBUFFER_H

