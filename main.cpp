//
// Created by M_D_Luffy on 2018/6/16.
//
#include <vector>
#include <string>
#include "object.hpp"
#include "light.hpp"
#include "scene.hpp"
#include "camera.hpp"
using namespace std;

int main() {
    vector<Object*> objects;
    vector<Light*> lights;
    Camera camera(1024, 1920, 0.001, 1, 30, {6, 0, 3});
    Scene scene(objects, lights, camera);
    string filename = "G:\\github_project\\IlluminationModel\\image.ppm";
    scene.to_image(filename);
    return 0;
}
