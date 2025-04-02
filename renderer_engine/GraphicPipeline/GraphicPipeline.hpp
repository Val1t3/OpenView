/*
** Valentin Woehrel, 2025
** OpenView
** GraphicPipeline
*/

#ifndef GRAPHICPIPELINE_HPP_
#define GRAPHICPIPELINE_HPP_

#include <iostream>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include "Shader/Shader.hpp"

class GraphicPipeline {
    public:
        GraphicPipeline();
        ~GraphicPipeline();

        void test();

    private:
        Shader _shader;
};

#endif /* !GRAPHICPIPELINE_HPP_ */
