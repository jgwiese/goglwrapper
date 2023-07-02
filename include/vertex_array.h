#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "../include/vertex_buffer.h"


class t_vertex_array {
public:
    t_vertex_array();
    ~t_vertex_array();
    void bind();
    void unbind();
    void add_vertex_buffer(std::vector<unsigned int> numbers_of_elements, unsigned int element_size, t_vertex_buffer *p_vertex_buffer);
    void bind_element_buffer(t_vertex_buffer *p_vertex_buffer);
    void unbind_element_buffer(t_vertex_buffer *p_vertex_buffer);

private:
    GLuint id;
    unsigned int attributes_counter;
};

#endif // VERTEX_ARRAY_H

