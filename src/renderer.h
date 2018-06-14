#pragma once

#include "GL/gl3w.h"
#include <vector>
#include <string>

class Board;
class Font;

class Renderer {
public:
	Renderer(int width, int height, Board *pBoard) : width(width), height(height), pBoard(pBoard) {};
	void init();
	void draw(double time);
private:
	int bufferText(int x, int y, std::string text, int bufferPos);
	GLuint sphereVertBuffer, sphereIndexBuffer;
	GLuint guiVertBuffer;
	GLuint cornerInstanceBuffer, edgeInstanceBuffer;
	GLuint tilePosInstanceBuffer, tileScaleInstanceBuffer, tileValueInstanceBuffer;
	GLuint textVertBuffer, textUVBuffer;
	GLuint quadIndexBuffer;
	GLuint matrixUniformBuffer, angleUniformBuffer;
	GLuint cornerShader, guiShader, edgeShader, tileShader, textShader;
	GLuint cornerVAO, guiVAO, edgeVAO, tileVAO, textVAO;
	GLuint rampTex;
	int width, height;
	Board* pBoard;
	Font* pFont;
	std::vector<float> textPos;
	std::vector<float> textUV;
	int textLength;
};
