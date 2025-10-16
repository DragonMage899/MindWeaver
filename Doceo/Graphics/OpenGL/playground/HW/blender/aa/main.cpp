#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "shader.hpp"

#include "ObjLoader.h"

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
    window = glfwCreateWindow(800, 600, "u22490079", NULL, NULL);
    if (!window)
    {  
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_NEAREST);
    glDisable(GL_CULL_FACE);

    // Initialize GLEW
    glewExperimental = GL_TRUE; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    //render window size
    glViewport(0, 0, 800, 600);

    //update viewport on window resize
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

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
    unsigned int indices[] = { // note that we start from 0!
        0, 1, 3, // first triangle
        1, 2, 3 // second triangle
    };

    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Define how OpenGL should interpret vertex data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Compile and load shaders
    GLuint programID = LoadShaders("vertexShader.glsl", "fragmentShader.glsl");
    if (programID == 0) {
        std::cerr << "Failed to load shaders." << std::endl;
        return -1;
    }
        
    ObjLoader* cubb = new ObjLoader(programID);
    if (!cubb->loadObject("cubb.obj")) {
            std::cout << "Failed to load cubb.obj meow" << std::endl;
            delete cubb; 
            glfwTerminate();
            return -1;
    }
    if (!cubb->loadTexture("cubb.png")) {
            std::cout << "Failed to load cubb.png meow" << std::endl;
    }

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        /* Render here */
        glClearColor(0.485f, 0.592f, 0.767f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //cubb->setDrawColor(1, 0, 0, 1.0f); 
        cubb->draw();

        //player.draw();
        
        // for(Shapes3D* sh: shp){
        //     sh->draw();
        // }

        // if(wiremode)
        //     scene->wire_draw();

        // else
        //     scene->draw();

        //std::cout << temp << std::endl;

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