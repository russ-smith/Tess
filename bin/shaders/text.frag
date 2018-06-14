#version 330 core

uniform sampler2D glyphs;

in vec2 vuv;
out vec4 col;

void main(){
	col = texture(glyphs, vuv);
}