#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>


class t_window {
public:
    t_window(const unsigned int width, const unsigned int height, const std::string name);
    ~t_window();
    void event();
    void update();
    bool running;
    int get_width();
    int get_height();

private:
    GLFWwindow *p_backend_window;
};

static void key_callback(GLFWwindow *p_backend_window, int key, int scancode, int action, int mods);


#endif // WINDOW_H

