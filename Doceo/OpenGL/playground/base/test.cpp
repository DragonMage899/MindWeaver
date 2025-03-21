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
#include "shapes.h"

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

    float triangle[] = {
        0.2f, 0.1f, 0.0f, 
        0.5f, 0.4f, 0.0f,
        0.8f, 0.1f, 0.0f
    };

    float square[] = {
        -0.6f, -0.2f, 0.0f
    };

    float floor[] = {
        0.9f, 0.9f, 0.0f
    };

    float rect[] = {
        -0.8f, 0.8f, 0.0f, 
        -0.2f, 0.8f, 0.0f, 
        -0.2f, 0.6f, 0.0f, 
        -0.8f, 0.6f, 0.0f 
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

    //Shapes
        Square carpet(programID, VAO, floor, 1.8);
        carpet.setColor(0.44f, 0.44f, 0.44f);

        Triangle t(programID, VAO, triangle);
        t.setColor(0.224f, 0.831f, 0.494f);

        Square s(programID, VAO, square, 0.2);
        s.setColor(0.4f, 0.137f, 0.49f);

        Rectangle r(programID, VAO, rect);
        r.setColor(0.329f, 0.549f, 1.0f);


        Circle c(programID, VAO, 0.2, 0, 0, 12);
        c.setColor(1.0f, 1.0f, 0.0f);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        /* Render here */
        glClearColor(0.485f, 0.592f, 0.767f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Use the shader program
        //glUseProgram(programID);


        carpet.draw();

        //t.prt();
        t.draw();
        s.draw();
        r.draw();
        c.draw();
        
        // glUseProgram(programID);
        // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        // glBindVertexArray(VAO);
        // glDrawArrays(GL_TRIANGLES, 0, 3); //use line loop to get a non filled in triangle

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        {
            t.moveUp();
            s.moveUp();
            r.moveUp();
            c.moveUp();
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        {
            t.moveDown();
            s.moveDown();
            r.moveDown();
            c.moveDown();
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
            t.moveRight();
            s.moveRight();
            r.moveRight();
            c.moveRight();
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
            t.moveLeft();
            s.moveLeft();
            r.moveLeft();
            c.moveLeft();
        }
        if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
        {
            t.toggleWireframe();
            s.toggleWireframe();
            r.toggleWireframe();
            c.toggleWireframe();

            
        }

        if (glfwGetKey(window, GLFW_KEY_MINUS) == GLFW_PRESS)
        {
            t.scale(0.8f);
            s.scale(0.8f);
            r.scale(0.8f);
            c.scale(0.8f);
        }

        if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS)
        {
            t.scale(1.1f);
            s.scale(1.1f);
            r.scale(1.1f);
            c.scale(1.1f);
        }
        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        {
            t.rotate(3.0f);
            s.rotate(3.0f);
            r.rotate(3.0f);
            c.rotate(3.0f);
        }
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        {
            t.rotate(-3.0f);
            s.rotate(-3.0f);
            r.rotate(-3.0f);
            c.rotate(-3.0f);
        }
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