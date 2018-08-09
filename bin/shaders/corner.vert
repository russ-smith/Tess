#version 330 core

layout (std140) uniform transform{
	mat4 vp;
};

layout (std140) uniform rotation{
	vec4 angles;
};

layout(location = 0) in vec3 pos;
layout(location = 1) in vec4 offset;

out vec3 normal;

void main(){  
	vec4 o;
	o.zx = mat2(angles.xy, -angles.y, angles.x) * offset.zx;
	o.wy = mat2(angles.zw, -angles.w, angles.z) * offset.wy;
	float wScale = 2./ -(o.w - 5);
	gl_Position = vp * vec4(wScale * (.18* pos + o.xyz),1);
	normal = pos;
}