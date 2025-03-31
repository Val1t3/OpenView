#include <iostream>
#include "WindowManager.hpp"

int main(int, char**){
    WindowManager wm(800, 600, "Renderer Engine");

    while(!wm.shouldClose())  // Renderer loop
        wm.render();
    std::exit(EXIT_SUCCESS);
}
