/*
** Valentin Woehrel, 2025
** OpenView
** Shader
*/

#include "Shader.hpp"

RendererEngine::Shader::Shader()
    : _id(-1)
{
}

RendererEngine::Shader::Shader(const std::string &vertexPath, const std::string &fragmentPath)
{
    // Read files and convert code to C string
    std::string vertexCodeStr = readFile(vertexPath);
    if (vertexCodeStr.empty()) {
        std::cerr << "[Shader error] Failed to read vertex shader file: " << vertexPath << std::endl;
        return;
    }
    const char *vertexCode = vertexCodeStr.c_str();

    std::string fragmentCodeStr = readFile(fragmentPath);
    if (fragmentCodeStr.empty()) {
        std::cerr << "[Shader error] Failed to read fragment shader file: " << fragmentPath << std::endl;
        return;
    }
    const char *fragmentCode = fragmentCodeStr.c_str();

    // Create and compile shaders
    GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexCode, nullptr);
    glCompileShader(vertex);
    if (checkCompileError(vertex, "VERTEX") == -1) return;

    GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentCode, nullptr);
    glCompileShader(fragment);
    if (checkCompileError(fragment, "FRAGMENT") == -1) return;

    // Create and link program
    _id = glCreateProgram();
    glAttachShader(_id, vertex);
    glAttachShader(_id, fragment);
    glLinkProgram(_id);
    if (checkCompileError(_id, "PROGRAM") == -1) return;

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

RendererEngine::Shader::~Shader()
{
    glDeleteProgram(_id);
}

GLuint RendererEngine::Shader::getId() const
{
    return _id;
}

void RendererEngine::Shader::use() const
{
    glUseProgram(_id);
}

std::string RendererEngine::Shader::readFile(const std::string &path) const
{
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "[Shader error] Failed to open file: " << path << std::endl;
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int RendererEngine::Shader::checkCompileError(GLuint shader, const std::string type) const
{
    GLint success;
    GLchar infoLog[1024];

    if (type == "PROGRAM") {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
            std::cerr << "[Shader error] Linking error in program\n"
                      << infoLog << std::endl;
            return -1;
        }
    } else {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
            std::cerr << "[Shader error] Compilation error in " << type << "\n"
            << infoLog << std::endl;
            return -1;
        }
    }
    return 0;
}
