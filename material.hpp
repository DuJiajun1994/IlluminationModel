//
// Created by dujiajun on 6/14/18.
//

#ifndef ILLUMINATIONMODEL_MATERIAL_HPP
#define ILLUMINATIONMODEL_MATERIAL_HPP

#include <glm/glm.hpp>
using namespace glm;

class Material {
public:
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    Material(vec3 a, vec3 d, vec3 s): ambient(a), diffuse(d), specular(s) {}
};

#endif //ILLUMINATIONMODEL_MATERIAL_HPP
