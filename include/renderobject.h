#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <gassets/gassets.h>
#include "program.h"
#include "texture.h"


class t_renderobject {
public:
    t_renderobject(t_mesh *p_mesh);
    ~t_renderobject();
    void draw();
    unsigned int get_indices_size();

private:
    GLuint vao;
    GLuint vbo;
    GLuint ibo;
    unsigned int indices_size; // TODO: technially, this should not have the a_.
};

#endif // RENDEROBJECT_H

