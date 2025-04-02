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

class GraphicPipeline {
    public:
        GraphicPipeline();
        ~GraphicPipeline();

        void test();

    private:
};

#endif /* !GRAPHICPIPELINE_HPP_ */
