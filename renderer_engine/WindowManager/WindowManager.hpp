/*
** Valentin Woehrel, 2025
** OpenView
** WindowManager
*/

#ifndef WINDOWMANAGER_HPP_
#define WINDOWMANAGER_HPP_

#include <iostream>
#include <GLFW/glfw3.h>

class WindowManager {
    public:
        WindowManager(int width, int height, const char *title);
        ~WindowManager();

        bool shouldClose();
        void render();

    private:
        GLFWwindow *_window;
};

#endif /* !WINDOWMANAGER_HPP_ */