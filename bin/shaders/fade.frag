#version 330 core

uniform float fade;
out vec4 col;

void main(){
	col = vec4(0,0,0,fade);
}