#include "cube.hpp"

int Cube::init_resources(GLuint programID)
{
   static const GLfloat g_vertex_buffer_data[] = {
      -1.0f,-1.0f,-1.0f,
      -1.0f,-1.0f, 1.0f,
      -1.0f, 1.0f, 1.0f,
       1.0f, 1.0f,-1.0f,
      -1.0f,-1.0f,-1.0f,
      -1.0f, 1.0f,-1.0f,
       1.0f,-1.0f, 1.0f,
      -1.0f,-1.0f,-1.0f,
       1.0f,-1.0f,-1.0f,
       1.0f, 1.0f,-1.0f,
       1.0f,-1.0f,-1.0f,
      -1.0f,-1.0f,-1.0f,
      -1.0f,-1.0f,-1.0f,
      -1.0f, 1.0f, 1.0f,
      -1.0f, 1.0f,-1.0f,
       1.0f,-1.0f, 1.0f,
      -1.0f,-1.0f, 1.0f,
      -1.0f,-1.0f,-1.0f,
      -1.0f, 1.0f, 1.0f,
      -1.0f,-1.0f, 1.0f,
       1.0f,-1.0f, 1.0f,
       1.0f, 1.0f, 1.0f,
       1.0f,-1.0f,-1.0f,
       1.0f, 1.0f,-1.0f,
       1.0f,-1.0f,-1.0f,
       1.0f, 1.0f, 1.0f,
       1.0f,-1.0f, 1.0f,
       1.0f, 1.0f, 1.0f,
       1.0f, 1.0f,-1.0f,
      -1.0f, 1.0f,-1.0f,
       1.0f, 1.0f, 1.0f,
      -1.0f, 1.0f,-1.0f,
      -1.0f, 1.0f, 1.0f,
       1.0f, 1.0f, 1.0f,
      -1.0f, 1.0f, 1.0f,
       1.0f,-1.0f, 1.0f
   };

static const GLfloat g_vertex_buffer2_data[] = {
      -4.0f,-1.0f,-1.0f,
      -4.0f,-1.0f, 1.0f,
      -4.0f, 1.0f, 1.0f,

      -2.0f, 1.0f,-1.0f,
      -4.0f,-1.0f,-1.0f,
      -4.0f, 1.0f,-1.0f,
      
      -2.0f,-1.0f, 1.0f,
      -4.0f,-1.0f,-1.0f,
      -2.0f,-1.0f,-1.0f,
      
      -2.0f, 1.0f,-1.0f,
      -2.0f,-1.0f,-1.0f,
      -4.0f,-1.0f,-1.0f,
      
      -4.0f,-1.0f,-1.0f,
      -4.0f, 1.0f, 1.0f,
      -4.0f, 1.0f,-1.0f,
      
      -2.0f,-1.0f, 1.0f,
      -4.0f,-1.0f, 1.0f,
      -4.0f,-1.0f,-1.0f,
      
      -4.0f, 1.0f, 1.0f,
      -4.0f,-1.0f, 1.0f,
      -2.0f,-1.0f, 1.0f,
      
      -2.0f, 1.0f, 1.0f,
      -2.0f,-1.0f,-1.0f,
      -2.0f, 1.0f,-1.0f,
      
      -2.0f,-1.0f,-1.0f,
      -2.0f, 1.0f, 1.0f,
      -2.0f,-1.0f, 1.0f,
      
      -2.0f, 1.0f, 1.0f,
      -2.0f, 1.0f,-1.0f,
      -4.0f, 1.0f,-1.0f,
      
      -2.0f, 1.0f, 1.0f,
      -4.0f, 1.0f,-1.0f,
      -4.0f, 1.0f, 1.0f,
      
      -2.0f, 1.0f, 1.0f,
      -4.0f, 1.0f, 1.0f,
      -2.0f,-1.0f, 1.0f
   };



   // Two UV coordinatesfor each vertex. They were created withe Blender.
   static const GLfloat g_uv_buffer_data[] = {
      0.000059f, 0.000004f,
      0.000103f, 0.336048f,
      0.335973f, 0.335903f,
      1.000023f, 0.000013f,
      0.667979f, 0.335851f,
      0.999958f, 0.336064f,
      0.667979f, 0.335851f,
      0.336024f, 0.671877f,
      0.667969f, 0.671889f,
      1.000023f, 0.000013f,
      0.668104f, 0.000013f,
      0.667979f, 0.335851f,
      0.000059f, 0.000004f,
      0.335973f, 0.335903f,
      0.336098f, 0.000071f,
      0.667979f, 0.335851f,
      0.335973f, 0.335903f,
      0.336024f, 0.671877f,
      1.000004f, 0.671847f,
      0.999958f, 0.336064f,
      0.667979f, 0.335851f,
      0.668104f, 0.000013f,
      0.335973f, 0.335903f,
      0.667979f, 0.335851f,
      0.335973f, 0.335903f,
      0.668104f, 0.000013f,
      0.336098f, 0.000071f,
      0.000103f, 0.336048f,
      0.000004f, 0.671870f,
      0.336024f, 0.671877f,
      0.000103f, 0.336048f,
      0.336024f, 0.671877f,
      0.335973f, 0.335903f,
      0.667969f, 0.671889f,
      1.000004f, 0.671847f,
      0.667979f, 0.335851f
   };

   glGenBuffers(1, &vertexbuffer);
   glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
   glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);


   glGenBuffers(1, &vertexbuffer2);
   glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer2);
   glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer2_data), g_vertex_buffer2_data, GL_STATIC_DRAW);

   glGenBuffers(1, &uvbuffer);
   glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
   glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);

   // Get a handle for our buffers
   vertexPosition_modelspaceID = glGetAttribLocation(programID, "vertexPosition_modelspace");
   if (vertexPosition_modelspaceID == -1)
   {
      std::cout<<"Could not bind attribute vertexPosition_modelspaceID"<<std::endl;
      return 0;
   }

   vertexUVID = glGetAttribLocation(programID, "vertexUV");
   if (vertexUVID == -1)
   {
      std::cout<<"Could not bind attribute vertexUVID"<<std::endl;
      return 0;
   }

   // Load the texture
   Texture = loadDDS("uvtemplate.DDS");

   // Get a handle for our "myTextureSampler" uniform
   TextureID  = glGetUniformLocation(programID, "myTextureSampler");

   return 1;
}

void Cube::draw(GLint matrixId, glm::mat4 mvp){

   glUniformMatrix4fv(matrixId, 1, GL_FALSE, glm::value_ptr(mvp));

   // Bind our texture in Texture Unit 0
   glActiveTexture(GL_TEXTURE0);
   glBindTexture(GL_TEXTURE_2D, Texture);
   // Set our "myTextureSampler" sampler to user Texture Unit 0
   glUniform1i(TextureID, 0);

   // 1rst attribute buffer : vertices
   glEnableVertexAttribArray(vertexPosition_modelspaceID);
   glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
   glVertexAttribPointer(
      vertexPosition_modelspaceID,  // The attribute we want to configure
      3,                            // size
      GL_FLOAT,                     // type
      GL_FALSE,                     // normalized?
      0,                            // stride
      (void*)0                      // array buffer offset
   );

   glEnableVertexAttribArray(vertexUVID);
   glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
   glVertexAttribPointer(
      vertexUVID,                   // The attribute we want to configure
      2,                            // size : U+V => 2
      GL_FLOAT,                     // type
      GL_FALSE,                     // normalized?
      0,                            // stride
      (void*)0                      // array buffer offset
   );

   glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12*3 indices starting at 0 -> 12 triangles

   glEnableVertexAttribArray(vertexPosition_modelspaceID);
   glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer2);
   glVertexAttribPointer(
      vertexPosition_modelspaceID,  // The attribute we want to configure
      3,                            // size
      GL_FLOAT,                     // type
      GL_FALSE,                     // normalized?
      0,                            // stride
      (void*)0                      // array buffer offset
   );


   // 2nd attribute buffer : UVs
   glEnableVertexAttribArray(vertexUVID);
   glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
   glVertexAttribPointer(
      vertexUVID,                   // The attribute we want to configure
      2,                            // size : U+V => 2
      GL_FLOAT,                     // type
      GL_FALSE,                     // normalized?
      0,                            // stride
      (void*)0                      // array buffer offset
   );

   // Draw the triangles !
   glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12*3 indices starting at 0 -> 12 triangles
}

void Cube::disable(){
   glDisableVertexAttribArray(vertexPosition_modelspaceID);
   glDisableVertexAttribArray(vertexUVID);
}

void Cube::deleteBuffers(){
   glDeleteBuffers(1, &vertexbuffer);
   glDeleteBuffers(1, &uvbuffer);
   glDeleteTextures(1, &TextureID);
}