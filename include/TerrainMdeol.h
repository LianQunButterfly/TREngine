#pragma once
#include <string>
#include <vector>
#include "opencv2/opencv.hpp"
#include "glshader.h"
#include "camera.h"
struct Point{
    float x,y,z;
};
namespace TREngine{
    class TerrainModel{
        public :
            TerrainModel();
            void readdata(std::vector<float> &data, std::vector<unsigned int> &index);
            void renderDate(GLShader *shader, Camera *cam);
        
        private:
            unsigned int VAO,VBO,EBO;
            unsigned int nuTri;
           
    };
    class TerrainGen{
        public:
            TerrainGen() {};
            void readfile(const std::string &path);
            void genTrangle();
            std::vector<float> data;
            std::vector<unsigned int> index;
        private:
            cv::Mat image;
            void putPointXYZ(Point p){
                data.push_back(p.x);
                data.push_back(p.y);
                data.push_back(p.z);
            };
            void putindex(int x, int y, int colow) {
                index.push_back(x + y * colow);
            }
            
    };
}