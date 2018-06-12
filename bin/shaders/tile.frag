#version 330 core

in vec3 normal;
in vec3 vColor;
out vec4 color;

void main(){
	float diff = dot(normal, normalize(vec3 (1,2,2)));
	color = vec4(diff * vColor, 1);
}