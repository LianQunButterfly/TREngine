#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "math3d.h"
#include <iostream>
#include <fstream>  

#include "TRWindows.h"
#include "glshader.h"
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    std::string vpath = "vertex.txt";
    std::string fpath = "fragmet.txt";
    TREngine::TRWindows win;
    win.Init();
    win.createWindow(800,600,"Hello Window");
    win.setThisCurrent();
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
     TREngine::GLShader shader(vpath,fpath);
/* 
        添加渲染设置
 */
     Vector3f Vertices[4];
    Vertices[0] = Vector3f(0.0, 0.0, 0.0f);

    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);

   
    while (!glfwWindowShouldClose(win.getWindow()))
    {


        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
       
     
       
        glfwSwapBuffers(win.getWindow());
        glfwPollEvents();
    }


 
    return 0;
}

