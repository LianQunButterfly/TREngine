#pragma once
#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
namespace TREngine
{
    class GLShader
    {
    public:
        GLShader(const std::string vertexPath, const std::string fragmentPath);

        ~GLShader();
        void use();
        unsigned int getShaderID();
        void setMat4(const std::string name, glm::mat4 value) {
            glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
        }
        void setVec3(const std::string name, glm::vec3 value) {
            glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, glm::value_ptr(value));
        }
        //这只uniform变量
        void setFloat(const std::string name, float value) {
            glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
        }
        void setInt(const std::string name, int value) {
            glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
        }
        void setBool(const std::string name, bool value) {
            //设置bool变量
            glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
        }
      
    private:
        unsigned int ID;
        void checkCompileErrors(unsigned int shader, std::string type);//shader编译错误检查
    };
} // namespace TREngine
