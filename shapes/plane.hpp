//
// Created by M_D_Luffy on 2018/6/16.
//

#ifndef ILLUMINATIONMODEL_PLANE_HPP
#define ILLUMINATIONMODEL_PLANE_HPP

#include "../object.hpp"
#include <glm/glm.hpp>
using namespace glm;

class Plane: public Object {
private:
    vec3 point;
    vec3 normal; // direction of normal vector
public:
    Plane(vec3 a, vec3 d, vec3 s, vec3 p, vec3 n): point(p), normal(n), Object(a, d, s) {}
    bool hit(vec3 ray_point, vec3 ray_direction, vec3 &hit_point, vec3 &hit_normal) {

    }
};

#endif //ILLUMINATIONMODEL_PLANE_HPP
