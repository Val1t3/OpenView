/*
** Valentin Woehrel, 2025
** OpenView
** main
*/

#include <iostream>

#include "WindowManager.hpp"
#include "GraphicPipeline.hpp"

int main(int, char**) {
    RendererEngine::WindowManager wm(800, 600, "Renderer Engine");
    RendererEngine::GraphicPipeline gp;

    // Renderer loop
    while(!wm.shouldClose()) {
        wm.clear();
        gp.render();
        wm.render();
    }

    // Quit programm
    glfwTerminate();

    std::exit(EXIT_SUCCESS);
}
