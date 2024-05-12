#pragma once
#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"
#include "camera.h"
namespace  TREngine
{
    class TRGUI{
        public :
            void init(GLFWwindow * window);
            void render();
            void camGUI();
            Camera *cam;
        private:
        
          float m_Time = 0.0f;

    };

}// TREngine
