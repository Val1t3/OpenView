#include "WindowManager.hpp"

WindowManager::WindowManager(int width, int height, const char *title) {
    if (!glfwInit()) {
        std::cerr << "Error to initialize GLFW.\n";
        std::exit(EXIT_FAILURE);
    }
}

WindowManager::~WindowManager() {
    if(!_window) {
        std::cerr << "Error to create a window.\n";
    }
}