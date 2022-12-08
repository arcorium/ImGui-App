# CMakeList.txt : CMake project for ImGui App, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("ImGui App" LANGUAGES CXX C)

# Add source to this project's executable.

set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(thirdparty/glfw)
add_subdirectory(thirdparty/imgui)
add_subdirectory(thirdparty/freetype)
add_subdirectory(thirdparty/glad)

add_subdirectory(src/app)

# TODO: Add tests and install targets if needed.
