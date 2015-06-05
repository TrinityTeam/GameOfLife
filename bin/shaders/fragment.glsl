#version 330

out vec4 fragColor;
uniform int isLive;


void main() {
	fragColor = (isLive != 0) ? vec4(0.0f, 0.0f, 0.0f, 1.0f) : vec4(1.0f, 1.0f, 1.0f, 1.0f);
}
