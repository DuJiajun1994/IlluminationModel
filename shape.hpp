//
// Created by M_D_Luffy on 2018/6/16.
//

#ifndef ILLUMINATIONMODEL_SHAPE_HPP
#define ILLUMINATIONMODEL_SHAPE_HPP

#include <glm/glm.hpp>
using namespace glm;

class Shape {
public:
    virtual bool hit(vec3 ray_point, vec3 ray_direction, vec3 &hit_point, vec3 &hit_normal) = 0;
};

#endif //ILLUMINATIONMODEL_SHAPE_HPP
