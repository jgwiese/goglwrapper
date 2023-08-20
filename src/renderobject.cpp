#include "../include/renderobject.h"


t_renderobject::t_renderobject(t_mesh *p_mesh) {
    t_vertex_buffer *p_vertex_buffer = new t_vertex_buffer(p_mesh->get_vertices());
    t_vertex_element_buffer *p_vertex_element_buffer = new t_vertex_element_buffer(p_mesh->get_indices());
    this->p_vertex_array = new t_vertex_array(p_vertex_buffer, p_vertex_element_buffer);
}

t_renderobject::~t_renderobject() {
}

void t_renderobject::draw() {
    this->p_vertex_array->bind();
    glDrawElements(GL_TRIANGLES, this->p_vertex_array->get_elements_count(), GL_UNSIGNED_INT, 0);
    this->p_vertex_array->unbind();

    // make sure that nothing else is bound anymore
    glBindTexture(GL_TEXTURE_2D, 0);
    glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, 0);
    glUseProgram(0);
}
