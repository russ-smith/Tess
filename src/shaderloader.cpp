#include "shaderloader.h"
#include <fstream>

using namespace std;

string readSource(string path) {
	ifstream file(path);
	if (!file.is_open())
		return "";
	string src;
	file.seekg(0, ios::end);
	src.resize(file.tellg());
	file.seekg(0, ios::beg);
	file.read(&src[0], src.size());
	return src;
}

GLuint loadShader(string vert, string frag) {
	string src;
	const char* rawptr;
	GLuint vertSh = glCreateShader(GL_VERTEX_SHADER);
	src = readSource("shaders/" + vert);
	rawptr = src.data();
	glShaderSource(vertSh, 1, &rawptr, nullptr);
	glCompileShader(vertSh);
	GLuint fragSh = glCreateShader(GL_FRAGMENT_SHADER);
	src = readSource("shaders/" + frag);
	rawptr = src.data();
	glShaderSource(fragSh, 1, &rawptr, nullptr);
	glCompileShader(fragSh);
	GLuint prog = glCreateProgram();
	glAttachShader(prog, vertSh);
	glAttachShader(prog, fragSh);
	glLinkProgram(prog);
	glDeleteShader(vertSh);
	glDeleteShader(fragSh);
	return prog;
}
