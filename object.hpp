//
// Created by M_D_Luffy on 2018/6/16.
//

#ifndef ILLUMINATIONMODEL_OBJECT_HPP
#define ILLUMINATIONMODEL_OBJECT_HPP

#include "shape.hpp"
#include "material.hpp"

class Object {
private:
    Shape *shape;
public:
    Material *material;
    Object(Shape *s, Material *m): shape(s), material(m) {}
    bool hit(vec3 ray_point, vec3 ray_direction, vec3 &hit_point, vec3 &hit_normal) {
        return shape->hit(ray_point, ray_direction, hit_point, hit_normal);
    }
};

#endif //ILLUMINATIONMODEL_OBJECT_HPP
