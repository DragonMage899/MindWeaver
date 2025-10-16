#version 330 core
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexNormal;
layout(location = 2) in vec2 vertexTexCoord;

uniform vec4 color; 
uniform mat4 MVP; // Model-View-Projection matrix (optional)

out vec4 fragmentColor; 
out vec2 texCoord;
out vec3 normal;

void main() {
    gl_Position = vec4(vertexPosition_modelspace, 1.0);
    fragmentColor = color;
    texCoord = vertexTexCoord;
    normal = vertexNormal;
}