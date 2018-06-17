//
// Created by M_D_Luffy on 2018/6/16.
//
#include <vector>
#include <string>
#include "object.hpp"
#include "light.hpp"
#include "scene.hpp"
using namespace std;

int main() {
    vector<Object*> objects;
    vector<Light*> lights;
    Scene scene(objects, lights);
    string filename = "image.ppm";
    int height = 1024, width = 1920;
    scene.to_image(filename, height, width);
    return 0;
}
