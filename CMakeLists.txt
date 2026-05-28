cmake_minimum_required(VERSION 3.30)
project(firstRayLibGame)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib CONFIG REQUIRED)

add_executable(firstRayLibGame main.cpp)
target_link_libraries(firstRayLibGame PRIVATE raylib)