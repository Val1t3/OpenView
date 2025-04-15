/*
** Valentin Woehrel, 2025
** OpenView
** GraphicPipeline
*/

#include "GraphicPipeline.hpp"

// RendererEngine::GraphicPipeline::GraphicPipeline()
// : _shader("assets/shaders/vertex_shader.glsl", "assets/shaders/fragment_shader.glsl")
// {
// }

RendererEngine::GraphicPipeline::GraphicPipeline()
    : _shader("assets/shaders/vertex_shader.glsl", "assets/shaders/fragment_shader.glsl")
{
    std::cout << "GRAPHIC PIPELINE" << std::endl;
    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);

    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0, 0.5f, 0.0f
    };

    glGenBuffers(1, &_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

    _shader.use();
}

RendererEngine::GraphicPipeline::~GraphicPipeline()
{
}

void RendererEngine::GraphicPipeline::render()
{
    // Draw the object
    _shader.use();
    glBindVertexArray(_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}