#include "WindowManager.hpp"

WindowManager::WindowManager(int width, int height, const char *title) {
    if (!glfwInit()) {
        std::cerr << "Error to initialize GLFW.\n";
        std::exit(EXIT_FAILURE);
    }

    // Define window hints
#ifdef __APPLE__
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

    // Create window
    _window = glfwCreateWindow(width, height, title, NULL, NULL);
    glViewport(0, 0, width, height);

    // TODO: Window iconification

    if (!_window) {
        std::cerr << "Error to create window.\n";
        glfwTerminate();
        std::exit(EXIT_FAILURE);
    }

    glfwSetWindowUserPointer(_window, this);
    glfwMakeContextCurrent(_window);

    // Set callback functions
    glfwSetKeyCallback(_window, WindowManager::keyCallback);
    glfwSetFramebufferSizeCallback(_window, WindowManager::framebufferSizeCallback);
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

void WindowManager::onKey(int key, int scancode, int action, int mods) {
    std::cout << "[GLFW] Key " << key << " pressed!" << std::endl;
}

void WindowManager::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    auto *instance = static_cast<WindowManager *>(glfwGetWindowUserPointer(window));

    if (!instance) return;

    instance->onKey(key, scancode, action, mods);
}

void WindowManager::framebufferSizeCallback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}