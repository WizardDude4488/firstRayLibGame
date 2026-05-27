cmake_minimum_required(VERSION 3.30)
project(firstRayLibGame)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(raylib_DIR "C:/Users/Sam/.vcpkg-clion/vcpkg/installed/x64-windows-static/share/raylib/")

find_package(raylib REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(firstRayLibGame
        main.cpp)

target_link_libraries(firstRayLibGame PRIVATE raylib glfw3 opengl32 gdi32 winmm)
target_link_options(firstRayLibGame PRIVATE -mconsole)