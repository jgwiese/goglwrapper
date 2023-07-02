#include "../include/vertex_array.h"
#include <gassets/vertex.h>
#include <glad/glad.h>


t_vertex_array::t_vertex_array() {
    glGenVertexArrays(1, &this->id);
    glBindVertexArray(this->id);
    
    glEnableVertexAttribArray(3);

    // here: bind instancing buffer
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void *) 0);
    glVertexAttribDivisor(3, 1);
}

t_vertex_array::~t_vertex_array() {
    glDeleteVertexArrays(1, &this->id);
    // TODO: this is probably not complete.
}

void t_vertex_array::bind() {
    glBindVertexArray(this->id);
}

void t_vertex_array::unbind() {
    glBindVertexArray(0);
}

void t_vertex_array::add_vertex_buffer(std::vector<unsigned int> numbers_of_elements, unsigned int element_size, t_vertex_buffer *p_vertex_buffer) {
    unsigned long stride = 0;
    unsigned long stride_tmp = 0;

    for (unsigned int i = 0; i < numbers_of_elements.size(); i++) {
        stride += numbers_of_elements[i];
    }

    p_vertex_buffer->bind();
    for (unsigned int i = 0; i < numbers_of_elements.size(); i++) {
        glVertexAttribPointer(this->attributes_counter, numbers_of_elements[i], GL_FLOAT, GL_FALSE, element_size * stride, (void *) (stride_tmp * element_size));
        glEnableVertexAttribArray(this->attributes_counter);
        stride_tmp += numbers_of_elements[i];
        this->attributes_counter += 1;
    }
    p_vertex_buffer->unbind();
}

void t_vertex_array::bind_element_buffer(t_vertex_buffer *p_vertex_buffer) {
    this->bind();
    p_vertex_buffer->bind();
    this->unbind();
}

void t_vertex_array::unbind_element_buffer(t_vertex_buffer *p_vertex_buffer) {
    this->bind();
    p_vertex_buffer->unbind();
    this->unbind();
}

//void t_vertex_array::add_instances_buffer() {
//}
