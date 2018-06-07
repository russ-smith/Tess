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
	GLuint tilePosInstanceBuffer, tileScaleInstanceBuffer, tileValueInstanceBuffer;
	GLuint matrixUniformBuffer, angleUniformBuffer;
	GLuint cornerShader, guiShader, edgeShader, tileShader;
	GLuint cornerVAO, guiVAO, edgeVAO, tileVAO;
	GLuint rampTex;
	int width, height;
	Board* pBoard;
};
