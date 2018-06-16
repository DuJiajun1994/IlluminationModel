//
// Created by dujiajun on 6/14/18.
//

#ifndef ILLUMINATIONMODEL_CYLINDER_HPP
#define ILLUMINATIONMODEL_CYLINDER_HPP

#include "../shape.hpp"
#include <glm/glm.hpp>
using namespace glm;

class Cylinder: public Shape {
private:
    vec3 center; // center of the bottom circle
    float radius;
    float height;
public:
    Cylinder(float x, float y, float z, float r, float h): center(x, y, z), radius(r), height(h) {}
};

#endif //ILLUMINATIONMODEL_CYLINDER_HPP
