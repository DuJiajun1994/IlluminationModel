//
// Created by M_D_Luffy on 2018/6/16.
//

#ifndef ILLUMINATIONMODEL_POINT_LIGHT_HPP
#define ILLUMINATIONMODEL_POINT_LIGHT_HPP

#include "../light.hpp"
#include <glm/glm.hpp>
using namespace glm;

class PointLight: public Light {
private:
    vec3 position; // x, y, z
public:
    PointLight(float r, float g, float b, float x, float y, float z):
            position(x, y, z), Light(r, g, b) {}
};

#endif //ILLUMINATIONMODEL_POINT_LIGHT_HPP
