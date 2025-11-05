#include "../include/debug.h"
#include "../include/gl.h"
#include <iostream>

void print_glerror() { std::cout << "gl error: " << glGetError() << std::endl; }
