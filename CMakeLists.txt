cmake_minimum_required(VERSION 3.21)
project(raytracing_with_cmake)

set(CMAKE_CXX_STANDARD 17)
include_directories(src)
add_executable(
        raytracing_with_cmake
        src/App.cpp
        src/App.H
        src/GameObject.cpp
        src/GameObject.h
        src/general.h
        src/Pixel.cpp
        src/Pixel.h
        src/Plane.cpp
        src/Plane.h
        src/Ray.cpp
        src/Ray.h
        src/raytracing.cpp
        src/Scene.cpp
        src/Scene.h
        src/Screen.cpp
        src/Screen.h
        src/Sphere.cpp
        src/Sphere.h
        src/Torus.cpp
        src/Torus.h
        src/vec.h
)
