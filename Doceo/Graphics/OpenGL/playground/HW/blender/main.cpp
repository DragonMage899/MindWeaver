#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "shader.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

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
    float screenWidth = 800.0f;
    float screenHeight = 600.0f;
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
    if (!cubb->loadModel("cubb.obj")) {
            std::cout << "Failed to load cubb.obj meow" << std::endl;
            delete cubb; 
            glfwTerminate();
            return -1;
    }


    // Inside your main function, before the render loop or where you set up matrices:
    // Define camera parameters
    glm::vec3 cameraPos   = glm::vec3(0.0f, 0.0f,  3.0f); // Camera is at (0,0,3) in World Space
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f); // Looking towards negative Z
    glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f,  0.0f); // Head is up (set to 0,-1,0 to look upside-down)

    // Calculate the view matrix
    glm::mat4 view = glm::lookAt(cameraPos,             // Camera position
                                cameraPos + cameraFront, // Target position (where the camera is looking)
                                cameraUp);               // Up vector

    glm::vec3 resize = glm::vec3(0.25, 0.25, 0.25);
    cubb->scale(resize);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

                /* Render here */
        glClearColor(0.485f, 0.592f, 0.767f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        GLint viewLoc = glGetUniformLocation(programID, "view");
        if (viewLoc != -1) {
            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        } else {
            std::cerr << "Warning: Uniform 'view' not found in shader program " << programID << std::endl;
        }



        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)screenWidth / (float)screenHeight, 0.1f, 100.0f);
        
        GLint projLoc = glGetUniformLocation(programID, "projection");
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

    // Example transformations for the cubb object
    // cubb->resetTransform(); // Start from identity if applying fresh transforms each frame
    // cubb->translate(glm::vec3(0.0f, 0.0f, -5.0f));
    // cubb->rotate( (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f) );

        //cubb->setDrawColor(1, 0, 0, 1.0f); 
        cubb->Draw();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
            cubb->rotate(glm::radians(1.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        }
        
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
            cubb->rotate(glm::radians(-1.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        }

        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
            cubb->rotate(glm::radians(1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        }
            
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
            cubb->rotate(glm::radians(-1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        }
            
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS){
            cubb->rotate(glm::radians(1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        }

        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS){
            cubb->rotate(glm::radians(-1.0f), glm::vec3(0.0f, 0.0f, 1.0f));
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