#include "../include/render_target.h"


t_render_target::t_render_target(const unsigned int width, const unsigned int height, const std::string name) {
    this->width = width;
    this->height = height;
    this->name = name;
}

t_render_target::~t_render_target() {

}

unsigned int t_render_target::get_id() {
    return this->id;
}

std::string t_render_target::get_name() {
    return this->name;
}

unsigned int t_render_target::get_width() {
    return this->width;
}

unsigned int t_render_target::get_height() {
    return this->height;
}

