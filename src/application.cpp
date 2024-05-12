#include "application.h"
namespace TREngine{
    void application::run(){
        //渲染顺序 先渲染UI 在渲染3D物体
        TerrainGen tg = TerrainGen();
        tg.readfile("TRmin.jpg");
        tg.genTrangle();
    tmodel->readdata(tg.data,tg.index);
     GLShader shader = GLShader("TR.vs","TR.fs");
     float deltaTime = 0.0f;	// time between current frame and last frame
     float lastFrame = 0.0f;
     glEnable(GL_DEPTH_TEST);

    while(windows->is_close()){
          float currentFrame = static_cast<float>(glfwGetTime());
          deltaTime = currentFrame - lastFrame;
          lastFrame = currentFrame;
          cam->updata(windows->getWindow(),deltaTime);
          renderBE();
          gui->render();
       
          tmodel->renderDate(&shader ,cam);
          renderAF();
    
        }
    }
    void application::renderBE(){
         glfwPollEvents();
        int display_w, display_h;
        glfwGetFramebufferSize(windows->getWindow(), &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.0f,0.00f,0.00f,0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
       
	
    }
    void application::renderAF(){
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(windows->getWindow());
    }
    application::application(){

         windows = new TRWindows();
         windows->Init();
         windows->createWindow(800,600,"awdaw");
         windows->setThisCurrent();
         windows->gladInit();
         gui = new TRGUI();
         gui->init(windows->getWindow());
         cam = new Camera((glm::vec3(0.0f, 0.0f, 3.0f)));
          gui->cam = cam;
         tmodel = new TerrainModel();

    }

}