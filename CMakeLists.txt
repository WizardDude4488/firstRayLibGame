cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)

add_executable(firstRayLibGame
        main.cpp)

target_link_libraries(firstRayLibGame PRIVATE raylib)
target_link_options(firstRayLibGame PRIVATE -mconsole)