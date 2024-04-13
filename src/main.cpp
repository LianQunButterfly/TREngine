#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "math3d.h"
#include <iostream>
#include <fstream>  
#include "model.h"
#include "TRWindows.h"
#include "glshader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
GLVector vertices[] = {
    GLVector(-0.5f, -0.5f, -0.5f,0,0,0  ,0.0f, 0.0f),
    GLVector( 0.5f, -0.5f, -0.5f,0,0,0  ,1.0f, 0.0f),
    GLVector( 0.5f,  0.5f, -0.5f,0,0,0  ,1.0f, 1.0f),
    GLVector( 0.5f,  0.5f, -0.5f,0,0,0  ,1.0f, 1.0f),
    GLVector(-0.5f,  0.5f, -0.5f,0,0,0  ,0.0f, 1.0f),
    GLVector(-0.5f, -0.5f, -0.5f,0,0,0  ,0.0f, 0.0f),
    GLVector(-0.5f, -0.5f,  0.5f,0,0,0  ,0.0f, 0.0f),
    GLVector( 0.5f, -0.5f,  0.5f,0,0,0  ,1.0f, 0.0f),
    GLVector( 0.5f,  0.5f,  0.5f,0,0,0  ,1.0f, 1.0f),
    GLVector( 0.5f,  0.5f,  0.5f,0,0,0  ,1.0f, 1.0f),
    GLVector(-0.5f,  0.5f,  0.5f,0,0,0  ,0.0f, 1.0f),
    GLVector(-0.5f, -0.5f,  0.5f,0,0,0  ,0.0f, 0.0f),
    GLVector(-0.5f,  0.5f,  0.5f,0,0,0  ,1.0f, 0.0f),
    GLVector(-0.5f,  0.5f, -0.5f,0,0,0  ,1.0f, 1.0f),
    GLVector(-0.5f, -0.5f, -0.5f,0,0,0  ,0.0f, 1.0f),
    GLVector(-0.5f, -0.5f, -0.5f,0,0,0  ,0.0f, 1.0f),
    GLVector(-0.5f, -0.5f,  0.5f,0,0,0  ,0.0f, 0.0f),
    GLVector(-0.5f,  0.5f,  0.5f,0,0,0  ,1.0f, 0.0f),
    GLVector( 0.5f,  0.5f,  0.5f,0,0,0  ,1.0f, 0.0f),
    GLVector( 0.5f,  0.5f, -0.5f,0,0,0  ,1.0f, 1.0f),
    GLVector( 0.5f, -0.5f, -0.5f,0,0,0  ,0.0f, 1.0f),
    GLVector( 0.5f, -0.5f, -0.5f,0,0,0  ,0.0f, 1.0f),
    GLVector( 0.5f, -0.5f,  0.5f,0,0,0  ,0.0f, 0.0f),
    GLVector( 0.5f,  0.5f,  0.5f,0,0,0  ,1.0f, 0.0f),
    GLVector(-0.5f, -0.5f, -0.5f,0,0,0  ,0.0f, 1.0f),
    GLVector( 0.5f, -0.5f, -0.5f,0,0,0  ,1.0f, 1.0f),
    GLVector( 0.5f, -0.5f,  0.5f,0,0,0  ,1.0f, 0.0f),
    GLVector( 0.5f, -0.5f,  0.5f,0,0,0  ,1.0f, 0.0f),
    GLVector(-0.5f, -0.5f,  0.5f,0,0,0  ,0.0f, 0.0f),
    GLVector(-0.5f, -0.5f, -0.5f,0,0,0  ,0.0f, 1.0f),
    GLVector(-0.5f,  0.5f, -0.5f,0,0,0  ,0.0f, 1.0f),
    GLVector( 0.5f,  0.5f, -0.5f,0,0,0  ,1.0f, 1.0f),
    GLVector( 0.5f,  0.5f,  0.5f,0,0,0  ,1.0f, 0.0f),
    GLVector( 0.5f,  0.5f,  0.5f,0,0,0  ,1.0f, 0.0f),
    GLVector(-0.5f,  0.5f,  0.5f,0,0,0  ,0.0f, 0.0f),
    GLVector(-0.5f,  0.5f, -0.5f,0,0,0  ,0.0f, 1.0f)
};
// world space positions of our cubes
glm::vec3 cubePositions[] = {
    glm::vec3(0.0f,  0.0f,  0.0f),
    glm::vec3(2.0f,  5.0f, -15.0f),
    glm::vec3(-1.5f, -2.2f, -2.5f),
    glm::vec3(-3.8f, -2.0f, -12.3f),
    glm::vec3(2.4f, -0.4f, -3.5f),
    glm::vec3(-1.7f,  3.0f, -7.5f),
    glm::vec3(1.3f, -2.0f, -2.5f),
    glm::vec3(1.5f,  2.0f, -2.5f),
    glm::vec3(1.5f,  0.2f, -1.5f),
    glm::vec3(-1.3f,  1.0f, -1.5f)
};

int indices[36]; 


int main()
{
    // glfw: initialize and configure
    // ------------------------------
    for (int i = 0; i < 36; i++) { indices[i] = i; }

    TREngine::model mymodel = TREngine::model(vertices,sizeof(vertices)/sizeof(GLVector),
    indices,sizeof(indices)/sizeof(int));

    std::string vpath = "vertex.glsl";
    std::string fpath = "fragmet.glsl";
    TREngine::TRWindows win;
    win.Init();
    win.createWindow(800,600,"Hello Window");
    win.setThisCurrent();
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glEnable(GL_DEPTH_TEST);

     TREngine::GLShader shader =TREngine::GLShader(vpath,fpath);
/* 
        添加渲染设置
 */
    
     shader.use();
     
     




     mymodel.load_texture("awesomeface.png");
     mymodel.set_data();
     
    while (!glfwWindowShouldClose(win.getWindow()))
    {

        shader.use();
       glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
       glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
       glm::mat4 view = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
       glm::mat4 projection = glm::mat4(1.0f);
       projection = glm::perspective(glm::radians(45.0f), (float)800 / (float)600, 0.1f, 100.0f);
       view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
       // pass transformation matrices to the shader
       shader.setMat4("projection", projection); // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
       shader.setMat4("view", view);
               for (unsigned int i = 0; i < 10; i++)
        {
            // calculate the model matrix for each object and pass it to shader before drawing
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);
            float angle = 20.0f * i;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            shader.setMat4("model", model);

            mymodel.draw(shader);
        }
        glfwSwapBuffers(win.getWindow());
        glfwPollEvents();
    }


 
    return 0;
}

