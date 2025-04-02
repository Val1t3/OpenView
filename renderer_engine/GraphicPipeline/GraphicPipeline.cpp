/*
** Valentin Woehrel, 2025
** OpenView
** GraphicPipeline
*/

#include "GraphicPipeline.hpp"

GraphicPipeline::GraphicPipeline()
: _shader("assets/shaders/vertex_shader.glsl", "assets/shaders/fragment_shader.glsl")
{
}

GraphicPipeline::~GraphicPipeline()
{
}

void GraphicPipeline::test()
{
    std::cout << "graphic pipeline" << std::endl;

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0, 0.5f, 0.0f
    };

    // // ### VERTEX INPUT ###
    // // Generate buffers
    // unsigned int VBO;
    // glGenBuffers(1, &VBO);

    // // Bind buffer
    // glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // // Configure the bound buffer
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // // TODO: segfault
}