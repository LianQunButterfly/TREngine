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

		ImGui::ShowDemoWindow(&showdemo);
		ImGui::Render();
   
    }
    void TRGUI::camGUI(){
       static float Pitch =0  ,yaw=-90,zoom=45;
       glm::vec3 capos = cam->getPos();
        ImGui::Begin("This is the information of camera");    
        ImGui::Text("counter = %f", capos.x);
        ImGui::Text("counter = %f", capos.y);
        ImGui::Text("counter = %f", capos.z);
        ImGui::SliderFloat("Pitch", &Pitch, -89.0f, 89.0f); 
        ImGui::SliderFloat("yaw", &yaw, -180, 180); 
        ImGui::SliderFloat("zoom", &zoom, 1.0f, 45.0f);
        cam->setPathSetYaw(Pitch,yaw);
        cam->SetZoom(zoom);
        ImGui::End();
    }
}