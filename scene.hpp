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

    bool hit(vec3 ray_point, vec3 ray_direction, vec3 &hit_point, vec3 &hit_normal, vec3 &ambient, vec3 &diffuse, vec3 &specular) {
        float dist = numeric_limits<float>::max();
        bool has_hit = false;
        for(auto object: objects) {
            vec3 tmp_hit_point, tmp_hit_normal;
            bool tmp_hit = object->hit(ray_point, ray_direction, tmp_hit_point, tmp_hit_normal);
            has_hit = tmp_hit || has_hit;
            if(tmp_hit) {
                float tmp_distance = distance(ray_point, tmp_hit_point);
                if(tmp_distance < dist) {
                    hit_point = tmp_hit_point;
                    hit_normal = tmp_hit_normal;
                    ambient = object->ambient;
                    diffuse = object->diffuse;
                    specular = object->specular;
                }
            }
        }
        return has_hit;
    }

    vec3 get_intensity(vec3 view_direction, vec3 hit_point, vec3 hit_normal, vec3 &ambient, vec3 &diffuse, vec3 &specular) {
        vec3 intensity(0, 0, 0);
        for(auto light: lights) {
            vec3 light_direction;
            bool is_blocked = is_blocked(light_direction, hit_point);
            if(!is_blocked) {

            }
        }
        return intensity;
    }

    bool is_blocked(vec3 light_direction, vec3 hit_point) {

    }

public:
    Scene(vector<Object*> o, vector<Light*> l): objects(o), lights(l) {}
    void to_image(string filename, int height, int width) {
        vector<vector<vector<float>>> image(height, vector<vector<float>>(width, vector<float>(3, 0)));
        for(int i=0;i<height;i++) {
            for(int j=0;j<width;j++) {
                vec3 ray_point, ray_direction;
                vec3 hit_point, hit_normal;
                vec3 ambient, diffuse, specular;
                bool has_hit = hit(ray_point, ray_direction, hit_point, hit_normal, ambient, diffuse, specular);
                if(has_hit) {
                    vec3 intensity = get_intensity(ray_point, hit_point, hit_normal, ambient, diffuse, specular);
                    image[i][j][0] = intensity.r;
                    image[i][j][1] = intensity.g;
                    image[i][j][2] = intensity.b;
                }
            }
        }
        save_image(filename, image);
    }
};

#endif //ILLUMINATIONMODEL_SCENE_HPP
