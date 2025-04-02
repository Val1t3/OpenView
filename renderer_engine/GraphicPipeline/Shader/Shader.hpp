/*
** Valentin Woehrel, 2025
** OpenView
** Shader
*/

#ifndef SHADER_HPP_
#define SHADER_HPP_

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
    public:
        Shader(const std::string &vertexPath, const std::string &fragmentPath);
        ~Shader();

        GLuint getId() const;

        void use() const;

    private:
        GLuint _id;

        std::string readFile(const std::string &path) const;
        int checkCompileError(GLuint shader, const std::string type) const;
};

#endif /* !SHADER_HPP_ */
