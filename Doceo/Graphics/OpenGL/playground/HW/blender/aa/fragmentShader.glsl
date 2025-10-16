#version 330 core
in vec4 fragmentColor;
in vec2 texCoord;
in vec3 normal;

uniform sampler2D ourTexture;
uniform bool hasTexture = false;

out vec4 color;

void main() {
    if (hasTexture) {
        vec4 texColor = texture(ourTexture, texCoord);
        color = texColor * fragmentColor;
    } else {
        color = fragmentColor;
    }
}