#include "model.h"


namespace TREngine{
    model::model() {
        std::cout << "hello word" << std::endl;
    }
    model::model(GLVector* data,int size,int* index,int indexsize){
        for(auto p = data; p < data + size; p++){
           Point.push_back(*p);
        }
        for(auto p = index; p < index + indexsize; p++){
           indextri.push_back(*p);
        }
    
    }
    void model::set_data(){
        glGenVertexArrays(1,&VAO);
        glGenBuffers(1,&VBO);
        glGenBuffers(1,&EBO);
        glBindVertexArray(VAO);
        //VBO Set

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, Point.size()*sizeof(GLVector),
            &Point[0], GL_STATIC_DRAW);
        //glBufferData(GL_ARRAY_BUFFER, sizeof(Point), Point, GL_STATIC_DRAW);

        //EBO Set
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indextri.size()* sizeof(int),
            &indextri[0], GL_STATIC_DRAW
                    );
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
            glEnableVertexAttribArray(0);
    // color attribute
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
            glEnableVertexAttribArray(1);
    // texture coord attribute
             glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
            glEnableVertexAttribArray(2);
    
       

    }
    void model::draw(GLShader &shader){
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);
        //shader.use();
        
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, indextri.size(), GL_UNSIGNED_INT, 0);
    }
    model::~model(){
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
    }
    void model::load_texture(const std::string path){
        // texture 参数设置
        int width, height, nrChannels;
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        stbi_set_flip_vertically_on_load(true);
        //load Timage
        unsigned char* data = stbi_load(path.c_str(),&width,&height,&nrChannels,0);
        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);

    }
}