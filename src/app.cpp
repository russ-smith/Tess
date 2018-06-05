#include "app.h"
#include "renderer.h"
#include "board.h"
#include "gui.h"
#include <GLFW/glfw3.h>

void App::run() {
	//setup OpenGL
	glfwInit();
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	glfwWindowHint(GLFW_SRGB_CAPABLE, GLFW_TRUE);
	width = 960;	//TODO FIX THIS - ADAPT TO SCREEN
	height = 720;
	pWindow = glfwCreateWindow(width, height, "TESS", nullptr, nullptr);
	glfwSetMouseButtonCallback(pWindow, mouseButtonCB);
	glfwMakeContextCurrent(pWindow);
	glfwSwapInterval(1);
	pBoard = new Board(glfwGetTime());
	pGUI = new GUI(width, height, pBoard);
	pRenderer = new Renderer(width, height, pBoard);
	pRenderer->init();
	glfwSetWindowUserPointer(pWindow, pGUI);

	//main game loop
	while (!glfwWindowShouldClose(pWindow)) {
		pBoard->currTime = glfwGetTime();
		if (pBoard->updateFlags)
			pBoard->update();
		pRenderer->draw(glfwGetTime());
		glfwSwapBuffers(pWindow);
		glfwPollEvents();
	}
}

void App::mouseButtonCB(GLFWwindow * window, int button, int action, int mods) {
	if (action == GLFW_PRESS) {
		double x, y;
		glfwGetCursorPos(window, &x, &y);
		static_cast<GUI *>(glfwGetWindowUserPointer(window))->mouseButton(x, y);
	}
}


