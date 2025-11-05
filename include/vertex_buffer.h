#ifndef VERTEX_BUFFER_OBJECT_H
#define VERTEX_BUFFER_OBJECT_H

#include "gl.h"
#include <gassets/gassets.h>
#include <vector>

class t_vertex_buffer {
public:
  // t_vertex_buffer(std::vector<t_vertex> *v_vertices);
  t_vertex_buffer(float *data, unsigned int count_size);
  ~t_vertex_buffer();
  void update(float *data, unsigned int count_size);
  void bind();
  void unbind();
  GLuint get_id();

private:
  GLuint id;
};

#endif // VERTEX_BUFFER_OBJECT_H
