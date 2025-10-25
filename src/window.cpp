#include "../include/window.h"
#include <GLFW/glfw3.h>
#include <iostream>

t_window::t_window(const unsigned int width, const unsigned int height,
                   const std::string name) {
  this->p_framebuffer = NULL;
  if (!glfwInit()) {
    std::cout << "glfw init failed" << std::endl;
  }

  // glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

  // msaa here only important for default framebuffer.
  // glfwWindowHint(GLFW_SAMPLES, 4);

  this->p_backend_window =
      glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
  if (!(this->p_backend_window)) {
    std::cout << "glfw window failed" << std::endl;
  }
  glfwMakeContextCurrent(this->p_backend_window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "failed to initialize opengl context" << std::endl;
  }

  glfwSetKeyCallback(this->p_backend_window, key_callback);
  this->running = true;
  std::cout << glGetString(GL_VERSION)
            << ", glsl: " << glGetString(GL_SHADING_LANGUAGE_VERSION)
            << std::endl;
}

t_window::~t_window() {
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

void t_window::update() { glfwSwapBuffers(this->p_backend_window); }

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

void t_window::set_framebuffer(t_framebuffer *p_framebuffer) {
  this->p_framebuffer = p_framebuffer;
  glViewport(0, 0, 512, 512);
}

static void key_callback(GLFWwindow *p_backend_window, int key, int scancode,
                         int action, int mods) {
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(p_backend_window, GLFW_TRUE);
}
