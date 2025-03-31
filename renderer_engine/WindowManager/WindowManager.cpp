#include "WindowManager.hpp"

WindowManager::WindowManager(int width, int height, const char *title) {
    if (!glfwInit()) {
        std::cerr << "Error to initialize GLFW.\n";
        std::exit(EXIT_FAILURE);
    }


#ifdef __APPLE__  // Add window contexts for OS X
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

    _window = glfwCreateWindow(width, height, title, NULL, NULL);  // Create a window with given parameters

    if (!_window) {
        std::cerr << "Error to create window.\n";
        glfwTerminate();
        std::exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(_window);  // Make the window's context current
}

WindowManager::~WindowManager() {
    glfwDestroyWindow(_window);
    glfwTerminate();
}

bool WindowManager::shouldClose() {
    return glfwWindowShouldClose(_window);
}

void WindowManager::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear the buffers
    glfwSwapBuffers(_window);
    glfwPollEvents();
}