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
{
    glGenVertexArrays(1, &_vao);
    glBindVertexArray(_vao);

    GLfloat vertices[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0, 1.0f, 0.0f
    };

    _shader = RendererEngine::Shader("assets/shaders/vertex_shader.glsl", "assets/shaders/fragment_shader.glsl");

    glGenBuffers(1, &_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // // Set the vertex attributes pointers
    // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    // glEnableVertexAttribArray(0);

    // glBindBuffer(GL_ARRAY_BUFFER, 0);
    // glBindVertexArray(0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glUseProgram(_shader.getId());
}

RendererEngine::GraphicPipeline::~GraphicPipeline()
{
}

void RendererEngine::GraphicPipeline::render()
{
    // Draw the object
    glDrawArrays(GL_TRIANGLES, 0, 3);
}