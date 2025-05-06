#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "shader.hpp"

#include "Matrix.h"
#include "Vector.h"
#include "shapes3.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window);

int main(void) {
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(800, 600, "IT Kiosk Floor Plan", NULL, NULL);
    if (!window) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_NEAREST);
    glDisable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //=====================================================

    // Shader setup
    GLuint programID = LoadShaders("vertexShader.glsl", "fragmentShader.glsl");
    if (programID == 0) {
        std::cerr << "Failed to load shaders." << std::endl;
        return -1;
    }

    // VAO setup
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // IT Kiosk Floor Plan Definition
    std::vector<Shape*> kioskElements;

    // 1. Base floor (main rectangle)
    float baseFloorPoints[] = {
        -0.9f, -0.9f, 0.0f,
        0.9f, -0.9f, 0.0f,
        0.9f, 0.9f, 0.0f,
        -0.9f, 0.9f, 0.0f
    };
    Rectangle baseFloor(programID, VAO, baseFloorPoints);
    baseFloor.setColor(0.5f, 0.5f, 0.5f); // Grey color for the floor
    kioskElements.push_back(&baseFloor);

    // 2. Central walkway
    float walkwayPoints[] = {
        -0.1f, -0.9f, 0.0f,
        0.1f, -0.9f, 0.0f,
        0.1f, 0.9f, 0.0f,
        -0.1f, 0.9f, 0.0f
    };
    Rectangle walkway(programID, VAO, walkwayPoints);
    walkway.setColor(0.8f, 0.8f, 0.8f); // Lighter grey for walkway
    kioskElements.push_back(&walkway);

    // Seating booths (rectangles) - Increased number
    // 3. Booth 1
    float booth1Points[] = {
        -0.8f, 0.6f, 0.0f,
        -0.5f, 0.6f, 0.0f,
        -0.5f, 0.8f, 0.0f,
        -0.8f, 0.8f, 0.0f
    };
    Rectangle booth1(programID, VAO, booth1Points);
    booth1.setColor(0.9f, 0.9f, 0.9f); // Booth color
    kioskElements.push_back(&booth1);

    // 4. Booth 2
    float booth2Points[] = {
        0.5f, 0.6f, 0.0f,
        0.8f, 0.6f, 0.0f,
        0.8f, 0.8f, 0.0f,
        0.5f, 0.8f, 0.0f
    };
    Rectangle booth2(programID, VAO, booth2Points);
    booth2.setColor(0.9f, 0.9f, 0.9f);
    kioskElements.push_back(&booth2);

    // 5. Booth 3 (opposite side)
    float booth3Points[] = {
        -0.8f, 0.2f, 0.0f,
        -0.5f, 0.2f, 0.0f,
        -0.5f, 0.4f, 0.0f,
        -0.8f, 0.4f, 0.0f
    };
    Rectangle booth3(programID, VAO, booth3Points);
    booth3.setColor(0.9f, 0.9f, 0.9f);
    kioskElements.push_back(&booth3);

    // 6. Booth 4 (opposite side)
    float booth4Points[] = {
        0.5f, 0.2f, 0.0f,
        0.8f, 0.2f, 0.0f,
        0.8f, 0.4f, 0.0f,
        0.5f, 0.4f, 0.0f
    };
    Rectangle booth4(programID, VAO, booth4Points);
    booth4.setColor(0.9f, 0.9f, 0.9f);
    kioskElements.push_back(&booth4);

    // Tables (circles) - Increased number
    // 7. Table 1
    Circle table1(programID, VAO, 0.08f, -0.65f, 0.7f, 16);
    table1.setColor(1.0f, 1.0f, 0.7f); // Table color
    kioskElements.push_back(&table1);

    // 8. Table 2
    Circle table2(programID, VAO, 0.08f, 0.65f, 0.7f, 16);
    table2.setColor(1.0f, 1.0f, 0.7f);
    kioskElements.push_back(&table2);

    // 9. Table 3 (lower area)
    Circle table3(programID, VAO, 0.08f, -0.4f, 0.3f, 16);
    table3.setColor(1.0f, 1.0f, 0.7f);
    kioskElements.push_back(&table3);

    // 10. Table 4 (lower area)
    Circle table4(programID, VAO, 0.08f, 0.4f, 0.3f, 16);
    table4.setColor(1.0f, 1.0f, 0.7f);
    kioskElements.push_back(&table4);

    // Counter (rectangle)
    // 11. Counter
    float counterPoints[] = {
        -0.9f, -0.8f, 0.0f,
        -0.7f, -0.8f, 0.0f,
        -0.7f, -0.6f, 0.0f,
        -0.9f, -0.6f, 0.0f
    };
    Rectangle counter(programID, VAO, counterPoints);
    counter.setColor(0.7f, 0.7f, 1.0f); // Counter color
    kioskElements.push_back(&counter);

    // Decorative elements (rectangles) - Added more detail
    // 12. Decorative wall panel 1
    float panel1Points[] = {
        -0.9f, -0.5f, 0.0f,
        -0.9f, -0.3f, 0.0f,
        -0.85f, -0.3f, 0.0f,
        -0.85f, -0.5f, 0.0f
    };
    Rectangle panel1(programID, VAO, panel1Points);
    panel1.setColor(0.6f, 0.6f, 0.6f);
    kioskElements.push_back(&panel1);

    // 13. Decorative wall panel 2
    float panel2Points[] = {
        0.9f, -0.5f, 0.0f,
        0.9f, -0.3f, 0.0f,
        0.85f, -0.3f, 0.0f,
        0.85f, -0.5f, 0.0f
    };
    Rectangle panel2(programID, VAO, panel2Points);
    panel2.setColor(0.6f, 0.6f, 0.6f);
    kioskElements.push_back(&panel2);

    // 14. Divider 1
    float divider1Points[] = {
        -0.3f, 0.1f, 0.0f,
        -0.25f, 0.1f, 0.0f,
        -0.25f, 0.5f, 0.0f,
        -0.3f, 0.5f, 0.0f
    };
    Rectangle divider1(programID, VAO, divider1Points);
    divider1.setColor(0.7f, 0.7f, 0.7f);
    kioskElements.push_back(&divider1);

    // 15. Divider 2
    float divider2Points[] = {
        0.3f, 0.1f, 0.0f,
        0.25f, 0.1f, 0.0f,
        0.25f, 0.5f, 0.0f,
        0.3f, 0.5f, 0.0f
    };
    Rectangle divider2(programID, VAO, divider2Points);
    divider2.setColor(0.7f, 0.7f, 0.7f);
    kioskElements.push_back(&divider2);

    // Additional seating or low tables
    // 16. Seating 1
    float seating1Points[] = {
        -0.6f, -0.2f, 0.0f,
        -0.4f, -0.2f, 0.0f,
        -0.4f, -0.1f, 0.0f,
        -0.6f, -0.1f, 0.0f
    };
    Rectangle seating1(programID, VAO, seating1Points);
    seating1.setColor(0.85f, 0.85f, 0.85f);
    kioskElements.push_back(&seating1);

    // 17. Seating 2
    float seating2Points[] = {
        0.4f, -0.2f, 0.0f,
        0.6f, -0.2f, 0.0f,
        0.6f, -0.1f, 0.0f,
        0.4f, -0.1f, 0.0f
    };
    Rectangle seating2(programID, VAO, seating2Points);
    seating2.setColor(0.85f, 0.85f, 0.85f);
    kioskElements.push_back(&seating2);

    // 18. Small table 1
    Circle smallTable1(programID, VAO, 0.05f, -0.5f, -0.15f, 12);
    smallTable1.setColor(1.0f, 0.9f, 0.8f);
    kioskElements.push_back(&smallTable1);

    // 19. Small table 2
    Circle smallTable2(programID, VAO, 0.05f, 0.5f, -0.15f, 12);
    smallTable2.setColor(1.0f, 0.9f, 0.8f);
    kioskElements.push_back(&smallTable2);

    // 20. Entrance Area
    float entrancePoints[] = {
        -0.9f, -0.9f, 0.0f,
        -0.7f, -0.9f, 0.0f,
        -0.7f, -0.85f, 0.0f,
        -0.9f, -0.85f, 0.0f
    };
    Rectangle entrance(programID, VAO, entrancePoints);
    entrance.setColor(0.7f, 0.8f, 0.7f);
    kioskElements.push_back(&entrance);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.9f, 0.9f, 0.9f, 1.0f); // Light background
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Draw all kiosk elements
        for (Shape* element : kioskElements) {
            element->draw();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glDeleteVertexArrays(1, &VAO);
    glDeleteProgram(programID);

    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}