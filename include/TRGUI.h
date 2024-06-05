#pragma once
#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"
#include "camera.h"
#include "TerrainMdeol.h"
#include "glshader.h"

namespace  TREngine
{
    class TRGUI{
        public :
            void init(GLFWwindow * window);
            void render();
            void camGUI();
            void shaderseting();
            Camera *cam;
            TerrainGen *tg;
            TerrainModel* tmodel;
            GLShader *shader;
    private:
        
          float m_Time = 0.0f;

    };

}// TREngine
