//
// Created by M_D_Luffy on 2018/6/24.
//

#ifndef ILLUMINATIONMODEL_CUBE_HPP
#define ILLUMINATIONMODEL_CUBE_HPP

#include "../object.hpp"
#include <glm/glm.hpp>
using namespace glm;

class Cube: public Object {
private:
    vec3 center;
    float radius;
    bool hit_front(vec3 ray_point, vec3 ray_direction, vec3 &hit_point, vec3 &hit_normal) {
        if(ray_direction.x >= 0) return false;
        float t = (center.x + radius - ray_point.x) / ray_direction.x;
        vec3 tmp_hit_point = ray_point + ray_direction * t;
        if(tmp_hit_point.y > center.y + radius || tmp_hit_point.y < center.y - radius
           || tmp_hit_point.z > center.z + radius || tmp_hit_point.z < center.z - radius) return false;
        hit_point = tmp_hit_point;
        hit_normal = vec3(1, 0, 0);
        return true;
    }
    bool hit_back(vec3 ray_point, vec3 ray_direction, vec3 &hit_point, vec3 &hit_normal) {
        if(ray_direction.x <= 0) return false;
        float t = (center.x - radius - ray_point.x) / ray_direction.x;
        vec3 tmp_hit_point = ray_point + ray_direction * t;
        if(tmp_hit_point.y > center.y + radius || tmp_hit_point.y < center.y - radius
           || tmp_hit_point.z > center.z + radius || tmp_hit_point.z < center.z - radius) return false;
        hit_point = tmp_hit_point;
        hit_normal = vec3(-1, 0, 0);
        return true;
    }
    bool hit_left(vec3 ray_point, vec3 ray_direction, vec3 &hit_point, vec3 &hit_normal) {
        if(ray_direction.y <= 0) return false;
        float t = (center.y - radius - ray_point.y) / ray_direction.y;
        vec3 tmp_hit_point = ray_point + ray_direction * t;
        if(tmp_hit_point.x > center.x + radius || tmp_hit_point.x < center.x - radius
           || tmp_hit_point.z > center.z + radius || tmp_hit_point.z < center.z - radius) return false;
        hit_point = tmp_hit_point;
        hit_normal = vec3(0, -1, 0);
        return true;
    }
    bool hit_right(vec3 ray_point, vec3 ray_direction, vec3 &hit_point, vec3 &hit_normal) {
        if(ray_direction.y >= 0) return false;
        float t = (center.y + radius - ray_point.y) / ray_direction.y;
        vec3 tmp_hit_point = ray_point + ray_direction * t;
        if(tmp_hit_point.x > center.x + radius || tmp_hit_point.x < center.x - radius
           || tmp_hit_point.z > center.z + radius || tmp_hit_point.z < center.z - radius) return false;
        hit_point = tmp_hit_point;
        hit_normal = vec3(0, 1, 0);
        return true;
    }
    bool hit_top(vec3 ray_point, vec3 ray_direction, vec3 &hit_point, vec3 &hit_normal) {
        if(ray_direction.z >= 0) return false;
        float t = (center.z + radius - ray_point.z) / ray_direction.z;
        vec3 tmp_hit_point = ray_point + ray_direction * t;
        if(tmp_hit_point.x > center.x + radius || tmp_hit_point.x < center.x - radius
           || tmp_hit_point.y > center.y + radius || tmp_hit_point.y < center.y - radius) return false;
        hit_point = tmp_hit_point;
        hit_normal = vec3(0, 0, 1);
        return true;
    }
public:
    Cube(vec3 a, vec3 d, vec3 s, vec3 c, float r): center(c), radius(r), Object(a, d, s) {}
    bool hit(vec3 ray_point, vec3 ray_direction, vec3 &hit_point, vec3 &hit_normal) {
        return hit_front(ray_point, ray_direction, hit_point, hit_normal)
               || hit_back(ray_point, ray_direction, hit_point, hit_normal)
               || hit_left(ray_point, ray_direction, hit_point, hit_normal)
               || hit_right(ray_point, ray_direction, hit_point, hit_normal)
               || hit_top(ray_point, ray_direction, hit_point, hit_normal);
    }
};

#endif //ILLUMINATIONMODEL_CUBE_HPP
