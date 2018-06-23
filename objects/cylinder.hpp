//
// Created by dujiajun on 6/14/18.
//

#ifndef ILLUMINATIONMODEL_CYLINDER_HPP
#define ILLUMINATIONMODEL_CYLINDER_HPP

#include "../object.hpp"
#include <glm/glm.hpp>
using namespace glm;

class Cylinder: public Object {
private:
    vec3 center; // center of the top circle
    float radius;
    bool hit_top(vec3 ray_point, vec3 ray_direction, vec3 &hit_point, vec3 &hit_normal) {
        if(ray_direction.z >= 0) return false;
        float t = (center.z - ray_point.z) / ray_direction.z;
        vec3 tmp_hit_point = ray_point + ray_direction * t;
        if(distance(tmp_hit_point, center) >= radius) return false;
        hit_point = tmp_hit_point;
        hit_normal = {0, 0, 1};
        return true;
    }
    bool hit_side(vec3 ray_point, vec3 ray_direction, vec3 &hit_point, vec3 &hit_normal) {
        float a = 0, b = 0, c = 0;
        for(int i=0;i<2;i++) {
            a += ray_direction[i] * ray_direction[i];
            b += (ray_point[i] - center[i]) * ray_direction[i] * 2;
            c += (ray_point[i] - center[i]) * (ray_point[i] - center[i]);
        }
        c -= radius * radius;
        float delta = b * b - 4 * a * c;
        if(delta < 0) return false;
        float t = (- b - sqrt(delta)) / (2 * a);
        vec3 tmp_hit_point = ray_point + ray_direction * t;
        if(tmp_hit_point.z >= center.z || tmp_hit_point.z <= 0) return false;
        hit_point = tmp_hit_point;
        hit_normal = {hit_point.x - center.x, hit_point.y - center.y, 0};
        hit_normal = normalize(hit_normal);
        return true;
    }
public:
    Cylinder(vec3 a, vec3 d, vec3 s, vec3 c, float r): center(c), radius(r), Object(a, d, s) {}
    bool hit(vec3 ray_point, vec3 ray_direction, vec3 &hit_point, vec3 &hit_normal) {
        return hit_top(ray_point, ray_direction, hit_point, hit_normal)
               || hit_side(ray_point, ray_direction, hit_point, hit_normal);
    }
};

#endif //ILLUMINATIONMODEL_CYLINDER_HPP
