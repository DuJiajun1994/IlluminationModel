//
// Created by M_D_Luffy on 2018/6/16.
//

#include <vector>
#include <fstream>
#include "object.hpp"
#include "light.hpp"
#define HEIGHT 1024
#define WIDTH 1920
using namespace std;

float image[HEIGHT][WIDTH][3];

void save_image() {
    ofstream out("image.ppm", ios::out | ios::binary);
    out<<"P6\n";
    out<<WIDTH<<" "<<HEIGHT<<"\n";
    out<<"255\n";
    for(int i=0;i<HEIGHT;i++) {
        for(int j=0;j<WIDTH;j++) {
            for(int k=0;k<3;k++) {
                out<<(unsigned char)(image[i][j][k]);
            }
        }
    }
}

int main() {
    vector<Object> objects;
    vector<Light> lights;
    for(int i=0;i<HEIGHT;i++) {
        for(int j=0;j<WIDTH;j++) {

        }
    }
    save_image();
    return 0;
}
