#ifndef VERTEX_ELEMENT_BUFFER
#define VERTEX_ELEMENT_BUFFER

#include "gl.h"
#include <vector>

class t_vertex_element_buffer {
public:
  t_vertex_element_buffer(std::vector<unsigned int> *v_indices);
  ~t_vertex_element_buffer();
  void bind();
  void unbind();
  unsigned int get_elements_count();
  GLuint get_id();

private:
  GLuint id;
  unsigned int elements_count;
};

#endif // VERTEX_ELEMENT_BUFFER
