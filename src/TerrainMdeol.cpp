#include "TerrainMdeol.h"
namespace TREngine{

    void TerrainGen::readfile(const std::string &path){
        cv::Mat image2 = cv::imread(path, cv::IMREAD_COLOR);
        bool a = image2.empty();
        if (image2.empty()) {
            std::cout << "Could not open or find the image" << std::endl;
        }
        image = image2;
    }
    void TerrainGen::genTrangle(){
        Point p1;
        for (int y = 0; y < image.rows; ++y) {  
            for (int x = 0; x < image.cols; ++x) {
                // uchar grayValue = image.at<uchar>(y, x);  
                // double z = static_cast<double>(grayValue); 
                // data.emplace_back(x, y, z);  
              //  std::cout << static_cast<float>(image.at<uchar>(y, x)) << " ";
               p1.x = 0.02*x-1;
               p1.y = 0.02*y-1;
               p1.z  = static_cast<float>(image.at<uchar>(y, x))/255;
               putPointXYZ(p1);
                
            }
         //   getchar();
          //  std::cout << std::endl;  
        }
    }
    TerrainModel::TerrainModel(){
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
    }
    void TerrainModel::readdata(std::vector<float> &data,std::vector<int> &index){
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER,VBO );
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

        glBufferData(GL_ARRAY_BUFFER, data.size()*sizeof(float), data.data(), GL_STATIC_DRAW);
        if(!index.empty()){
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, index.size()*sizeof(int), index.data(), GL_STATIC_DRAW);
            nuTri = index.size();
        }
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
    }
    void TerrainModel::renderDate(GLShader *shader,Camera *cam){
        shader->use();
        glm::mat4 projection = glm::perspective(glm::radians( 45.0f), (float)600 / (float)400, 0.1f, 100.0f);
        glm::mat4 model = glm::mat4(1.0f);
        shader->setMat4("model",model);
        shader->setMat4("projection",projection);
        shader->setMat4("view",cam->GetViewMatrix());
        glBindVertexArray(VAO);
        glDrawArrays(GL_POINTS, 0,100*100);


    }
}