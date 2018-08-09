#version 330 core

layout (std140) uniform transform{
	mat4 vp;
};


layout(location = 0) in vec3 pos;

out vec3 normal;

void main(){  
	
	gl_Position = vp * vec4(pos,1);
	normal = pos;
}