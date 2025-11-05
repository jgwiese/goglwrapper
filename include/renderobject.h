#ifndef RENDEROBJECT_H
#define RENDEROBJECT_H

#include "gl.h"
#include "vertex_array.h"

class t_renderobject {
public:
  t_renderobject(t_mesh *p_mesh, glm::mat4 transformation);
  ~t_renderobject();
  void draw();
  void update_instances(std::vector<glm::mat4> *transformations);

private:
  t_vertex_array *p_vertex_array;
  t_vertex_buffer *p_vertex_buffer_instances;
  unsigned int instances;
};

#endif // RENDEROBJECT_H
