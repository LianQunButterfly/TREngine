#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "glshader.h"
#include "camera.h"
#include <iostream>
#include "openglCtypeAPI.h"
#include "TRWindows.h"
#include "TerrainMdeol.h"
#include "TRGUI.h"
namespace TREngine{

    class application
    {
        
        public:
            application();
            void run();
        private:
            void renderAF();
            void renderBE();
            TRWindows *windows;
            Camera *cam;
            TerrainModel * tmodel;
            TRGUI *gui;
    };

}