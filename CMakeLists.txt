cmake_minimum_required(VERSION 3.30)
project(firstRayLibGame)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(raylib_DIR "C:/Users/Sam/raylib-master")
set(VCPKG_TARGET_TRIPLET "x64-windows-static")

find_package(raylib REQUIRED)

add_executable(firstRayLibGame
        main.cpp)

target_link_libraries(firstRayLibGame PRIVATE raylib opengl32 gdi32 winmm)
target_link_options(firstRayLibGame PRIVATE -mconsole)

add_custom_command(TARGET firstRayLibGame POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "C:/Users/Sam/.vcpkg-clion/vcpkg/installed/x64-mingw-dynamic/bin/libraylib.dll"
        $<TARGET_FILE_DIR:firstRayLibGame>
)