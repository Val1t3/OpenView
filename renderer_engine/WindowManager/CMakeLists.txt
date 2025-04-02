add_library(WindowManager STATIC
    WindowManager.cpp
)

target_include_directories(WindowManager PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(WindowManager PUBLIC
    glad
    glfw
    OpenGL::GL
)
