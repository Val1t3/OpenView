/*
** Valentin Woehrel, 2025
** OpenView
** GraphicPipeline
*/

#include "GraphicPipeline.hpp"

GraphicPipeline::GraphicPipeline()
{
    _vs = VertexShader();
}

GraphicPipeline::~GraphicPipeline()
{
}

void GraphicPipeline::test()
{
    std::cout << "graphic pipeline" << std::endl;
}

VertexShader* GraphicPipeline::getVertexShader()
{
    return &_vs;
}
