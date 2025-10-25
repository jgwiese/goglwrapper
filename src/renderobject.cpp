#include "../include/renderobject.h"
#include <iostream>

t_renderobject::t_renderobject(t_mesh *p_mesh, glm::mat4 transformation) {
  t_vertex_buffer *p_vertex_buffer =
      new t_vertex_buffer((float *)p_mesh->get_vertices()->data(),
                          p_mesh->get_vertices()->size() * 8);
  t_vertex_element_buffer *p_vertex_element_buffer =
      new t_vertex_element_buffer(p_mesh->get_indices());
  this->p_vertex_buffer_instances =
      new t_vertex_buffer((float *)&transformation[0][0], 16);
  this->p_vertex_array =
      new t_vertex_array(p_vertex_buffer, p_vertex_element_buffer,
                         this->p_vertex_buffer_instances);
  this->instances = 1;
}

t_renderobject::~t_renderobject() {}

void t_renderobject::draw() {
  this->p_vertex_array->bind();
  // glDrawElements(GL_TRIANGLES, this->p_vertex_array->get_elements_count(),
  // GL_UNSIGNED_INT, 0);
  glDrawElementsInstanced(GL_TRIANGLES,
                          this->p_vertex_array->get_elements_count(),
                          GL_UNSIGNED_INT, 0, this->instances);
  this->p_vertex_array->unbind();

  // make sure that nothing else is bound anymore
  glBindTexture(GL_TEXTURE_2D, 0);
  glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, 0);
  glUseProgram(0);
}

void t_renderobject::update_instances(std::vector<glm::mat4> *transformations) {
  this->p_vertex_buffer_instances->update((float *)transformations->data(),
                                          transformations->size() * 16);
  this->instances = transformations->size();
}
