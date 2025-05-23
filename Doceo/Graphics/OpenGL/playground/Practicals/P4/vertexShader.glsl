#version 330 core
layout(location = 0) in vec3 vertexPosition_modelspace;
uniform vec4 color; 

out vec4 fragmentColor; 

void main() {
    gl_Position = vec4(vertexPosition_modelspace, 1.0);
    fragmentColor = color;
}
