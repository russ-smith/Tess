#version 330 core

in vec3 normal;
in vec3 vColor;
out vec4 color;

void main(){
	float diff = dot(normalize(normal), normalize(vec3 (0,1,0.5)));
	diff = .9*max(diff,0) + .1;
	color = vec4(diff * vColor, 1);
}