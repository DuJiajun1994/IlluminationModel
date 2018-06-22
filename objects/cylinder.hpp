//
// Created by dujiajun on 6/14/18.
//

#ifndef ILLUMINATIONMODEL_CYLINDER_HPP
#define ILLUMINATIONMODEL_CYLINDER_HPP

#include "../object.hpp"
#include <glm/glm.hpp>
using namespace glm;

class Cylinder: public Object {
private:
    vec3 center; // center of the bottom circle
    float radius;
    float height;
public:
    Cylinder(vec3 a, vec3 d, vec3 s, vec3 c, float r, float h): center(c), radius(r), height(h), Object(a, d, s) {}
    bool hit(vec3 ray_point, vec3 ray_direction, vec3 &hit_point, vec3 &hit_normal) {

    }
};

#endif //ILLUMINATIONMODEL_CYLINDER_HPP
