#version 440 core

in vec3 normal;
out vec4 color;

void main(){
	color = vec4(normalize(abs(normal)),1);
}