//
// Created by dujiajun on 6/14/18.
//

#ifndef ILLUMINATIONMODEL_LIGHT_HPP
#define ILLUMINATIONMODEL_LIGHT_HPP

#include <glm/glm.hpp>
using namespace glm;

class Light {
public:
    vec3 intensity; // R, G, B
    vec3 position;
    Light(vec3 i, vec3 p): intensity(i), position(p) {}
};

#endif //ILLUMINATIONMODEL_LIGHT_HPP
