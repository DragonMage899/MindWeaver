#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Matrix.cpp"
#include "Vector.cpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    //std::cout << "Window Resized" << std::endl;
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window);

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
    if (!window)
    {  
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    if (!window)
    {  
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Tell opengl size of render window 
    glViewport(0, 0, 800, 600);
        //can be set to lower than window
        //all opengl renders would be displated in a smaller window and other elements ould be added outside of this

    //update viewport on window resize
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) //check if glfw window has been closed
    {
        processInput(window);
        /* Render here */
        glClearColor(0.485f, 0.592f, 0.767f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    //when glfw window closes termincate program
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window)
{
if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}