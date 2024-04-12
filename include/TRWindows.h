#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
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
            GLFWwindow* getWindow(){
                return m_window;
            };
        private:
            GLFWwindow* m_window;
    };
} 