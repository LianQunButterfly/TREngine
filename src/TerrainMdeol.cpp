#include "TerrainMdeol.h"
namespace TREngine{

    void TerrainGen::readfile(const std::string &path){
        image = cv::imread(path, cv::IMREAD_GRAYSCALE);
        bool a = image.empty();
        if (image.empty()) {
            std::cout << "Could not open or find the image" << std::endl;
        }
      //  cv::imshow("my", image);
        
    }
    void TerrainGen::genTrangle(){
        Point p1;
        data.clear();
        index.clear();
        for (int y = 0; y < image.rows; ++y) {  
            for (int x = 0; x < image.cols; ++x) {
               p1.x = (2.0*x/ float(image.cols) )-1.0;
               p1.z = (2.0*y/ float(image.rows) )-1.0;
               p1.y  = static_cast<float>(image.at<uchar>(y, x))/255;
               putPointXYZ(p1);
                
            }
        }
        for (int y = 1; y < image.rows - 1; y += 2) {
            for (int x = 1; x < image.cols - 1; x += 2) {
                //1
                putindex(x, y, image.cols);
                putindex(x - 1, y - 1, image.cols);
                putindex(x, y - 1, image.cols);
                //2
                putindex(x, y, image.cols);
                putindex(x - 1, y - 1, image.cols);
                putindex(x - 1, y , image.cols);
                //3
                putindex(x, y, image.cols);
                putindex(x + 1, y -1, image.cols);
                putindex(x, y - 1, image.cols);
                //4
                putindex(x, y, image.cols);
                putindex(x + 1, y - 1, image.cols);
                putindex(x +1, y , image.cols);
                //5
                putindex(x, y, image.cols);
                putindex(x -1, y+1, image.cols);
                putindex(x-1, y , image.cols);
                //6
                putindex(x, y, image.cols);
                putindex(x - 1, y + 1, image.cols);
                putindex(x, y + 1, image.cols);
                //7
                putindex(x, y, image.cols);
                putindex(x + 1, y + 1, image.cols);
                putindex(x+1, y , image.cols);
                //8
                putindex(x, y, image.cols);
                putindex(x + 1, y + 1, image.cols);
                putindex(x, y +1, image.cols);;
                
            }
        }
    }
    TerrainModel::TerrainModel(){
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
    }
    void TerrainModel::readdata(std::vector<float> &data,std::vector<unsigned int> &index){
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
        glm::mat4 projection = glm::perspective(glm::radians( cam->getZoom()), (float)600 / (float)400, 0.1f, 100.0f);
        glm::mat4 model = glm::mat4(1.0f);
        shader->setMat4("model",model);
        shader->setMat4("projection",projection);
        shader->setMat4("view",cam->GetViewMatrix());
        shader->setVec3("campos ", cam->getPos());
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, nuTri, GL_UNSIGNED_INT,0);


    }
}