//
// Created by M_D_Luffy on 2018/6/16.
//

#ifndef ILLUMINATIONMODEL_PLANE_HPP
#define ILLUMINATIONMODEL_PLANE_HPP

#include "../shape.hpp"
#include <glm/glm.hpp>
using namespace glm;

class Plane: public Shape {
private:
    vec3 point;
    vec3 normal; // direction of normal vector
public:
    Plane(float x1, float y1, float z1, float x2, float y2, float z2): point(x1, y1, z1), normal(x2, y2, z2) {}
    bool hit(vec3 ray_point, vec3 ray_direction, vec3 &hit_point, vec3 &hit_normal) {

    }
};

#endif //ILLUMINATIONMODEL_PLANE_HPP
