#version 330 core

const vec2 res = vec2(480, -360);

layout (location = 0) in vec2 pos;
layout (location = 1) in vec2 uv;

out vec2 vuv;

void main(){
	gl_Position = vec4(pos/res, -0.5, 1);
	vuv = uv;
}