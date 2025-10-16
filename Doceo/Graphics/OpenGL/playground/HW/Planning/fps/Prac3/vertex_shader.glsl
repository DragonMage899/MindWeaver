#version 330 core

// Input vertex data, different for all executions of this shader
layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexColor;

// Output data that will be passed to the fragment shader
out vec3 fragmentColor;

// Values that stay constant for the whole mesh
uniform mat4 model;

void main() {
    // Output position of the vertex, in clip space
    gl_Position = model * vec4(vertexPosition, 1);
    
    // The color of each vertex will be interpolated
    // to produce the color of each fragment
    fragmentColor = vertexColor;
}