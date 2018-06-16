//
// Created by M_D_Luffy on 2018/6/16.
//

#ifndef ILLUMINATIONMODEL_PARALLEL_LIGHT_HPP
#define ILLUMINATIONMODEL_PARALLEL_LIGHT_HPP

#include "../light.hpp"
#include <glm/glm.hpp>
using namespace glm;

class ParallelLight: public Light {
    vec3 direction;
    ParallelLight(float r, float g, float b, float x, float y, float z):
            direction(x, y, z), Light(r, g, b) {}
};

#endif //ILLUMINATIONMODEL_PARALLEL_LIGHT_HPP
