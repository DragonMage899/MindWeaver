#version 330 core
layout(location = 0) in vec3 vertexPos;
uniform vec4 color;

out vec4 fragmentCol;

void main() {
    gl_Position = vec4(vertexPos, 1.0);
    fragmentCol = color; 
}