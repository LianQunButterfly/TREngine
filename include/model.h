#pragma once
#include "math3d.h"
#include "vector"
#include "glshader.h"
#include "stb_image.h"

struct GLVector{
    float x,y,z;
    float r,g,b;
    float u,v;
    
    GLVector(float x=0,float y=0,float z=0,float r=0,
            float g=0,float b=0,float u=0,float v=0){
        this->x=x;
        this->y=y;
        this->z=z;
        this->r=r;
        this->g=g;
        this->b=b;
        this->u=u;
        this->v=v;
    }
    GLVector(Vector3f point,Vector3f color){
        x= point.x;
        y= point.y;
        z= point.z;
        r= color.x;
        g= color.y;
        b= color.z;
        u= 0;
        v= 0;
    }
    GLVector(Vector3f point ,Vector3f color,Vector3f uv){
        x= point.x;
        y= point.y;
        z= point.z;
        r= color.x;
        g= color.y;
        b= color.z;
        u= uv.x;
        v= uv.y;
    }
};
namespace TREngine{

    class model{
        
    public:
        model();
        model(GLVector* data,int size,int* index,int indexsize);
        ~model();
        void set_data();
        void draw(GLShader &shader);
        void load_texture(const std::string path);
    private:
        std::vector<GLVector> Point ;
        std::vector<int> indextri;
        unsigned int VAO,VBO,EBO;
        unsigned int texture;
    };
}


