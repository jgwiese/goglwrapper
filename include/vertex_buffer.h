#ifndef VERTEX_BUFFER_OBJECT_H
#define VERTEX_BUFFER_OBJECT_H

#include "gl.h"
#include <gassets/gassets.h>
#include <gassets/vertex.h>
#include <vector>

class t_vertex_buffer {
public:
  t_vertex_buffer(float *data, unsigned int vertices_size,
                  unsigned int attribute_size);
  ~t_vertex_buffer();
  void update(float *data, unsigned int buffer_size);
  void bind();
  void unbind();
  GLuint get_id();
  unsigned int get_vertices_size();
  unsigned int get_attribute_size();

private:
  GLuint id;
  unsigned int vertices_size, attribute_size;
};

#endif // VERTEX_BUFFER_OBJECT_H
