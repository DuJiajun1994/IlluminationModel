//
// Created by dujiajun on 6/14/18.
//

#ifndef ILLUMINATIONMODEL_LIGHT_HPP
#define ILLUMINATIONMODEL_LIGHT_HPP

struct Light {
    float intensity[3]; // R, G, B
    float position[3]; // x, y, z
    Light(float r, float g, float b, float x, float y, float z): intensity({r, g, b}), position({x, y, z}) {}
};

#endif //ILLUMINATIONMODEL_LIGHT_HPP
