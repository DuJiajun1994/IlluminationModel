//
// Created by M_D_Luffy on 2018/6/16.
//
#include <vector>
#include <string>
#include <cmath>
#include "object.hpp"
#include "light.hpp"
#include "scene.hpp"
#include "camera.hpp"
#include "objects/plane.hpp"
#include "objects/sphere.hpp"
using namespace std;

int main() {
    vector<Object*> objects;
    Object *plane = new Plane({50, 0, 0}, {100, 0, 0}, {0, 0, 0});
    Object *sphere = new Sphere({0, 50, 0}, {0, 100, 0}, {0, 100, 0}, {0, 0, 1}, 1);
    objects.push_back(plane);
    objects.push_back(sphere);
    vector<Light*> lights;
    Light *light = new Light({1, 1, 1}, {0, 0, 10});
    lights.push_back(light);
    Camera camera(1024, 1920, 0.001, 1, M_PI / 6, {6, 0, 3});
    Scene scene(objects, lights, camera);
    string filename = "/home/dujiajun/project/IlluminationModel/image.ppm";
    scene.to_image(filename);
    return 0;
}
