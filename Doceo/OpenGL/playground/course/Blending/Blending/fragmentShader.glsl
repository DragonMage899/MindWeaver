#version 330 core

// Ouput data
out vec4 color;
in vec4 fragmentColor;

void main()
{

	// Output color = red 
	color = fragmentColor;

}