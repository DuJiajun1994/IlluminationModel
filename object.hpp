//
// Created by M_D_Luffy on 2018/6/16.
//

#ifndef ILLUMINATIONMODEL_OBJECT_HPP
#define ILLUMINATIONMODEL_OBJECT_HPP

#include <glm/glm.hpp>
using namespace glm;

class Object {
public:
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    Object(vec3 a, vec3 d, vec3 s): ambient(a), diffuse(d), specular(s) {}
    virtual bool hit(vec3 ray_point, vec3 ray_direction, vec3 &hit_point, vec3 &hit_normal) = 0;
};

#endif //ILLUMINATIONMODEL_OBJECT_HPP
