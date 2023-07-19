#include "../include/renderobject.h"
#include <glad/glad.h>
#include <stdlib.h>
#include <string>
#include <glm/gtx/string_cast.hpp>
#include <iostream>


t_renderobject::t_renderobject(t_mesh *p_mesh) {
    this->indices_size = p_mesh->get_indices()->size();

    // Generate buffers
    glGenVertexArrays(1, &this->vao);
    glGenBuffers(1, &this->vbo);
    glGenBuffers(1, &this->ibo);

    // Bind buffers and upload data
    glBindVertexArray(this->vao);
    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(t_vertex) * p_mesh->get_vertices()->size(), p_mesh->get_vertices()->data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * p_mesh->get_indices()->size(), p_mesh->get_indices()->data(), GL_STATIC_DRAW);

    // Configure vertex attribute pointers
    glEnableVertexAttribArray(0); // TODO: 0, 1, 2 are kind of fixed assumptions for position, normal, uv... unified way?
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void *) 0); // NULL?
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void *) (6 * sizeof(float)));

    glBindVertexArray(0);
    
    std::cout << "renderobject created, vao: " << this->vao << ", vbo " << this->vbo << ", ibo " << this->ibo << std::endl;
}

t_renderobject::~t_renderobject() {
    glDeleteBuffers(1, &this->ibo);
    glDeleteBuffers(1, &this->vbo);
    glDeleteVertexArrays(1, &this->vao);
}

void t_renderobject::draw(t_program *p_program, t_texture *p_texture) {
    glUseProgram(p_program->id);
    if (p_texture != NULL) {
        GLint tmp = glGetUniformLocation(p_program->id, p_texture->get_name().c_str());
        glUniform1i(tmp, 0);
        glActiveTexture(GL_TEXTURE0);
        // TODO: how to decide when to bind multisample vs normal texture?
        glBindTexture(GL_TEXTURE_2D, p_texture->get_id());
        //glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, p_texture->get_id());
    }
    glBindVertexArray(this->vao);
    glDrawElements(GL_TRIANGLES, this->indices_size, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
    //glBindTexture(GL_TEXTURE_2D_MULTISAMPLE, 0);
    glUseProgram(0);
}

unsigned int t_renderobject::get_indices_size() {
    return this->indices_size;
}
