//
// Created by dujiajun on 6/14/18.
//

#ifndef ILLUMINATIONMODEL_SPHERE_HPP
#define ILLUMINATIONMODEL_SPHERE_HPP

struct Sphere{
    float center[3];
    float radius;
    Sphere(float x, float y, float z, float r): center({x, y, z}), radius(r) {}
};

#endif //ILLUMINATIONMODEL_SPHERE_HPP
