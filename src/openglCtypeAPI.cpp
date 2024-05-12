#include "openglCtypeAPI.h"


 void Vertex_Type::Init_Vertex(Vertex_Type_Inf p){
     glBindVertexArray(VAO);
     glBindBuffer(GL_ARRAY_BUFFER,VBO );
     VAO_size = p.v_size;
     EBO_size = p.E_size;
     glBufferData(GL_ARRAY_BUFFER,p.v_size_byte,p.data,GL_STATIC_DRAW);
     ifEBO = false;
     if(p.Edata != nullptr){
        ifEBO = true;
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,p.E_size_byte,p.Edata,GL_STATIC_DRAW);
     }
     for(int i=0;i<p.VertexAttri_index;i++){
        glVertexAttribPointer(i,p.preVertexAttr_size[i], GL_FLOAT, GL_FALSE,
                                p.VertexAttri_size,p.preVertexAttr_start[i]);
        glEnableVertexAttribArray(i);
     }
     glBindVertexArray(0);

 }
 void Vertex_Type::send_date2GPU(){
    glBindVertexArray(VAO);
    if(ifEBO){
        glDrawElements(GL_TRIANGLES, EBO_size, GL_UNSIGNED_INT, 0);
    }
    else {
        glDrawArrays(GL_TRIANGLES, 0, VAO_size);
    }
 }