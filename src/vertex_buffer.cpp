#include "../include/vertex_buffer.h"
#include "../include/gl.h"
#include <gassets/vertex.h>

t_vertex_buffer::t_vertex_buffer(float *data, unsigned int vertices_size,
                                 unsigned int attribute_size)
    : vertices_size(vertices_size), attribute_size(attribute_size) {
  glGenBuffers(1, &this->id);
  for (int i = 0; i < vertices_size * attribute_size; i++) {
  }
  this->update(data, vertices_size * attribute_size);
}

void t_vertex_buffer::update(float *data, unsigned int buffer_size) {
  this->bind();
  glBufferData(GL_ARRAY_BUFFER, sizeof(float) * buffer_size, data,
               GL_STATIC_DRAW);
  this->unbind();
}

t_vertex_buffer::~t_vertex_buffer() { glDeleteBuffers(1, &this->id); }

void t_vertex_buffer::bind() { glBindBuffer(GL_ARRAY_BUFFER, this->id); }

void t_vertex_buffer::unbind() { glBindBuffer(GL_ARRAY_BUFFER, 0); }

GLuint t_vertex_buffer::get_id() { return this->id; }

unsigned int t_vertex_buffer::get_vertices_size() {
  return this->vertices_size;
}

unsigned int t_vertex_buffer::get_attribute_size() {
  return this->attribute_size;
}
