#include "camera.h"
/*
            glm::vec3 campos;
            glm::vec3 camup;
            glm::vec3 camdir;
            glm::mat4  viewMat;
            glm::mat4  projmat;

*/
namespace TREngine{

         camera::camera(glm::vec3 campos, 
                  glm::vec3 camup, 
                  glm::vec3 camdi, 
                  float fov, float aspect, 
                  float near, float far){

                     this->campos = campos;
                     this->camup = camup;
                     this->camdir = camdir;
                     this->fov = fov;
                     this->aspect = aspect;
                     this->near = near;
                     this->far = far;
                     this->viewMat = glm::lookAt(campos, campos+camdir, camup);
                     this->projmat = glm::perspective(fov, aspect, near, far);
                  }
    void camera::useThisCamera(GLShader& shader ,
                std::string viewMatName,
                std::string projMatName
    ){
        shader.setMat4("viewMat", viewMat);
        shader.setMat4("projMat", projmat);
    }

}