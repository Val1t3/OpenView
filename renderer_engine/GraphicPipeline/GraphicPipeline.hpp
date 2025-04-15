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

namespace RendererEngine {
    class GraphicPipeline {
        public:
            GraphicPipeline();
            ~GraphicPipeline();

            void render();

        private:
            RendererEngine::Shader _shader;
            GLuint _vao;
            GLuint _vbo;
    }; // GraphicPipeline
};  // RendererEngine

#endif /* !GRAPHICPIPELINE_HPP_ */
