//
// Created by dujiajun on 6/14/18.
//

#ifndef ILLUMINATIONMODEL_MATERIAL_HPP
#define ILLUMINATIONMODEL_MATERIAL_HPP

#include<vector>
using namespace std;

struct Material {
    float ambient[3];
    float diffuse[3];
    float specular[3];
    Material(vector<float> a, vector<float> d, vector<float> s) {
        for(int i=0;i<3;i++) {
            ambient[i] = a[i];
            diffuse[i] = d[i];
            specular[i] = s[i];
        }
    }
};

#endif //ILLUMINATIONMODEL_MATERIAL_HPP
