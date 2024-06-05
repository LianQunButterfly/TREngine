#include "TRGUI.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
namespace TREngine{
    void TRGUI::init(GLFWwindow * window){
       
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);

    ImGui_ImplOpenGL3_Init("#version 330");
    }
    void TRGUI::render(){
		ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
		bool showdemo  = true;
		camGUI();
        shaderseting();
        
        /*
              this is other GUI       
        */

        ImGui::Begin("This is load hight_Map");

        static char buf1[32] = ""; ImGui::InputText("please input path of hight map", buf1, 32);
        if (ImGui::Button("Button")) {
            tg->readfile(buf1);
            tg->genTrangle();
            tmodel->readdata(tg->data, tg->index);
        }
       
        ImGui::End();

		//ImGui::ShowDemoWindow(&showdemo);
		ImGui::Render();
   
    }
    void TRGUI::camGUI(){
        static float Pitch =0  ,yaw=-90,zoom=45;
        static float lastX = 0  ,lastY = 0;
        static bool camorGUI = false;
        ImGuiIO& io = ImGui::GetIO();
        glm::vec3 capos = cam->getPos();
        ImGui::Begin("This is the information of camera");    
        ImGui::Text("x = %f", capos.x);
        ImGui::Text("y = %f", capos.y);
        ImGui::Text("z = %f", capos.z);
   
        if(ImGui::IsKeyPressed(ImGuiKey_C)){
            camorGUI = !camorGUI;
            if (camorGUI == true){
                lastX=io.MousePos.x;
                lastY=io.MousePos.y;
                
            }
        }
        if(camorGUI){
            float xpos = static_cast<float>(io.MousePos.x);
            float ypos = static_cast<float>(io.MousePos.y);
            float xoffset = xpos - lastX;
            float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
            lastX = xpos;
            lastY = ypos;
            cam->ProcessMouseMovement(xoffset,yoffset,true);
            cam->ProcessMouseScroll(io.MouseWheel);

            if(ImGui::IsKeyDown(ImGuiKey_W)){
                cam->updatabyGUI("FORWARD",io.DeltaTime);
            }
             if(ImGui::IsKeyDown(ImGuiKey_S)){
                cam->updatabyGUI("BACKWARD",io.DeltaTime);
            }
             if(ImGui::IsKeyDown(ImGuiKey_A)){
                cam->updatabyGUI("LEFT",io.DeltaTime);
            }
             if(ImGui::IsKeyDown(ImGuiKey_D)){
                cam->updatabyGUI("RIGHT",io.DeltaTime);
            }
               if(ImGui::IsKeyDown(ImGuiKey_Q)){
                cam->updatabyGUI("UP",io.DeltaTime);
            }
               if(ImGui::IsKeyDown(ImGuiKey_E)){
                cam->updatabyGUI("DOWN",io.DeltaTime);
            }
        }
        ImGui::End();
    }
    void TRGUI::shaderseting(){
         ImGui::Begin("This is the shaderseting"); 
        static float light[3] = {1.0f, 0.5f, 0.31f};
        static float object[3] = { 1.0f, 1.0f, 1.0f};
        ImGui::ColorEdit3("light color", (float*)&light);
        ImGui::ColorEdit3("object color",(float*)&object);
        /*
        lightingShader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
        lightingShader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);
        lightingShader.setVec3("lightPos", lightPos);
        lightingShader.setVec3("viewPos", camera.Position);
        */
        shader->setVec3("objectColor",glm::vec3(light[0],light[1],light[2]));
        shader->setVec3("lightColor",glm::vec3(object[0],object[1],object[2]));
        shader->setVec3("lightPos",cam->getPos());
        shader->setVec3("viewPos",cam->getPos());
         ImGui::End();
    }
}
/*
        if (cmd == "FORWARD")
            Position += Front * velocity;
        if (cmd == "BACKWARD")
            Position -= Front * velocity;
        if (cmd == "LEFT")
            Position -= Right * velocity;
        if (cmd == "RIGHT")
            Position += Right * velocity;

*/