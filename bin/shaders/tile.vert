#version 330 core

layout (std140) uniform transform{
	mat4 vp;
};

layout (std140) uniform rotation{
	vec4 angles;
};

uniform sampler1D ramp;

layout(location = 0) in vec3 pos;
layout(location = 1) in vec4 offset;
layout(location = 2) in float scale;
layout(location = 3) in float value;

out vec3 normal;
out vec3 vColor;

void main(){  
	vec4 o;
	o.zx = mat2(angles.xy, -angles.y, angles.x) * offset.zx;
	o.wy = mat2(angles.zw, -angles.w, angles.z) * offset.wy;
	float wScale = 2./ -(o.w - 5);
	gl_Position = vp * vec4(wScale * (.6* scale *pos + o.xyz),1);
	normal = pos;
	float u = (value - .5)* 0.0625;
	vColor = texture(ramp, u).rgb;
}