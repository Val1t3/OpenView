cmake_minimum_required(VERSION 3.10.0)

project(engine VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include Packages
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(renderer_engine src/main.cpp)

target_link_libraries(renderer_engine PRIVATE glfw)
target_link_libraries(renderer_engine PRIVATE OpenGL::GL)