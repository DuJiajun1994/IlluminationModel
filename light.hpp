//
// Created by dujiajun on 6/14/18.
//

#ifndef ILLUMINATIONMODEL_LIGHT_HPP
#define ILLUMINATIONMODEL_LIGHT_HPP

#include <glm/glm.hpp>
using namespace glm;

class Light {
private:
    vec3 intensity; // R, G, B
public:
    Light(float r, float g, float b): intensity(r, g, b) {}
};

#endif //ILLUMINATIONMODEL_LIGHT_HPP
