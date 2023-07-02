#include "../include/vertex_buffer.h"
#include <glad/glad.h>


t_vertex_buffer::t_vertex_buffer(void *p_data, unsigned long data_size, bool element_data) {
    this->element_data = element_data;
    glGenBuffers(1, &this->id);

    this->bind();
    if (this->element_data)
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, data_size, p_data, GL_STATIC_DRAW);
    else
        glBufferData(GL_ARRAY_BUFFER, data_size, p_data, GL_STATIC_DRAW);
    this->unbind();
}

t_vertex_buffer::~t_vertex_buffer() {
    glDeleteBuffers(1, &this->id);
}

void t_vertex_buffer::bind() {
    if (this->element_data)
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
    else
        glBindBuffer(GL_ARRAY_BUFFER, this->id);
}

void t_vertex_buffer::unbind() {
    if (this->element_data)
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    else
        glBindBuffer(GL_ARRAY_BUFFER, 0);
}

