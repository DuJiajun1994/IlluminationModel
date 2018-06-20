//
// Created by M_D_Luffy on 2018/6/20.
//

#ifndef ILLUMINATIONMODEL_CAMERA_HPP
#define ILLUMINATIONMODEL_CAMERA_HPP

#include <glm/glm.hpp>
#include <cmath>
using namespace glm;

class Camera {
public:
    int height;
    int width;
    float pixel_size;
    float image_distance;
    float angle;
    vec3 origin;
    Camera(int h, int w, float p, float i, float a, vec3 o):
            height(h), width(w), pixel_size(p), image_distance(i), angle(a), origin(o) {}
    vec3 ray_direction(int i, int j) {
        float v_offset = (i - float(height - 1) / 2) * pixel_size;
        float x = - image_distance * cos(angle) + v_offset * sin(angle);
        float y = (j - float(width - 1) / 2) * pixel_size;
        float z = - image_distance * sin(angle) - v_offset * cos(angle);
        return vec3(x, y, z);
    }
};

#endif //ILLUMINATIONMODEL_CAMERA_HPP
