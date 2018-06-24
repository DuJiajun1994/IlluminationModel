cmake_minimum_required(VERSION 3.6)
project(IlluminationModel)
set(CMAKE_CXX_STANDARD 11)
add_executable(main main.cpp light.hpp object.hpp scene.hpp camera.hpp
        objects/cylinder.hpp objects/plane.hpp objects/sphere.hpp objects/cube.hpp)
