#include "renderer.h"
#include "assetloader.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/quaternion.hpp"
#include "board.h"
#include "geometry.h"
#include "font.h"
#include <iostream>

void Renderer::init() {
	gl3wInit();
	glClearColor(.01f, .01f, .01f, 1);
	glEnable(GL_FRAMEBUFFER_SRGB);
	glEnable(GL_CULL_FACE);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//setup quad indices
	glGenBuffers(1, &quadIndexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, quadIndexBuffer);
	glBufferData(GL_ARRAY_BUFFER, 300 * sizeof(GLubyte), nullptr, GL_STATIC_DRAW);
	GLubyte* mub = reinterpret_cast<GLubyte*>(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
	for (size_t i = 0, j = 0; i < 300; i+=6, j+=4) {
		mub[i] = j;
		mub[i + 1] = mub[i + 5] = j + 1;
		mub[i + 2] = mub[i + 4] = j + 2;
		mub[i + 3] = j + 3;
	}
	glUnmapBuffer(GL_ARRAY_BUFFER);

	//setup corners
	glGenBuffers(1, &sphereVertBuffer);
	glGenBuffers(1, &sphereIndexBuffer);
	glGenBuffers(1, &cornerInstanceBuffer);
	glGenVertexArrays(1, &cornerVAO);
	glBindVertexArray(cornerVAO);
	glBindBuffer(GL_ARRAY_BUFFER, sphereVertBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(geometry::sphereVerts), geometry::sphereVerts, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
	glBindBuffer(GL_ARRAY_BUFFER, cornerInstanceBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(geometry::corners), geometry::corners, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
	glVertexAttribDivisor(1, 1);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sphereIndexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(geometry::sphereTris), geometry::sphereTris, GL_STATIC_DRAW);

	//setup gui
	glGenBuffers(1, &guiVertBuffer);
	glGenVertexArrays(1, &guiVAO);
	glBindVertexArray(guiVAO);
	glBindBuffer(GL_ARRAY_BUFFER, guiVertBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(geometry::buttonVerts), geometry::buttonVerts, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quadIndexBuffer);
	
	//setup edges	
	glGenBuffers(1, &edgeInstanceBuffer);
	glGenVertexArrays(1, &edgeVAO);
	glBindVertexArray(edgeVAO);
	glBindBuffer(GL_ARRAY_BUFFER, edgeInstanceBuffer);
	glBufferData(GL_ARRAY_BUFFER, 256*sizeof(GLfloat), nullptr, GL_STATIC_DRAW);
	GLfloat* mf = reinterpret_cast<GLfloat*>(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 16; j++) {
			for (size_t k = 0; k < 4; k++) {
				mf[64 * i + 4 * j + k] = geometry::corners[4 * geometry::edges[i][j] + k];
			}
		}
	}
	glUnmapBuffer(GL_ARRAY_BUFFER);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), reinterpret_cast<void*>(4 * sizeof(GLfloat)));
	glVertexAttribDivisor(0, 1);
	glVertexAttribDivisor(1, 1);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	//setup tiles
	glGenBuffers(1, &tilePosInstanceBuffer);
	glGenBuffers(1, &tileScaleInstanceBuffer);
	glGenBuffers(1, &tileValueInstanceBuffer);
	glGenVertexArrays(1, &tileVAO);
	glBindVertexArray(tileVAO);
	glBindBuffer(GL_ARRAY_BUFFER, sphereVertBuffer);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
	glBindBuffer(GL_ARRAY_BUFFER, tilePosInstanceBuffer);
	glBufferData(GL_ARRAY_BUFFER, 64 * sizeof(GLfloat), nullptr, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
	glVertexAttribDivisor(1, 1);
	glBindBuffer(GL_ARRAY_BUFFER, tileScaleInstanceBuffer);
	glBufferData(GL_ARRAY_BUFFER, 16 * sizeof(GLfloat), nullptr, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(2, 1, GL_FLOAT, GL_FALSE, sizeof(GLfloat), 0);
	glVertexAttribDivisor(2, 1);
	glBindBuffer(GL_ARRAY_BUFFER, tileValueInstanceBuffer);
	glBufferData(GL_ARRAY_BUFFER, 16 * sizeof(GLfloat), nullptr, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, sizeof(GLfloat), 0);
	glVertexAttribDivisor(3, 1);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sphereIndexBuffer);

	//setup text buffers with space for 50 chars
	glGenBuffers(1, &textVertBuffer);
	glGenBuffers(1, &textUVBuffer);
	glGenVertexArrays(1, &textVAO);
	glBindVertexArray(textVAO);
	glBindBuffer(GL_ARRAY_BUFFER, textVertBuffer);
	glBufferData(GL_ARRAY_BUFFER, 400 * sizeof(GLfloat), nullptr, GL_DYNAMIC_DRAW);	
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);
	glBindBuffer(GL_ARRAY_BUFFER, textUVBuffer);
	glBufferData(GL_ARRAY_BUFFER, 400 * sizeof(GLfloat), nullptr, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, quadIndexBuffer);
	
	//compile shaders
	cornerShader = loadShader("corner.vert", "board.frag");
	guiShader = loadShader("gui.vert", "gui.frag");
	edgeShader = loadShader("edge.vert", "board.frag");
	tileShader = loadShader("tile.vert", "tile.frag");
	textShader = loadShader("text.vert", "text.frag");
	
	//setup view-projection and rotation
	glm::quat rot{ glm::vec3{ 0,0.55,0 } };
	glm::vec3 camPos = rot * glm::vec3{ 0,5,4 };
	glm::mat4 VP = glm::perspective(.9f, 1.f, 1.f, 19.f) * glm::lookAt(camPos, glm::vec3{ 0.f,0.f,0.f }, glm::vec3{ 0.f,1.f,0.f });

	glGenBuffers(1, &matrixUniformBuffer);
	glBindBuffer(GL_UNIFORM_BUFFER, matrixUniformBuffer);
	glBufferData(GL_UNIFORM_BUFFER, 16 * sizeof(GLfloat), &VP[0][0], GL_STATIC_DRAW);
	glBindBufferBase(GL_UNIFORM_BUFFER, 0, matrixUniformBuffer);

	glGenBuffers(1, &angleUniformBuffer);
	glBindBuffer(GL_UNIFORM_BUFFER, angleUniformBuffer);
	glBufferData(GL_UNIFORM_BUFFER, 4 * sizeof(GLfloat), pBoard->angles, GL_DYNAMIC_DRAW);
	glBindBufferBase(GL_UNIFORM_BUFFER, 1, angleUniformBuffer);

	rampTex = loadTexture("ramp");
	pFont = loadFont("cooper32");
	
	bufferText(270, -330, "SCORE:", 0);
	bufferText(270, -250, "BEST TILE:", 6);
}

int Renderer::bufferText(int x, int y, std::string text, int bufferPos) {
	pFont->makeText(x, y, text, textPos, textUV);
	glBindBuffer(GL_ARRAY_BUFFER, textVertBuffer);
	glBufferSubData(GL_ARRAY_BUFFER, 8*sizeof(GLfloat)*bufferPos, sizeof(GLfloat)*textPos.size(), &textPos[0]);
	glBindBuffer(GL_ARRAY_BUFFER, textUVBuffer);
	glBufferSubData(GL_ARRAY_BUFFER, 8*sizeof(GLfloat)*bufferPos, sizeof(GLfloat)*textUV.size(), &textUV[0]);
	return bufferPos + text.length();
}

void Renderer::draw(double time) {
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, height, height);
	glDisable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);

	//update board rotation
	glBufferSubData(GL_UNIFORM_BUFFER, 0, 4 * sizeof(GLfloat), pBoard->angles);

	//draw corner spheres
	glBindVertexArray(cornerVAO);
	glUseProgram(cornerShader);
	glDrawElementsInstanced(GL_TRIANGLES, 240, GL_UNSIGNED_BYTE, 0, 16);
	
	//draw edges
	glBindVertexArray(edgeVAO);
	glUseProgram(edgeShader);
	glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0, 34, 32);

	//draw tiles
	glBindBuffer(GL_ARRAY_BUFFER, tilePosInstanceBuffer);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(pBoard->drawPositions), pBoard->drawPositions);
	glBindBuffer(GL_ARRAY_BUFFER, tileScaleInstanceBuffer);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(pBoard->drawScales), pBoard->drawScales);
	glBindBuffer(GL_ARRAY_BUFFER, tileValueInstanceBuffer);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(pBoard->drawValues), pBoard->drawValues);
	glBindVertexArray(tileVAO);
	glUseProgram(tileShader);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_1D, rampTex);
	glUniform1i(glGetUniformLocation(tileShader, "ramp"), 0);
	glDrawElementsInstanced(GL_TRIANGLES, 240, GL_UNSIGNED_BYTE, 0, pBoard->numActive);

	glEnable(GL_BLEND);
	glDisable(GL_DEPTH_TEST);

	//draw gui
	glViewport(0, 0, width, height);
	glBindVertexArray(guiVAO);
	glUseProgram(guiShader);
	glDrawElements(GL_TRIANGLES, 72, GL_UNSIGNED_BYTE, 0);

	//draw text
	if (pBoard->updateFlags & SCORE_CHANGED) {
		pBoard->updateFlags ^= SCORE_CHANGED;
		int i = bufferText(270, -295, std::to_string(pBoard->score), 16);
		textLength = bufferText(270, -215, std::to_string(1 << pBoard->bestTile), i);
	}
	glBindVertexArray(textVAO);
	glUseProgram(textShader);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, pFont->texID);
	glUniform1i(glGetUniformLocation(textShader, "glyphs"), 1);
	glDrawElements(GL_TRIANGLES, 6 * textLength, GL_UNSIGNED_BYTE, 0);
}



