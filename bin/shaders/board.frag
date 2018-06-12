#version 330 core

in vec3 normal;
out vec4 color;

void main(){
	float diff = dot(normal, normalize(vec3 (1,2,2)));
	color = vec4(diff,diff,diff,1);
}