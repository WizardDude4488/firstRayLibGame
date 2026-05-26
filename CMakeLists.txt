#Sets a minimum required version for C++
set(CMAKE_CXX_STANDARD_REQUIRED 20)

#set the minimum required version of Cmake for the project
cmake_minimum_required(VERSION 4.2)

#Sets the project name and version number (don't use for version control, using git instead)
project(firstRayLibGame VERSION 1.0.0)

#tell CMake where to find vcpackage libraries
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/C:/Users/Sam/.vcpkg-clion/vcpkg/installed/x64-mingw-dynamic")

#find raylib
find_package(raylib CONFIG REQUIRED)

#tell Cmake to make an executable with this name
add_executable(firstRayLibGame
        main.cpp)

#link raylib
target_link_libraries(firstRayLibGame PRIVATE raylib)