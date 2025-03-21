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
    window = glfwCreateWindow(800, 600, "u22490079", NULL, NULL);
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

    //render window size
    glViewport(0, 0, 800, 600);

    //update viewport on window resize
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //Floor Shapes
    //=====================================================

    float triangle[] = {
        0.2f, 0.1f, 0.0f, 
        0.5f, 0.4f, 0.0f,
        0.8f, 0.1f, 0.0f
    };

    float square[] = {
        -0.6f, -0.2f, 0.0f
    };


    float rect[] = {
        -0.8f, 0.8f, 0.0f, 
        -0.2f, 0.8f, 0.0f, 
        -0.2f, 0.6f, 0.0f, 
        -0.8f, 0.6f, 0.0f 
    };

    //Objects
    //=====================================================
    float floor[] = {
        0.9f, 0.9f, 0.0f
    };

    float door1[] = {
        -0.85f, 0.8f, 0.0f, 
        -0.8f, 0.8f, 0.0f, 
        -0.8f, 0.4f, 0.0f,
        -0.85f, 0.4f, 0.0f, 
    };

    float door2[] = {
        -0.85f, -0.4f, 0.0f,  
        -0.8f, -0.4f, 0.0f, 
        -0.8f, -0.8f, 0.0f,
        -0.85f, -0.8f, 0.0f 
    };

    float table1[] = {
        -0.6f, 0.4f, 0.0f, 
        -0.4f, 0.4f, 0.0f, 
        -0.4f, 0.2f, 0.0f,
        -0.6f, 0.2f, 0.0f, 
    };

    float table2[] = {
        -0.6f, -0.2f, 0.0f, 
        -0.4f, -0.2f, 0.0f, 
        -0.4f, -0.4f, 0.0f,
        -0.6f, -0.4f, 0.0f, 
    };

    float counter[] = {
        0.6f, 0.7f, 0.0f, 
        0.8f, 0.7f, 0.0f, 
        0.8f, -0.7f, 0.0f,
        0.6f, -0.7f, 0.0f, 
    };

    float plant1[] = {
        0.0f, 0.6f, 0.0f, 
        0.1f, 0.6f, 0.0f,
        0.05f, 0.7f, 0.0f
    };

    float plant2[] = {
        0.0f, -0.6f, 0.0f, 
        0.1f, -0.6f, 0.0f,
        0.05f, -0.7f, 0.0f
    };


    float nil_pt[] = {
        0.0f, 0.0f, 1.0f, 
        0.0f, -0.0f, 1.0f,
        0.0f, 0.0f, 1.0f
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
        // Triangle t(programID, VAO, triangle);
        // t.setColor(0.224f, 0.831f, 0.494f);

        // Square s(programID, VAO, square, 0.2);
        // s.setColor(0.4f, 0.137f, 0.49f);

        // Rectangle r(programID, VAO, rect);
        // r.setColor(0.329f, 0.549f, 1.0f);


        // Circle c(programID, VAO, 0.2, 0, 0, 12);
        // c.setColor(1.0f, 1.0f, 0.0f);

        //Static Shapes
        Square carpet(programID, VAO, floor, 1.8);
        carpet.setColor(0.44f, 0.44f, 0.44f);

        std::vector<Shape*> static_shapes;
        Rectangle object_door1(programID, VAO, door1);
        Rectangle object_door2(programID, VAO, door2);
        Rectangle object_conter(programID, VAO, counter);
        object_door1.setColor(0.486f, 0.855f, 0.922f);
        object_door2.setColor(0.486f, 0.855f, 0.922f);
        object_conter.setColor(0.49f, 0.396f, 0.95f);
        static_shapes.push_back(&carpet);
        static_shapes.push_back(&object_door1);
        static_shapes.push_back(&object_door2);
        static_shapes.push_back(&object_conter);

        
        
        std::vector<Shape*> tables;
        Rectangle object_table1(programID, VAO, table1);
        Rectangle object_table2(programID, VAO, table2);
        object_table1.setColor(0.7f, 0.5f, 0.2f);
        object_table2.setColor(0.7f, 0.5f, 0.2f);
        tables.push_back(&object_table1);
        tables.push_back(&object_table2);

        std::vector<Shape*> trashcans;
        Circle trash1(programID, VAO, 0.035, -0.7, 0.8, 7);
        Circle trash2(programID, VAO, 0.035, -0.7, -0.8, 7);
        Circle trash3(programID, VAO, 0.035, 0.5, 0.8, 7);
        Circle trash4(programID, VAO, 0.035, 0.5, -0.8, 7);
        trash1.setColor(0.0f, 0.0f, 0.0f);
        trash2.setColor(0.0f, 0.0f, 0.0f);
        trash3.setColor(0.0f, 0.0f, 0.0f);
        trash4.setColor(0.0f, 0.0f, 0.0f);
        trashcans.push_back(&trash1);
        trashcans.push_back(&trash2);
        trashcans.push_back(&trash3);
        trashcans.push_back(&trash4);

        std::vector<Shape*> plants;
        Triangle object_plant1(programID, VAO, plant1);
        Triangle object_plant2(programID, VAO, plant2);
        object_plant1.setColor(0.0f, 0.78f, 0.376f);
        object_plant2.setColor(0.0f, 0.78f, 0.376f);
        plants.push_back(&object_plant1);
        plants.push_back(&object_plant2);

        std::vector<Shape*> chairs;
        Circle chair1(programID, VAO, 0.08, -0.3, 0.2, 70);
        Circle chair2(programID, VAO, 0.08, 0.3, 0.2, 70);
        Circle chair3(programID, VAO, 0.08, -0.3, -0.2, 70);
        Circle chair4(programID, VAO, 0.08, 0.3, -0.2, 70);
        chair1.setColor(0.68f, 0.24f, 0.24f);
        chair2.setColor(0.68f, 0.24f, 0.24f);
        chair3.setColor(0.68f, 0.24f, 0.24f);
        chair4.setColor(0.68f, 0.24f, 0.24f);
        chairs.push_back(&chair1);
        chairs.push_back(&chair2);
        chairs.push_back(&chair3);
        chairs.push_back(&chair4);

        std::vector<Shape*> people;
        Circle player(programID, VAO, 0.02, -0.85, 0.8, 12);
        player.setColor(1.0f, 1.0f, 1.0f);
        chairs.push_back(&player);

        Triangle nil(programID, VAO, nil_pt);

        bool wire = false;
        Shape* selected = &player;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        /* Render here */
        glClearColor(0.485f, 0.592f, 0.767f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Use the shader program
        //glUseProgram(programID);

        //t.prt();
        // t.draw();
        // s.draw();
        // r.draw();
        // c.draw();

        for(Shape* s : static_shapes){
            if(!wire)
                {s->draw();}
            else
                {s->draw_wireframe();}
        }

        for(Shape* s : tables){
            if(!wire)
                {s->draw();}
            else
                {s->draw_wireframe();}
        }

        for(Shape* s : trashcans){
            if(!wire)
                {s->draw();}
            else
                {s->draw_wireframe();}
        }

        for(Shape* s : plants){
            if(!wire)
                {s->draw();}
            else
                {s->draw_wireframe();}
        }

        for(Shape* s : chairs){
            if(!wire)
                {s->draw();}
            else
                {s->draw_wireframe();}
        }

        for(Shape* s : people){
            if(!wire)
                {s->draw();}
            else
                {s->draw_wireframe();}
        }

        
        
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
            selected->moveUp();
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        {
            selected->moveDown();
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
            selected->moveRight();
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
            selected->moveLeft();
        }
        if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
        {
            wire = !wire;            
        }

        if (glfwGetKey(window, GLFW_KEY_MINUS) == GLFW_PRESS)
        {
            selected->scale(0.99f);
        }

        if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS)
        {
            selected->scale(1.01f);
        }
        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        {
            selected->rotate(3.0f);
        }
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        {
            selected->rotate(-3.0f);
        }

        if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS)
        {
            selected = &nil;
        }

        if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
        {   
            selected->pastelOff();
            selected = chairs[0];
            selected->pastelOn();
        }

        if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
        {
            selected->pastelOff();
            selected = tables[0];
            selected->pastelOn();
        }

        if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
        {
            selected->pastelOff();
            selected = plants[0];
            selected->pastelOn();
        }

        if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
        {
            selected->pastelOff();
            selected = trashcans[0];
            selected->pastelOn();
        }

        if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
        {
            selected = &player;
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