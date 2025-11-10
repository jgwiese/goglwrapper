#ifndef RENDERPARTICLE_H
#define RENDERPARTICLE_H

#include "renderobject.h"
#include "vertex_array.h"
#include <glm/ext/vector_float3.hpp>
#include <vector>
class t_renderparticle : public t_renderobject {
public:
  t_renderparticle(glm::vec3 position);
  ~t_renderparticle() override;
  void draw() override;
  void update_instances(std::vector<glm::vec3> &offsets);

private:
  t_vertex_array *p_vertex_array;
  t_vertex_buffer *p_vertex_buffer_instances;
  unsigned int instances;
};

#endif // RENDERPARTICLEH
