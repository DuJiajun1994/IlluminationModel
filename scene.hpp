//
// Created by M_D_Luffy on 2018/6/17.
//

#ifndef ILLUMINATIONMODEL_SCENE_HPP
#define ILLUMINATIONMODEL_SCENE_HPP

#include <vector>
#include <fstream>
#include <string>
#include <limits>
#include <glm/glm.hpp>
#include "material.hpp"
#include "object.hpp"
#include "light.hpp"
using namespace std;
using namespace glm;

class Scene {
private:
    vector<Object*> objects;
    vector<Light*> lights;
    void save_image(string filename, const vector<vector<vector<float>>> &image) {
        int height = image.size(), width = image[0].size();
        ofstream out(filename, ios::out | ios::binary);
        out<<"P6\n";
        out<<width<<" "<<height<<"\n";
        out<<"255\n";
        for(int i=0;i<height;i++) {
            for(int j=0;j<width;j++) {
                for(int k=0;k<3;k++) {
                    out<<(unsigned char)(image[i][j][k]);
                }
            }
        }
    }

    bool hit(vec3 ray_point, vec3 ray_direction, vec3 &hit_point, Material &material) {
        float dist = numeric_limits<float>::max();
        bool has_hit = false;
        for(auto object: objects) {
            vec3 tmp_hit_point;
            bool tmp_hit = object->hit(ray_point, ray_direction, tmp_hit_point);
            has_hit = tmp_hit || has_hit;
            if(tmp_hit) {
                float tmp_distance = distance(ray_point, tmp_hit_point);
                if(tmp_distance < dist) {
                    hit_point = tmp_hit_point;
                    material = *(object->material);
                }
            }
        }
        return has_hit;
    }

    vec3 get_intensity(int x, int y, vec3 &point, Material &material) {

    }
public:
    Scene(vector<Object*> o, vector<Light*> l): objects(o), lights(l) {}
    void to_image(string filename, int height, int width) {
        vector<vector<vector<float>>> image(height, vector<vector<float>>(width, vector<float>(3, 0)));
        for(int i=0;i<height;i++) {
            for(int j=0;j<width;j++) {
                vec3 ray_point, ray_direction;
                vec3 hit_point;
                Material material;
                bool has_hit = hit(ray_point, ray_direction, hit_point, material);
                if(has_hit) {
                    vec3 intensity = get_intensity(i, j, point, material);
                    image[i][j][0] += intensity.r;
                    image[i][j][1] += intensity.g;
                    image[i][j][2] += intensity.b;
                }
            }
        }
        save_image(filename, image);
    }
};

#endif //ILLUMINATIONMODEL_SCENE_HPP
