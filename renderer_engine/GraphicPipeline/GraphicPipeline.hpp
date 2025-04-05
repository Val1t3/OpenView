/*
** Valentin Woehrel, 2025
** OpenView
** GraphicPipeline
*/

#ifndef GRAPHICPIPELINE_HPP_
#define GRAPHICPIPELINE_HPP_

#include <iostream>

#include "Shader/Shader.hpp"

#include <glad/glad.h>
// #include <OpenGL/gl.h>

class GraphicPipeline {
    public:
        GraphicPipeline();
        ~GraphicPipeline();

        void test();

    private:
        Shader _shader;
};

#endif /* !GRAPHICPIPELINE_HPP_ */
