#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "shader.h"

#include "Matrix.h"
#include "Vector.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    //std::cout << "Window Resized" << std::endl;
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window);

int main(void){

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

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = GL_TRUE; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    // Tell OpenGL the size of the render window 
    glViewport(0, 0, 800, 600);

    // Update viewport on window resize
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Vertex data for a rectagnle
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f,
    };


    //testing
    //=====================================================
    float points[] = {
        -0.8f, 0.8f, 0.0f, 
        -0.2f, 0.8f, 0.0f,
    };

    float lines[] = {
        -0.8f, 0.6f, 0.0f, 
        -0.2f, 0.6f, 0.0f, 
    };

    float lines_strip[] = {
        -0.8f, 0.4f, 0.0f, 
        -0.2f, 0.4f, 0.0f,
        -0.8f, 0.2f, 0.0f, 
        -0.2f, 0.2f, 0.0f
    };

    float lines_loop[] = {
        0.2f, 0.8f, 0.0f, 
        0.4f, 0.6f, 0.0f,
        0.6f, 0.7f, 0.0f, 
        0.8f, 0.5f, 0.0f
    };

    float triangle[] = {
        0.2f, 0.1f, 0.0f, 
        0.5f, 0.4f, 0.0f,
        0.8f, 0.1f, 0.0f
    };

    float triangles_strip[] = {
        0.2f, -0.2f, 0.0f, 
        0.4f, -0.8f, 0.0f,
        0.6f, -0.2f, 0.0f,
        0.8f, -0.8f, 0.0f
    };

    float triangle_fan[] = {
        -0.5f, -0.8f, 0.0f, 
        -0.2f, -0.6f, 0.0f,
        -0.4f, -0.2f, 0.0f, 
        -0.6f, -0.2f, 0.0f,
        -0.8f, -0.6f, 0.0f
    };
    //=====================================================

    unsigned int indices[] = { // note that we start from 0!
        0, 1, 3, // first triangle
        1, 2, 3 // second triangle
    };

    // Generate and bind the VAO
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Generate and bind the VBO
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //Generate and bind the EBO for rectangle
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Define how OpenGL should interpret vertex data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Compile and load shaders
    GLuint programID = LoadShaders("vertex.glsl", "fragment.glsl");
    if (programID == 0) {
        std::cerr << "Failed to load shaders." << std::endl;
        return -1;
    }

    //Set Color
    glUseProgram(programID);
    float color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLint colorLoc = glGetUniformLocation(programID, "color");
        if (colorLoc != -1) {
            glUniform4fv(colorLoc, 1, color);
        } else{
            std::cout << "Could not load colors!" << std::endl;
        }

    glBindVertexArray(VAO);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        /* Render here */
        glClearColor(0.485f, 0.592f, 0.767f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Use the shader program
        glUseProgram(programID);

        // Bind the VAO and draw the triangle
        // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        // glBindVertexArray(VAO);
        // glDrawArrays(GL_TRIANGLES, 0, 3);

        glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
        glBindVertexArray(VAO);
        glDrawArrays(GL_POINTS, 0, 2);

        glBufferData(GL_ARRAY_BUFFER, sizeof(lines), lines, GL_STATIC_DRAW);
        glBindVertexArray(VAO);
        glDrawArrays(GL_LINES, 0, 2);

        glBufferData(GL_ARRAY_BUFFER, sizeof(lines_strip), lines_strip, GL_STATIC_DRAW);
        glBindVertexArray(VAO);
        glDrawArrays(GL_LINE_STRIP, 0, 4);

        glBufferData(GL_ARRAY_BUFFER, sizeof(lines_loop), lines_loop, GL_STATIC_DRAW);
        glBindVertexArray(VAO);
        glDrawArrays(GL_LINE_LOOP, 0, 4);

        glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3); //use line loop to get a non filled in triangle

        glBufferData(GL_ARRAY_BUFFER, sizeof(triangles_strip), triangles_strip, GL_STATIC_DRAW);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        

        glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_fan), triangle_fan, GL_STATIC_DRAW);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 5);

            //Enable Wireframe
        //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
            //Diable Wireframe
        //glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

        // Bind the VAO and draw the triangle
        //glBindVertexArray(VAO);
        //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); 
            //glDrawElements -> want to render triangles from an index buffer


        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    // Clean up
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(programID);

    // Terminate GLFW
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}