/*
** Valentin Woehrel, 2025
** OpenView
** WindowManager
*/

#ifndef WINDOWMANAGER_HPP_
#define WINDOWMANAGER_HPP_

#include <iostream>

#include <GLFW/glfw3.h>
#include <glad/glad.h>

class WindowManager {
    public:
        WindowManager(int width, int height, const char *title);
        ~WindowManager();

        GLFWwindow *getWindow();

        bool shouldClose() const;
        void render() const;
        void onKey(int key, int scancode, int action, int mods) const;

        static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
        static void framebufferSizeCallback(GLFWwindow *window, int width, int height);

    private:
        GLFWwindow *_window;
};

#endif /* !WINDOWMANAGER_HPP_ */