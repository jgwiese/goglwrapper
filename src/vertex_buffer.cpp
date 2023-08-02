#include "../include/vertex_buffer.h"
#include <glad/glad.h>


t_vertex_buffer::t_vertex_buffer(std::vector<t_vertex> *v_vertices) {
    glGenBuffers(1, &this->id);
    this->bind();
    glBufferData(GL_ARRAY_BUFFER, sizeof(t_vertex) * v_vertices->size(), v_vertices->data(), GL_STATIC_DRAW);
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

std::vector<unsigned int> t_vertex_buffer::get_composition_numfloats() {
    // TODO how to prevent hardcoding of composition of t_vertex.
    return std::vector<unsigned int> {3, 3, 2};
}
