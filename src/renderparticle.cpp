#include "../include/renderparticle.h"
#include <glm/ext/vector_float3.hpp>

t_renderparticle::t_renderparticle(glm::vec3 position) {

  std::vector<glm::vec3> positions;
  positions.push_back(position);
  std::vector<glm::vec3> normals;
  normals.push_back(glm::vec3(0.0f, 0.0f, 1.0f));
  std::vector<glm::vec2> uvs;
  uvs.push_back(glm::vec2(0.0f, 0.0f));

  // core vertex buffer
  t_vertex_buffer *p_vertex_buffer_positions =
      new t_vertex_buffer((float *)positions.data(), positions.size(), 3);
  t_vertex_buffer *p_vertex_buffer_normals =
      new t_vertex_buffer((float *)normals.data(), normals.size(), 3);
  t_vertex_buffer *p_vertex_buffer_uvs =
      new t_vertex_buffer((float *)uvs.data(), uvs.size(), 2);

  // other buffer
  glm::mat4 transformation(1.0f);
  this->instances = 1;
  this->p_vertex_buffer_instances =
      new t_vertex_buffer((float *)&transformation[0][0], this->instances, 16);

  // bind to vertex array
  this->p_vertex_array = new t_vertex_array();
  this->p_vertex_array->add_vertex_buffer(p_vertex_buffer_positions);
  this->p_vertex_array->add_vertex_buffer(p_vertex_buffer_normals);
  this->p_vertex_array->add_vertex_buffer(p_vertex_buffer_uvs);
  this->p_vertex_array->add_instance_buffer(this->p_vertex_buffer_instances);
}

t_renderparticle::~t_renderparticle() {}

void t_renderparticle::draw() {
  this->p_vertex_array->bind();
  glDrawArraysInstanced(GL_POINTS, 0, 1, this->instances);
  this->p_vertex_array->unbind();
  glUseProgram(0);
}

void t_renderparticle::update_instances(std::vector<glm::vec3> &offsets) {
  this->p_vertex_buffer_instances->update((float *)offsets.data(),
                                          offsets.size() * 3);
  this->instances = offsets.size();
}
