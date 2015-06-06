#version 330

out vec4 fragColor;
uniform int cellState;


void main() {
	if (cellState == 0) {
		fragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	
	} else if (cellState == 1) {
		fragColor = vec4(0.0f, 0.0f, 0.0f, 1.0f);
	
	} else if (cellState == 2) {
		fragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f);
	
	} else if (cellState == 3) {
		fragColor = vec4(0.0f, 1.0f, 0.0f, 1.0f);
	}
}
