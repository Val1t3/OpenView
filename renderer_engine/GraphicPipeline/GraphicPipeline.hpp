/*
** Valentin Woehrel, 2025
** OpenView
** GraphicPipeline
*/

#ifndef GRAPHICPIPELINE_HPP_
#define GRAPHICPIPELINE_HPP_

#include <iostream>

#include "VertexShader/VertexShader.hpp"

class GraphicPipeline {
    public:
        GraphicPipeline();
        ~GraphicPipeline();

        void test();

        VertexShader *getVertexShader();

    private:
        VertexShader _vs;
};

#endif /* !GRAPHICPIPELINE_HPP_ */
