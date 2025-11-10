#include "../include/rendermesh.h"

t_rendermesh::t_rendermesh(const std::vector<t_vertex> &v_vertices,
                           const std::vector<unsigned int> &v_indices) {
  std::vector<glm::vec3> positions;
  std::vector<glm::vec3> normals;
  std::vector<glm::vec2> uvs;
  for (unsigned int i = 0; i < v_vertices.size(); i++) {
    t_vertex v = v_vertices.at(i);
    positions.push_back(v.coordinates);
    normals.push_back(v.normal);
    uvs.push_back(v.uv);
  }

  // core vertex buffer
  t_vertex_buffer *p_vertex_buffer_positions =
      new t_vertex_buffer((float *)positions.data(), positions.size(), 3);
  t_vertex_buffer *p_vertex_buffer_normals =
      new t_vertex_buffer((float *)normals.data(), normals.size(), 3);
  t_vertex_buffer *p_vertex_buffer_uvs =
      new t_vertex_buffer((float *)uvs.data(), uvs.size(), 2);

  // other buffer
  this->p_vertex_element_buffer = new t_vertex_element_buffer(v_indices);
  this->instances = 1;
  glm::mat4 transformation(1.0);
  this->p_vertex_buffer_instances =
      new t_vertex_buffer((float *)&transformation[0][0], this->instances, 16);

  // bind to vertex array
  this->p_vertex_array = new t_vertex_array();
  this->p_vertex_array->add_element_buffer(p_vertex_element_buffer);
  this->p_vertex_array->add_vertex_buffer(p_vertex_buffer_positions);
  this->p_vertex_array->add_vertex_buffer(p_vertex_buffer_normals);
  this->p_vertex_array->add_vertex_buffer(p_vertex_buffer_uvs);
  this->p_vertex_array->add_instance_buffer(p_vertex_buffer_instances);
}

t_rendermesh::~t_rendermesh() {}

void t_rendermesh::draw() {
  this->p_vertex_array->bind();
  glDrawElementsInstanced(GL_TRIANGLES,
                          this->p_vertex_element_buffer->get_elements_count(),
                          GL_UNSIGNED_INT, 0, this->instances);
  this->p_vertex_array->unbind();
  glBindTexture(GL_TEXTURE_2D, 0);
  glUseProgram(0);
}

void t_rendermesh::update_instances(std::vector<glm::mat4> &transformations) {
  this->p_vertex_buffer_instances->update((float *)transformations.data(),
                                          transformations.size() * 16);
  this->instances = transformations.size();
}
