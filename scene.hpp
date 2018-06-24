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
#include "camera.hpp"
using namespace std;
using namespace glm;

class Scene {
private:
    vector<Object*> objects;
    vector<Light*> lights;
    Camera camera;
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

    vec3 get_intensity(vec3 ray_direction, vec3 hit_point, vec3 hit_normal, vec3 ambient, vec3 diffuse, vec3 specular) {
        vec3 intensity = ambient;
        ray_direction = normalize(- ray_direction);
        hit_normal = normalize(hit_normal);
        for(auto light: lights) {
            vec3 light_direction = normalize(light->position - hit_point);
            bool blocked = is_blocked(light_direction, hit_point);
            float product1 = dot(light_direction, hit_normal);
            if(!blocked && product1 > 0) {
                float light_distance = distance(light->position, hit_point);
                float factor = std::min(1000 / (light_distance * light_distance), float(1.));
                intensity += light->intensity * diffuse * product1 * factor;
                vec3 reflection_vector = hit_normal * (2 * product1) - light_direction;
                float product2 = dot(reflection_vector, ray_direction);
                if(product2 > 0) {
                    intensity += light->intensity * specular * float(pow(product2, 5)) * factor;
                }
            }
        }
        return intensity;
    }

    bool is_blocked(vec3 light_direction, vec3 hit_point) {
        bool blocked = false;
        for(auto object: objects) {
            vec3 tmp_hit_point, tmp_hit_normal;
            bool tmp_hit = object->hit(hit_point, light_direction, tmp_hit_point, tmp_hit_normal);
            if(tmp_hit) {
                float indicate = dot(light_direction, hit_point - tmp_hit_point);
                if(indicate < 0) {
                    blocked = true;
                    break;
                }
            }
        }
        return blocked;
    }

public:
    Scene(vector<Object*> o, vector<Light*> l, Camera c): objects(o), lights(l), camera(c) {}
    void to_image(string filename) {
        int height = camera.height;
        int width = camera.width;
        vector<vector<vector<float>>> image(height, vector<vector<float>>(width, vector<float>(3, 0)));
        vec3 ray_point = camera.origin;
        for(int i=0;i<height;i++) {
            for(int j=0;j<width;j++) {
                vec3 ray_direction = camera.ray_direction(i, j);
                vec3 hit_point, hit_normal;
                vec3 ambient, diffuse, specular;
                bool has_hit = hit(ray_point, ray_direction, hit_point, hit_normal, ambient, diffuse, specular);
                if(has_hit) {
                    vec3 intensity = get_intensity(ray_direction, hit_point, hit_normal, ambient, diffuse, specular);
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
