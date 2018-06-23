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
#include "objects/cylinder.hpp"
using namespace std;

int main() {
    vector<Object*> objects;
    objects.push_back(new Plane({50, 50, 50}, {100, 100, 100}, {100, 100, 100}, 11));
    objects.push_back(new Sphere({0, 50, 0}, {0, 100, 0}, {0, 100, 0}, {4, 0, 2}, 2));
    objects.push_back(new Cylinder({0, 0, 50}, {0, 0, 100}, {0, 0, 100}, {4, 6, 4}, 2));
    vector<Light*> lights;
    lights.push_back(new Light({0.5, 0.5, 0.5}, {0, 0, 40}));
    lights.push_back(new Light({0.5, 0.5, 0.5}, {10, -10, 4}));
    Camera camera(1024, 1920, 0.001, 1, M_PI / 6, {20, 0, 10});
    Scene scene(objects, lights, camera);
    string filename = "/home/dujiajun/project/IlluminationModel/image.ppm";
    scene.to_image(filename);
    return 0;
}
