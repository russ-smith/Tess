#include "gui.h"
#include "geometry.h"
#include "board.h"

GUI::GUI(int width, int height, Board * pBoard) : width(width), height(height), pBoard(pBoard) {
	for (size_t i = 0; i < 12; i++) {
		buttons[i].left = geometry::buttonVerts[8 * i] * .5 + .5;
		buttons[i].bottom = geometry::buttonVerts[8 * i + 1] * .5 + .5;
		buttons[i].right = geometry::buttonVerts[8 * i + 2] * .5 + .5;
		buttons[i].top = geometry::buttonVerts[8 * i + 5] * .5 + .5;
	}
}

void GUI::mouseButton( double x, double y) {
	if (pBoard->updateFlags != 0)
		if (pBoard->updateFlags & GAME_OVER) {
			pBoard->resetBoard();
		}
		else return;
	int whichButton = -1;
	float nx = static_cast<float>(x / width);
	float ny = static_cast<float>(1. - (y / height));
	for (size_t i = 0; i < 12; i++) {
		if (buttons[i].left <= nx && buttons[i].right >= nx && buttons[i].bottom <= ny && buttons[i].top >= ny)
			whichButton = i;
	}
	if (whichButton < 0)
		return;
	else if (whichButton < 8)
		pBoard->beginMoveTiles(whichButton);
	else if (whichButton < 10)
		pBoard->beginRotateXZ(whichButton == 8 ? -1 : 1);
	else
		pBoard->beginRotateYW(whichButton == 10 ? -1 : 1);
	
}
