#include "app.h"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

int main() {
	App *app = new App;
	app->run();
}

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, INT nCmdShow) {
	App *app = new App;
	app->run();
}