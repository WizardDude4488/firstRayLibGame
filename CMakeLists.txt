#Sets a minimum required version for C++
set(CMAKE_CXX_STANDARD_REQUIRED 20)

#set the minimum required version of Cmake for the project
cmake_minimum_required(VERSION 4.2)

#Sets the project name and version number (don't use for version control, using git instead)
project(firstRayLibGame VERSION 1.0.0)

#link raylib
target_include_directories(firstRayLibGame PRIVATE C:/Users/Sam/.vcpkg-clion/vcpkg/packages/raylib_x64-mingw-dynamic)

#link raylib package to project
find_package(raylib CONFIG REQUIRED)

#tell Cmake to make an executable with this name
add_executable(firstRayLibGame
        main.cpp)

