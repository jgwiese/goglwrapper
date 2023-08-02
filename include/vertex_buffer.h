#ifndef VERTEX_BUFFER_OBJECT_H
#define VERTEX_BUFFER_OBJECT_H


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <gassets/gassets.h>


class t_vertex_buffer {
public:
    t_vertex_buffer(std::vector<t_vertex> *v_vertices);
    ~t_vertex_buffer();
    void bind();
    void unbind();
    std::vector<unsigned int> get_composition_numfloats();

private:
    GLuint id;
};


#endif // VERTEX_BUFFER_OBJECT_H

