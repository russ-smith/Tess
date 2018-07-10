#pragma once
#include <GL/gl3w.h>
#include <string>

class Font;

GLuint loadShader(std::string vert, std::string frag);
GLuint loadTexture(std::string name);
Font* loadFont(std::string name);

struct intPair {
	int a, b;
};

intPair loadScores();
void saveScores(int score, int tile);