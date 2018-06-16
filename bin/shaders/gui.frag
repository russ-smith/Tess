#version 330 core

uniform sampler2D buttons;

in vec2 vuv;
out vec4 color;

void main(){
	color = texture(buttons, vuv);
}