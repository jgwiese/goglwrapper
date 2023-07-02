#include "../include/debug.h"
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>


void print_glerror() {
    std::cout << "gl error: " << glGetError() << std::endl;
}

