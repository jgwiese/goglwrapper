#ifndef VERTEX_BUFFER_OBJECT_H
#define VERTEX_BUFFER_OBJECT_H


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <gassets/gassets.h>


class t_vertex_buffer {
public:
    t_vertex_buffer(void *p_data, unsigned long data_size, bool element_data);
    ~t_vertex_buffer();
    void bind();
    void unbind();

private:
    GLuint id;
    bool element_data;
};


#endif // VERTEX_BUFFER_OBJECT_H

