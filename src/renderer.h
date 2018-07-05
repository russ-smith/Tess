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
	void resetText();
	void draw(double time);
private:
	int bufferText(int x, int y, std::string text, int bufferPos, Font* pFont);
	GLuint sphereVertBuffer, sphereIndexBuffer;
	GLuint guiVertBuffer, guiUVBuffer;
	GLuint cornerInstanceBuffer, edgeInstanceBuffer;
	GLuint tilePosInstanceBuffer, tileScaleInstanceBuffer, tileValueInstanceBuffer;
	GLuint textVertBuffer, textUVBuffer;
	GLuint fadeVertBuffer;
	GLuint quadIndexBuffer;
	GLuint matrixUniformBuffer, angleUniformBuffer;
	GLuint cornerShader, guiShader, edgeShader, tileShader, textShader, fadeShader;
	GLuint cornerVAO, guiVAO, edgeVAO, tileVAO, textVAO, fadeVAO;
	GLuint rampTex, buttonTex;
	int width, height;
	Board* pBoard;
	Font* pSmallFont, * pBigFont;
	std::vector<float> textPos;
	std::vector<float> textUV;
	int textLength;
};
