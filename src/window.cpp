#include "../include/window.h"
#include <GLFW/glfw3.h>
#include <iostream>


t_window::t_window(const unsigned int width, const unsigned int height, const std::string name) {
    if (!glfwInit()) {
        printf("glfw init failed.");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    this->p_backend_window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
    if (!(this->p_backend_window)) {
        printf("glfw window failed");
    }
    glfwMakeContextCurrent(this->p_backend_window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        printf("Failed to initialize OpenGL context.\n");
    }

    glfwSetKeyCallback(this->p_backend_window, key_callback);
    this->running = true;
    printf("%s, GLSL: %s\n", glGetString(GL_VERSION), glGetString (GL_SHADING_LANGUAGE_VERSION));
    
}

t_window::~t_window() {
    std::cout << "window destroy" << std::endl;
    glfwDestroyWindow(this->p_backend_window);
    glfwTerminate();
}

void t_window::event() {
    glfwPollEvents();
    int return_value = glfwWindowShouldClose(this->p_backend_window);
    if (return_value) {
        this->running = false;
    }
}

void t_window::update() {
    glfwSwapBuffers(this->p_backend_window);
}

int t_window::get_width() {
    int width;
    int tmp;
    glfwGetWindowSize(this->p_backend_window, &width, &tmp);
    return width;
}

int t_window::get_height() {
    int height;
    int tmp;
    glfwGetWindowSize(this->p_backend_window, &tmp, &height);
    return height;
}

static void key_callback(GLFWwindow *p_backend_window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(p_backend_window, GLFW_TRUE);
}

