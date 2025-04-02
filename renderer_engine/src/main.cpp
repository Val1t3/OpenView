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


    // Renderer loop
    while(!wm.shouldClose())
        wm.render();

    // Quit programm
    glfwTerminate();

    std::exit(EXIT_SUCCESS);
}
