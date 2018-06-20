//
// Created by dujiajun on 6/14/18.
//

#ifndef ILLUMINATIONMODEL_SPHERE_HPP
#define ILLUMINATIONMODEL_SPHERE_HPP

#include "../object.hpp"
#include <glm/glm.hpp>
#include <cmath>
using namespace glm;

class Sphere: public Object {
private:
    vec3 center;
    float radius;
public:
    Sphere(vec3 a, vec3 d, vec3 s, vec3 c, float r): center(c), radius(r), Object(a, d, s) {}
    bool hit(vec3 ray_point, vec3 ray_direction, vec3 &hit_point, vec3 &hit_normal) {
        float a = 0, b = 0, c = 0;
        for(int i=0;i<3;i++) {
            a += ray_direction[i] * ray_direction[i];
            b += (ray_point[i] - center[i]) * ray_direction[i] * 2;
            c += (ray_point[i] - center[i]) * (ray_point[i] - center[i]);
        }
        c -= radius * radius;
        float delta = b * b - 4 * a * c;
        if(delta < 0) return false;
        float t = (- b - sqrt(delta)) / (2 * a);
        for(int i=0;i<3;i++) {
            hit_point[i] = ray_point[i] + ray_direction[i] * t;
            hit_normal[i] = hit_point[i] - center[i];
        }
        hit_normal = normalize(hit_normal);
        return true;
    }
};

#endif //ILLUMINATIONMODEL_SPHERE_HPP
