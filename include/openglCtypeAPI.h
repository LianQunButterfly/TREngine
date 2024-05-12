#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "glshader.h"
#include "camera.h"
#include <iostream>
struct Vertex_Type_Inf{
       float *data;
       unsigned int *Edata ;
       int v_size,E_size;
       int v_size_byte,E_size_byte;
       unsigned int VertexAttri_index;//一共有多少顶点属性 1 2 3;
       unsigned int  VertexAttri_size;
       unsigned int  preVertexAttr_size[8] ;
       void* preVertexAttr_start[8];

 
      
};

struct Vertex_Type{
    unsigned int VAO,VBO,EBO;
    unsigned int EBO_size,VAO_size;
    bool ifEBO;
    Vertex_Type(){
        glGenVertexArrays(1,&VAO);
        glGenBuffers(1,&VBO);
        glGenBuffers(1,&EBO);
    };
    ~Vertex_Type(){
       glDeleteVertexArrays(1, &VAO);
       glDeleteVertexArrays(1, &VBO);
       glDeleteBuffers(1, &EBO);
    };
    void Init_Vertex(Vertex_Type_Inf p);
    void send_date2GPU();
};
