#include "TRWindows.h"
#include <iostream>
namespace TREngine
{
    TRWindows::TRWindows()
    {
        
    }
    TRWindows::~TRWindows()
    {
        glfwTerminate();

    }
    void TRWindows::Init(){
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    }
    void TRWindows::createWindow(int width, int height, const char* title){
        m_window = glfwCreateWindow(width, height, title, NULL, NULL);
        if (m_window == NULL)
        {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        }
    }
    void TRWindows::setThisCurrent(){
        glfwMakeContextCurrent(m_window);

    }
    void TRWindows::gladInit(){
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
           
        }    
    }
   
} // namespace TREngine
