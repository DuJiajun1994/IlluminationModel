//
// Created by dujiajun on 6/14/18.
//

#ifndef ILLUMINATIONMODEL_LIGHT_HPP
#define ILLUMINATIONMODEL_LIGHT_HPP

#include<vector>
using namespace std;

struct Light {
    float intensity[3]; // R, G, B
    Light(vector<float> color) {
        for(int i=0;i<3;i++) {
            intensity[i] = color[i];
        }
    }
};

struct PointLight: Light {
    float position[3]; // x, y, z
    PointLight(vector<float> color, vector<float> pos): Light(color) {
        for(int i=0;i<3;i++) {
            position[i] = pos[i];
        }
    }
};

struct ParallelLight: Light {
    float direction[3];
    ParallelLight(vector<float> color, vector<float> dir): Light(color) {
        for(int i=0;i<3;i++) {
            direction[i] = dir[i];
        }
    }
};

#endif //ILLUMINATIONMODEL_LIGHT_HPP
