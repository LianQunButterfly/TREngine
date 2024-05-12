#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
/*
TRWindows 类
负责窗口(上下文)的管理 
包括窗口的创建销毁和设置当前窗口

*/
namespace TREngine{
    class TRWindows
    {
        public:
            TRWindows();
            ~TRWindows();
            // 创建窗口
            void Init();
            void createWindow(int width, int height, const char* title);
            void setThisCurrent();
            void gladInit();
            bool is_close(){
             return !glfwWindowShouldClose(m_window) ;
            };
            GLFWwindow* getWindow(){
                return m_window;
            };
        private:
            GLFWwindow* m_window;
    };
} 