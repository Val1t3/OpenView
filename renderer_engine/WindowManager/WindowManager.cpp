#include "WindowManager.hpp"

WindowManager::WindowManager(int width, int height, const char *title) {
    if (!glfwInit()) {
        std::cerr << "Error to initialize GLFW.\n";
        std::exit(EXIT_FAILURE);
    }

    _window = glfwCreateWindow(width, height, title, NULL, NULL);

    if (!_window) {
        std::cerr << "Error to create window.\n";
        glfwTerminate();
        std::exit(EXIT_FAILURE);
    }
}

WindowManager::~WindowManager() {
    glfwDestroyWindow(_window);
    glfwTerminate();
}

bool WindowManager::shouldClose() {
    return glfwWindowShouldClose(_window);
}

void WindowManager::render() {
    // TODO
}