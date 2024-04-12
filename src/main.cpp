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
    Vertices[0] = Vector3f(0.5f,  0.5f, 0.0f);
    Vertices[1] = Vector3f( 0.5f, -0.5f, 0.0f);
    Vertices[2] = Vector3f(-0.5f, -0.5f, 0.0f);
    Vertices[3] = Vector3f(-0.5f,  0.5f, 0.0f);


     unsigned int indices[] = {  // note that we start from 0!
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER,4* sizeof(Vertices), Vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6*sizeof(unsigned int), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
   
    while (!glfwWindowShouldClose(win.getWindow()))
    {


        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        shader.use();
        glBindVertexArray(VAO);
        glDrawElements(GL_POINTS, 6, GL_UNSIGNED_INT, 0);
     
       
        glfwSwapBuffers(win.getWindow());
        glfwPollEvents();
    }


 
    return 0;
}

