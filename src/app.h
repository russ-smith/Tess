#pragma once

class GLFWwindow;
class Renderer;
class Board;
class GUI;

class App {
public:
	void run();
	static void mouseButtonCB(GLFWwindow* window, int button, int action, int mods);

private:
	GLFWwindow *pWindow;
	Renderer *pRenderer;
	Board *pBoard;
	GUI *pGUI;
	int width;
	int height;
};