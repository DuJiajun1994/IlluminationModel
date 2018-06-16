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
    Material *material;
public:
    Object(Shape *s, Material *m): shape(s), material(m) {}
};

#endif //ILLUMINATIONMODEL_OBJECT_HPP
