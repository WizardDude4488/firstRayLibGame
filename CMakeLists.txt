cmake_minimum_required(VERSION 3.30)
project(firstRayLibGame)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(firstRayLibGame main.cpp)
target_include_directories(firstRayLibGame PRIVATE "C:/Users/Sam/raylib/src")
target_link_libraries(firstRayLibGame PRIVATE
        "C:/Users/Sam/raylib/build/raylib/Debug/raylib.lib"
        opengl32 gdi32 winmm)