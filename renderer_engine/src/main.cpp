/*
** Valentin Woehrel, 2025
** OpenView
** main
*/

#include <iostream>

#include "WindowManager.hpp"
#include "GraphicPipeline.hpp"

int main(int, char**){
    WindowManager wm(800, 600, "Renderer Engine");
    GraphicPipeline gp;

    // Initialize glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Renderer loop
    while(!wm.shouldClose())
        wm.render();

    // Quit programm
    glfwTerminate();

    std::exit(EXIT_SUCCESS);
}
