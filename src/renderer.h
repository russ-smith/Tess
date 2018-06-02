#pragma once

#include "GL/gl3w.h"

class Board;

class Renderer {
public:
	Renderer(int width, int height, Board *pBoard) : width(width), height(height), pBoard(pBoard) {};
	void init();
	void draw(double time);
private:
	GLuint sphereVertBuffer, sphereIndexBuffer;
	GLuint guiVertBuffer, guiIndexBuffer;
	GLuint cornerInstanceBuffer, edgeInstanceBuffer;
	GLuint edgeUniformBuffer, matrixUniformBuffer, angleUniformBuffer;
	GLuint cornerShader, guiShader, edgeShader;
	GLuint cornerVAO, guiVAO, edgeVAO;
	int width, height;
	Board* pBoard;
};
