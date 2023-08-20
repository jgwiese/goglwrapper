#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "vertex_array.h"


class t_renderobject {
public:
    t_renderobject(t_mesh *p_mesh);
    ~t_renderobject();
    void draw();
    unsigned int get_indices_size();

private:
    t_vertex_array *p_vertex_array;
};

#endif // RENDEROBJECT_H

