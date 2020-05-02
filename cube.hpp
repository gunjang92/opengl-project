#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include <GL/glut.h>
#include "texture.hpp"
using namespace std;

class Cube{

   private:

      GLuint vertexbuffer, vertexbuffer2, uvbuffer, Texture, TextureID;
      GLint vertexPosition_modelspaceID, vertexUVID;

   public:
   	Cube()
   	{

   	}
      int init_resources(GLuint shaderProgram);
      void draw(GLint uniform_mvp, glm::mat4 mvp);
      void disable();
      void deleteBuffers();
};

#endif