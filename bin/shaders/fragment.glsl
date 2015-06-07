#version 330

out vec4 fragColor;
in vec2 currentTextureCoord;
uniform int cellState;
uniform sampler2D sampler;


void main() {
	if (cellState == 0) {
		fragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	
	} else if (cellState == 1) {
		fragColor = texture2D(sampler, currentTextureCoord.st);
	
	}
}
