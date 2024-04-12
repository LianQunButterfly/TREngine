#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "math3d.h"
#include <iostream>
#include <fstream>  
#include "model.h"
#include "TRWindows.h"
#include "glshader.h"
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
GLVector vertices[] = {
//     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
    GLVector(0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f),   // 右上
    GLVector( 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f),   // 右下
    GLVector(-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f),   // 左下
    GLVector(-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f)    // 左上
};
int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
};
TREngine::model mymodel = TREngine::model(vertices,4,indices,6);


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
    
     TREngine::GLShader shader =TREngine::GLShader(vpath,fpath);
/* 
        添加渲染设置
 */





     mymodel.load_texture("container.jpg");
     mymodel.set_data();
     
    while (!glfwWindowShouldClose(win.getWindow()))
    {


        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        mymodel.draw(shader);
        glfwSwapBuffers(win.getWindow());
        glfwPollEvents();
    }


 
    return 0;
}

