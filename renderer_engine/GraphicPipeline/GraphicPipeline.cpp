/*
** Valentin Woehrel, 2025
** OpenView
** GraphicPipeline
*/

#include "GraphicPipeline.hpp"

RendererEngine::GraphicPipeline::GraphicPipeline()
: _shader("assets/shaders/vertex_shader.glsl", "assets/shaders/fragment_shader.glsl")
{
}

RendererEngine::GraphicPipeline::~GraphicPipeline()
{
}

void RendererEngine::GraphicPipeline::test()
{
    std::cout << "graphic pipeline" << std::endl;

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0, 0.5f, 0.0f
    };

    // Generate buffers
    unsigned int VBO;
    unsigned int VAO;

    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);


    // Bind buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    // Configure the bound buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // Draw the object
    glUseProgram(_shader.getId());
    glDrawArrays(GL_TRIANGLES, 0, 3);
}