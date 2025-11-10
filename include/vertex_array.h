#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include "gl.h"
#include "vertex_buffer.h"
#include "vertex_element_buffer.h"

class t_vertex_array {
public:
  t_vertex_array();
  ~t_vertex_array();
  void add_vertex_buffer(t_vertex_buffer *p_vertex_buffer);
  void add_instance_buffer(t_vertex_buffer *p_vertex_buffer);
  void add_element_buffer(t_vertex_element_buffer *p_vertex_element_buffer);
  void bind();
  void unbind();
  GLuint get_id();

private:
  GLuint id;
  unsigned int attributes_counter;
};

#endif // VERTEX_ARRAY_H
