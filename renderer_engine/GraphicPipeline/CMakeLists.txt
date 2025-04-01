add_library(GraphicPipeline STATIC
    GraphicPipeline.cpp
    VertexShader/VertexShader.cpp
)

target_include_directories(GraphicPipeline PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(GraphicPipeline
    OpenGL::GL
)