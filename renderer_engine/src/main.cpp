/*
** Valentin Woehrel, 2025
** OpenView
** main
*/

#include <iostream>

#include "WindowManager.hpp"
#include "GraphicPipeline.hpp"

int main(int, char**){
    // ### Graphic section ###
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0, 0.5f, 0.0f
    };

    GraphicPipeline gp;
    gp.test();
    gp.getVertexShader()->test();

    // ### Window section ###
    // WindowManager wm(800, 600, "Renderer Engine");

    // // Renderer loop
    // while(!wm.shouldClose())
    //     wm.render();

    // // Quit programm
    // glfwTerminate();

    std::exit(EXIT_SUCCESS);
}
