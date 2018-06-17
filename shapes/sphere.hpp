//
// Created by dujiajun on 6/14/18.
//

#ifndef ILLUMINATIONMODEL_SPHERE_HPP
#define ILLUMINATIONMODEL_SPHERE_HPP

#include "../shape.hpp"
#include <glm/glm.hpp>
using namespace glm;

class Sphere: public Shape {
private:
    vec3 center;
    float radius;
public:
    Sphere(float x, float y, float z, float r): center(x, y, z), radius(r) {}
};

#endif //ILLUMINATIONMODEL_SPHERE_HPP