#version 330 core
layout(location = 0) in vec3 aPos;        // Vertex Position
layout(location = 1) in vec3 aNormal;     // Vertex Normal (for lighting, if you add it later)
layout(location = 2) in vec2 aTexCoords;  // Texture Coordinates

out vec2 TexCoords;
// out vec3 FragPos_world; // For lighting in world space
// out vec3 Normal_world;  // For lighting in world space

uniform mat4 model;      // Model matrix (object's transformations)
uniform mat4 view;       // View matrix (camera)
uniform mat4 projection; // Projection matrix (perspective/orthographic)

void main() {
    // Transform vertex position to clip space
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    
    // Pass texture coordinates to the fragment shader
    TexCoords = aTexCoords;

    // For lighting (calculate world space position and normal)
    // FragPos_world = vec3(model * vec4(aPos, 1.0));
    // Normal_world = mat3(transpose(inverse(model))) * aNormal; // Normal matrix
}
