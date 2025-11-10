#include "../include/vertex_element_buffer.h"

t_vertex_element_buffer::t_vertex_element_buffer(
    const std::vector<unsigned int> &v_indices) {
  this->elements_count = v_indices.size();
  glGenBuffers(1, &this->id);
  this->bind();
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * v_indices.size(),
               v_indices.data(), GL_STATIC_DRAW);
  this->unbind();
}

t_vertex_element_buffer::~t_vertex_element_buffer() {
  glDeleteBuffers(1, &this->id);
}

void t_vertex_element_buffer::bind() {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
}

void t_vertex_element_buffer::unbind() {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int t_vertex_element_buffer::get_elements_count() {
  return this->elements_count;
}

GLuint t_vertex_element_buffer::get_id() { return this->id; }
