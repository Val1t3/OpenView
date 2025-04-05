/*
** Valentin Woehrel, 2025
** OpenView
** WindowManager
*/

#include "WindowManager.hpp"

WindowManager::WindowManager(int width, int height, const char *title)
{
    // Initialize GLFW
    if (!glfwInit())
    {
        std::cerr << "[WindowManager error] Failed to initialize GLFW\n";
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

    if (!_window) {
        std::cerr << "[WindowManager error] Failed to create a window\n";
        glfwTerminate();
        std::exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(_window);
    glfwSetWindowUserPointer(_window, this);

    // Initialize OpenGL context
    if (gladLoadGL() == 0) {
        std::cerr << "[WindowManager error] Failed to initialize OpenGL context\n";
        exit(EXIT_FAILURE);
    }

    // Define window viewport
    glViewport(0, 0, width, height);

    // TODO: Window iconification

    // Set callback functions
    glfwSetKeyCallback(_window, WindowManager::keyCallback);
    glfwSetFramebufferSizeCallback(_window, WindowManager::framebufferSizeCallback);
}

WindowManager::~WindowManager()
{
    glfwDestroyWindow(_window);
}

GLFWwindow *WindowManager::getWindow()
{
    return _window;
}

bool WindowManager::shouldClose() const
{
    return glfwWindowShouldClose(_window);
}

void WindowManager::render() const
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glfwSwapBuffers(_window);
    glfwPollEvents();
}

void WindowManager::onKey(int key, int scancode, int action, int mods) const
{
    std::cout << "[GLFW] Key " << key << " pressed!" << std::endl;
}

void WindowManager::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    auto *instance = static_cast<WindowManager *>(glfwGetWindowUserPointer(window));

    if (!instance) return;

    instance->onKey(key, scancode, action, mods);
}

void WindowManager::framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}