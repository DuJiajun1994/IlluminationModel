//
// Created by M_D_Luffy on 2018/6/16.
//

#ifndef ILLUMINATIONMODEL_PLANE_HPP
#define ILLUMINATIONMODEL_PLANE_HPP

#include "../object.hpp"
#include <glm/glm.hpp>
using namespace glm;

class Plane: public Object {
public:
    Plane(vec3 a, vec3 d, vec3 s): Object(a, d, s) {}
    bool hit(vec3 ray_point, vec3 ray_direction, vec3 &hit_point, vec3 &hit_normal) {
        if(ray_direction.z >= 0) return false;
        float t = ray_point.z / ray_direction.z;
        float x = ray_point.x - ray_direction.x * t;
        float y = ray_point.y - ray_direction.y * t;
        hit_point = vec3(x, y, 0);
        hit_normal = vec3(0, 0, 1);
        return true;
    }
};

#endif //ILLUMINATIONMODEL_PLANE_HPP
