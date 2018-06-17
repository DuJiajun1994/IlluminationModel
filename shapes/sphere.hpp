//
// Created by dujiajun on 6/14/18.
//

#ifndef ILLUMINATIONMODEL_SPHERE_HPP
#define ILLUMINATIONMODEL_SPHERE_HPP

#include "../object.hpp"
#include <glm/glm.hpp>
using namespace glm;

class Sphere: public Object {
private:
    vec3 center;
    float radius;
public:
    Sphere(vec3 a, vec3 d, vec3 s, vec3 c, float r): center(c), radius(r), Object(a, d, s) {}
    bool hit(vec3 ray_point, vec3 ray_direction, vec3 &hit_point, vec3 &hit_normal) {

    }
};

#endif //ILLUMINATIONMODEL_SPHERE_HPP
