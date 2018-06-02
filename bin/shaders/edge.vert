#version 440 core

layout (binding = 0, std140) uniform transform{
	mat4 vp;
};

layout (binding = 1, std140) uniform rotation{
	vec4 angles;
};

//layout (binding = 2, std140) uniform verts {
//	vec4 points[64];
//};

layout (location = 0) in vec4 a;
layout (location = 1) in vec4 b;

out vec3 normal;

const float PI = 3.1415926;

//procedurally draws a cylinder between two 4D points
void main(){
	float angle = float(gl_VertexID >> 1) * PI / 8;
	int end = gl_VertexID & 1;
	vec4 A, B;
	A.zx = mat2(angles.xy, -angles.y, angles.x) * a.zx;
	A.wy = mat2(angles.zw, -angles.w, angles.z) * a.wy;
	B.zx = mat2(angles.xy, -angles.y, angles.x) * b.zx;
	B.wy = mat2(angles.zw, -angles.w, angles.z) * b.wy;
	float scaleA = 2./ -(A.w - 5);
	float scaleB = 2./ -(B.w - 5);
	A.xyz *= scaleA;
	B.xyz *= scaleB;
	scaleA *= .25;
	scaleB *= .25;
	vec3 Z = B.xyz - A.xyz;
	vec3 X = cross(vec3(0, 0, 1), Z);
	if (dot(X,X) < 0.01) 
		X = cross(vec3(0, 1, 0), Z);
	vec3 Y = cross(Z, X);
	X = normalize(X);
	Y = normalize(Y);
	vec3 N = cos(angle) * X + sin(angle) * Y;
	vec3 P = end > 0 ? A.xyz + scaleA * N : B.xyz + scaleB * N;
	gl_Position = vp * vec4( P, 1);
	normal = N;
}