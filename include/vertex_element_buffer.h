#ifndef VERTEX_ELEMENT_BUFFER
#define VERTEX_ELEMENT_BUFFER

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>


class t_vertex_element_buffer {
public:
    t_vertex_element_buffer(std::vector<unsigned int> *v_indices);
    ~t_vertex_element_buffer();
    void bind();
    void unbind();
    unsigned int get_elements_count();

private:
    GLuint id;
    unsigned int elements_count;
};

#endif // VERTEX_ELEMENT_BUFFER 
