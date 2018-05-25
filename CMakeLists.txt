cmake_minimum_required(VERSION 3.6)
project(learn_opengl)

set(CMAKE_CXX_FLAGS "-lglfw3 -lgdi32 -lopengl32 -lglew32s")

set(SOURCE_FILES gltut1.cpp)
add_executable(gltut1 ${SOURCE_FILES})