#ifndef WINDOW_H
#define WINDOW_H

#include "framebuffer.h"
#include "gl.h"
#include <GLFW/glfw3.h>
#include <string>

class t_window {
public:
  t_window(const unsigned int width, const unsigned int height,
           const std::string name);
  ~t_window();
  void event();
  void update();
  bool running;
  int get_width();
  int get_height();
  void set_framebuffer(t_framebuffer *p_framebuffer);
  GLFWwindow *p_backend_window;

private:
  t_framebuffer *p_framebuffer;
};

static void key_callback(GLFWwindow *p_backend_window, int key, int scancode,
                         int action, int mods);
static void resize(GLFWwindow *p_window, int width, int height);

#endif // WINDOW_H
