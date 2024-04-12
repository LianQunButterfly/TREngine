#pragma once
#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
namespace TREngine
{
    class GLShader
    {
    public:
        GLShader(const std::string vertexPath, const std::string fragmentPath);

        ~GLShader();
        void use();
        unsigned int getShaderID();
    
    private:
        unsigned int ID;
        void checkCompileErrors(unsigned int shader, std::string type);//shader编译错误检查
    };
} // namespace TREngine
