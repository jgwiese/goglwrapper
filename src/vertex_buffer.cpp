#include "../include/vertex_buffer.h"
#include <glad/glad.h>
#include <iostream>


t_vertex_buffer::t_vertex_buffer(float *data, unsigned int count_size) {
    glGenBuffers(1, &this->id);
    this->update(data, count_size);
}

void t_vertex_buffer::update(float *data, unsigned int count_size) {
    this->bind();
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * count_size, data, GL_STATIC_DRAW);
    this->unbind();
}

t_vertex_buffer::~t_vertex_buffer() {
    glDeleteBuffers(1, &this->id);
}

void t_vertex_buffer::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, this->id);
}

void t_vertex_buffer::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
