//
// Created by dujiajun on 6/14/18.
//

#ifndef ILLUMINATIONMODEL_MATERIAL_HPP
#define ILLUMINATIONMODEL_MATERIAL_HPP

struct Material {
    float ambient;
    float diffuse;
    float specular;
    Material(float a, float d, float s): ambient(a), diffuse(d), specular(s) {}
};

#endif //ILLUMINATIONMODEL_MATERIAL_HPP
