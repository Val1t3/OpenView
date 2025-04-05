cmake_minimum_required(VERSION 3.10)
project(renderer_engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/../vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

add_compile_definitions(GL_SILENCE_DEPRECATION)

add_subdirectory(WindowManager)
add_subdirectory(GraphicPipeline)

add_executable(renderer_engine src/main.cpp)

target_link_libraries(renderer_engine
    PRIVATE
        WindowManager
        GraphicPipeline
)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})