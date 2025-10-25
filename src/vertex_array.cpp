#include "../include/vertex_array.h"
#include <gassets/vertex.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <iostream>

t_vertex_array::t_vertex_array(t_vertex_buffer *p_vertex_buffer,
                               t_vertex_element_buffer *p_vertex_element_buffer,
                               t_vertex_buffer *p_vertex_buffer_instances) {
  this->attributes_counter = 0;
  this->p_vertex_buffer = p_vertex_buffer;
  this->p_vertex_element_buffer = p_vertex_element_buffer;

  glGenVertexArrays(1, &this->id);
  this->bind();

  unsigned long stride = 0;
  unsigned long stride_tmp = 0;

  // TODO remove hardcoded compositions and also instances composition somehow.
  std::vector<unsigned int> composition_numfloats = {3, 3, 2};

  for (unsigned int i = 0; i < composition_numfloats.size(); i++) {
    stride += composition_numfloats[i];
  }

  p_vertex_buffer->bind();
  p_vertex_element_buffer->bind();

  for (unsigned int i = 0; i < composition_numfloats.size(); i++) {
    glVertexAttribPointer(this->attributes_counter, composition_numfloats[i],
                          GL_FLOAT, GL_FALSE, sizeof(float) * stride,
                          (void *)(stride_tmp * sizeof(float)));
    glEnableVertexAttribArray(this->attributes_counter);
    stride_tmp += composition_numfloats[i];
    this->attributes_counter += 1;
  }

  // instance buffer
  p_vertex_buffer_instances->bind();
  for (unsigned int i = 0; i < 4; i++) {
    glVertexAttribPointer(this->attributes_counter, 4, GL_FLOAT, GL_FALSE,
                          4 * sizeof(glm::vec4),
                          (void *)(i * sizeof(glm::vec4)));
    glEnableVertexAttribArray(this->attributes_counter);
    glVertexAttribDivisor(this->attributes_counter, 1);
    this->attributes_counter += 1;
  }

  this->unbind();
}

t_vertex_array::~t_vertex_array() {
  glDeleteVertexArrays(1, &this->id);
  // TODO: this is probably not complete.
}

void t_vertex_array::bind() { glBindVertexArray(this->id); }

void t_vertex_array::unbind() { glBindVertexArray(0); }

unsigned int t_vertex_array::get_elements_count() {
  return this->p_vertex_element_buffer->get_elements_count();
}

GLuint t_vertex_array::get_id() { return this->id; }
