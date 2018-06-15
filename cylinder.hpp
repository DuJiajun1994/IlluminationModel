//
// Created by dujiajun on 6/14/18.
//

#ifndef ILLUMINATIONMODEL_CYLINDER_HPP
#define ILLUMINATIONMODEL_CYLINDER_HPP

struct Cylinder{
    float center[3];
    float radius;
    float height;
    Cylinder(float x, float y, float z, float r, float h): center({x, y, z}), radius(r), height(h) {}
};

#endif //ILLUMINATIONMODEL_CYLINDER_HPP
