add_library(WindowManager STATIC
    WindowManager.cpp
)

find_package(glfw3 CONFIG REQUIRED)

target_include_directories(WindowManager PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(WindowManager
    PRIVATE
        glfw
)
