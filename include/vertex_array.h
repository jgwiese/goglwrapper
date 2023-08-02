#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "vertex_buffer.h"
#include "vertex_element_buffer.h"


class t_vertex_array {
public:
    t_vertex_array(t_vertex_buffer *p_vertex_buffer, t_vertex_element_buffer *p_vertex_element_buffer);
    ~t_vertex_array();
    void bind();
    void unbind();
    unsigned int get_elements_count();

private:
    GLuint id;
    unsigned int attributes_counter;
    t_vertex_buffer *p_vertex_buffer;
    t_vertex_element_buffer *p_vertex_element_buffer;
};

#endif // VERTEX_ARRAY_H

