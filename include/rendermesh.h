#ifndef RENDERMESH_H
#define RENDERMESH_H

#include "gl.h"
#include "renderobject.h"
#include "vertex_array.h"
#include "vertex_element_buffer.h"
#include <gassets/vertex.h>
#include <vector>

class t_rendermesh : public t_renderobject {
public:
  t_rendermesh(const std::vector<t_vertex> &v_vertices,
               const std::vector<unsigned int> &v_indices);
  ~t_rendermesh() override;
  void draw() override;
  void update_instances(std::vector<glm::mat4> &transformations);

private:
  t_vertex_array *p_vertex_array;
  t_vertex_buffer *p_vertex_buffer_instances;
  t_vertex_element_buffer *p_vertex_element_buffer;
  unsigned int instances;
};

#endif // RENDERMESH_H
