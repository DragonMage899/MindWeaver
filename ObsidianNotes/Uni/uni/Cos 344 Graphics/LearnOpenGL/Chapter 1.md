# Basics

## GLFW

- Provide approparete layout for multi platform

- Create Window

- Crate opengl context

- Access basic things like input

  

## Viewport

glViewport(0, 0, 800, 600);

can be smaller than opengl window, then we can add other stuff outside of opengl
Behind the scenes OpenGL uses the data specified via glViewport to transform the 2D
coordinates it processed to coordinates on your screen. For example, a processed point of
location (-0.5,0.5) would (as its final transformation) be mapped to (200,450)
in screen coordinates. Note that processed coordinates in OpenGL are between -1 and 1
so we effectively map from the range (-1 to 1) to (0, 800) and (0, 600).


Also want to dynamically adjust viewport when resizing
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
glViewport(0, 0, width, height);
}
  
## Double buffers
Double buffer When an application draws in a single buffer the resulting image may
display flickering issues. This is because the resulting output image is not drawn in an
instant, but drawn pixel by pixel and usually from left to right and top to bottom. Because
this image is not displayed at an instant to the user while still being rendered to, the result
may contain artifacts. To circumvent these issues, windowing applications apply a double
buffer for rendering. The front buffer contains the final output image that is shown at
the screen, while all the rendering commands draw to the back buffer. As soon as all
the rendering commands are finished we swap the back buffer to the front buffer so the
image can be displayed without still being rendered to, removing all the aforementioned
artifacts.

  

## Screen clear
We can clear the screen’s
color buffer using glClear where we pass in buffer bits to specify which buffer we would like
to clear. The possible bits we can set are

GL_COLOR_BUFFER_BIT
GL_DEPTH_BUFFER_BIT
GL_STENCIL_BUFFER_BIT
### color
glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //statew setting function
glClear(GL_COLOR_BUFFER_BIT);
when glClear is called the screen will be replaced by whatever we set in glClearColor

## Pipeline
Graphics pipeline transforms 3D coordinates into 2D pixels
Two Part Process
- Transform 3D cords into 2d Cords
- Transform 2D cords into colored pixels


Split into steps, each step takes previous step output as input
Can be run in paralel
### Shaders
gpu cores run shaders
some shaders are configurable allowing us to write outr wpn shaders to replace existing one
fine grained control over parts of the pipeline
Shaders are written on GLSL (openGL Shading Language)

![[Pasted image 20250316150427.png]]

# Pipeline Execution

Starting input: List of Three 3D cords that should form a triangle
- Vertex Data array
- collection of vertices
![[Pasted image 20250316150803.png]]

**Vertex Shader**
- First part of pipeline
- Takes single vertex as input
- Allows use to do basic processing on vertex attributes 

**Primitive Assembly**
- 