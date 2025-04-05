add_library(GraphicPipeline STATIC
    GraphicPipeline.cpp
    Shader/Shader.cpp
)

target_include_directories(GraphicPipeline PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Shader
    ${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/include
)

find_package(glad CONFIG REQUIRED)
target_link_libraries(GraphicPipeline PRIVATE glad::glad)

find_package(OpenGL REQUIRED)
target_link_libraries(GraphicPipeline PRIVATE OpenGL::GL)
