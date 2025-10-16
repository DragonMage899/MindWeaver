#version 330 core
out vec4 FragColor;

in vec2 TexCoords; // Interpolated texture coordinates from vertex shader
// in vec3 FragPos_world; // For lighting
// in vec3 Normal_world;  // For lighting

// Uniform for the diffuse texture sampler
uniform sampler2D texture_diffuse1; 
// Uniform for a base object color (can be used as a fallback or tint)
uniform vec4 objectColor; 
// Uniform to control whether to use texture or objectColor
uniform bool useTexture; 

void main() {
    if (useTexture) {
        // Sample color from the texture
        FragColor = texture(texture_diffuse1, TexCoords);
    } else {
        // Use the uniform object color
        FragColor = objectColor;
    }

    // Example of tinting:
    // FragColor = texture(texture_diffuse1, TexCoords) * objectColor;

    // If FragColor.a is very low (almost transparent), discard the fragment
    // This is useful for textures with alpha channels like PNGs for cutouts.
    if (FragColor.a < 0.1) {
        discard;
    }
}