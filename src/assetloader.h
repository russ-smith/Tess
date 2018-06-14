#pragma once
#include <GL/gl3w.h>
#include <string>

class Font;

GLuint loadShader(std::string vert, std::string frag);
GLuint loadTexture(std::string name);
Font* loadFont(std::string name);