#include "../include/vertex_array.h"
#include "../include/gl.h"
#include <gassets/vertex.h>
#include <glm/glm.hpp>

t_vertex_array::t_vertex_array() {
  this->attributes_counter = 0;
  glGenVertexArrays(1, &this->id);
}

void t_vertex_array::add_vertex_buffer(t_vertex_buffer *p_vertex_buffer) {
  this->bind();
  p_vertex_buffer->bind();
  glVertexAttribPointer(this->attributes_counter,
                        p_vertex_buffer->get_attribute_size(), GL_FLOAT,
                        GL_FALSE, 0, (void *)0);
  glEnableVertexAttribArray(this->attributes_counter);
  this->attributes_counter += 1;
  // p_vertex_buffer->unbind();
  this->unbind();
}

void t_vertex_array::add_instance_buffer(t_vertex_buffer *p_vertex_buffer) {
  // TODO currently assumes a glm::mat4 buffer
  this->bind();
  p_vertex_buffer->bind();
  for (unsigned int i = 0; i < 4; i++) {
    glVertexAttribPointer(this->attributes_counter, 4, GL_FLOAT, GL_FALSE,
                          4 * sizeof(glm::vec4),
                          (void *)(i * sizeof(glm::vec4)));
    glEnableVertexAttribArray(this->attributes_counter);
    glVertexAttribDivisor(this->attributes_counter, 1);
    this->attributes_counter += 1;
  }
  // p_vertex_buffer->unbind();
  this->unbind();
}

void t_vertex_array::add_element_buffer(
    t_vertex_element_buffer *p_vertex_element_buffer) {
  this->bind();
  p_vertex_element_buffer->bind();
  this->unbind();
}

t_vertex_array::~t_vertex_array() {
  glDeleteVertexArrays(1, &this->id);
  // TODO: this is probably not complete.
}

void t_vertex_array::bind() { glBindVertexArray(this->id); }

void t_vertex_array::unbind() { glBindVertexArray(0); }

GLuint t_vertex_array::get_id() { return this->id; }
