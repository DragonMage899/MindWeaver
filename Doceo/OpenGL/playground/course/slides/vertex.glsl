#version 330 core
layout(location = 0) in vec3 vertexPos;
out vec3 fragmentCol;

void main() {
    gl_Position = vec4(vertexPos, 1.0);
    fragmentCol = vec3(1.0, 0.0, 0.0); // Pass red color to fragment shader
}