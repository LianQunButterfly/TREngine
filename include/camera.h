#pragma
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "glshader.h"
namespace TREngine{
    class camera{
        public:
        
          
            camera(glm::vec3 campos = glm::vec3(0, 0, 0),
                glm::vec3 camup = glm::vec3(0, 1, 0),
                glm::vec3 camdir = glm::vec3(0, 0, 1),
                float fov = glm::radians(45.0f), float aspect = 4.0f / 3.0f,
                float near = 0.1f, float far = 100.0f);
            ~camera() {};
             void camera::useThisCamera(GLShader& shader ,
                std::string viewMatName="viewMat",
                std::string projMatName="projMat"
             );

        private:
            glm::vec3 campos;
            glm::vec3 camup;
            glm::vec3 camdir;
            glm::mat4  viewMat;
            glm::mat4  projmat;
            
            float fov;
            float aspect;
            float near;
            float far;
            //glm::mat4  viewprojmat;
    };


}