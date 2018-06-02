#pragma once

class Board;

struct Button {
	float left, bottom, right, top;
};

class GUI {
public:
	GUI(int width, int height, Board* pBoard);
	void mouseButton( double x, double y);
private:
	Board * pBoard;
	Button buttons[12];
	int width, height;
};