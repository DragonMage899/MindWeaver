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
#include "scene.h"

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
    GLuint programID = LoadShaders("vertexShader.glsl", "fragmentShader.glsl");
    if (programID == 0) {
        std::cerr << "Failed to load shaders." << std::endl;
        return -1;
    }
        //Static Shapes
        std::vector<Shape*> people;
        Circle player(programID, VAO, 0.02, -0.85, 0.8, 12);
        player.setColor(1.0f, 0.0f, 0.0f);
        people.push_back(&player);

        Triangle nil(programID, VAO, nil_pt);

        bool wire = false;
        Shape* selected = &player;

        //2D

        //3D

        //cuboid
        Vector<3> cen(new double[3]{-0.6,0,0});
        Vector<3> colsCube(new double[3]{0,0.5,0.4});
        double hgt = 0.2;
        double wid = 0.2;
        double len = 0.2;
        Shapes3D* cube = new Cube(cen, hgt, wid, len, colsCube, programID, VAO);

        //tri prism
        Vector<3> baseA(new double[3]{0,0.8,0});
        Vector<3> baseB(new double[3]{-0.3,0.5,0});
        Vector<3> baseC(new double[3]{0.3,0.5,0});
        Vector<3> colsPrism(new double[3]{0.9,0.5,0.5});
        Shapes3D* prism = new TriangularPrism(baseA, baseB, baseC, 0.3, colsPrism, programID, VAO);

        //cone
        Vector<3> centerCone(new double[3]{0, -0.5, 0});
        Vector<3> colorCone(new double[3]{1, 0.6, 0});
        Shapes3D* cone = new Cone(centerCone, 0.3, 0.5, colorCone, programID, VAO, 16);

        //cyl
        Vector<3> centerCyl(new double[3]{0.5, 0, 0});
        Vector<3> colorCyl(new double[3]{0, 0.7, 0.7});
        Shapes3D* cylinder = new Cylinder(centerCyl, 0.2, 0.3, colorCyl, programID, VAO, 16);

        //sphere
        Vector<3> sphereCenter(new double[3]{0.0, 0.0, 0.0});
        Vector<3> sphereColor(new double[3]{0.2, 0.5, 0.8});
        double sphereRadius = 0.2;
        int sphereQuality = 20; 
        Sphere* sphere = new Sphere(sphereCenter, sphereRadius, sphereColor, programID, VAO, sphereQuality);


        Shapes3D* sel = cube;

        int index = 0;
        float currentOp = 1;
        bool wiremode = false;
        double temp = 0;

        //Scene
        Scene* scene = new Scene(programID, VAO);

        Shapes3D* glb = scene->getGlobe();
        Shapes3D* back = scene->getBack();

        std::vector<Shapes3D*> shp;
        shp.push_back(glb);
        shp.push_back(back);

        sel = glb;

        scene->rotate(0.3, 'Y');
        scene->rotate(-0.3, 'X');

        std::vector<float*> cols;
        static bool oKeyPressed = false; 


        float* red = new float[3]{1,0,0};
        float* green = new float[3]{0,1,0};
        float* blue = new float[3]{0,0,1};
        float* white = new float[3]{0,0,0};
        float* black = new float[3]{1,1,1};

        float* yellow = new float[3]{1,1,0};
        float* cyan = new float[3]{0,1,1};
        float* pink = new float[3]{1,0,1};
        float* purple = new float[3]{0.5,0,1};
        float* orange = new float[3]{1,0.5,0};

        cols.push_back(red);
        cols.push_back(green);
        cols.push_back(blue);
        cols.push_back(white);
        cols.push_back(black);
        cols.push_back(yellow);
        cols.push_back(cyan);
        cols.push_back(pink);
        cols.push_back(purple);
        cols.push_back(orange);
        int colIndex = 0;
        static int waiter = 0;

        


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        /* Render here */
        glClearColor(0.485f, 0.592f, 0.767f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //player.draw();
        
        // for(Shapes3D* sh: shp){
        //     sh->draw();
        // }

        if(wiremode)
            scene->wire_draw();

        else
            scene->draw();

        //std::cout << temp << std::endl;

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        {
            scene->rotate(0.006, 'X');
        }
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        {
            scene->rotate(-0.006, 'X');
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
            scene->rotate(0.006, 'Y');
        }
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {   
            scene->rotate(-0.006, 'Y');
        }
        if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        {
            scene->rotate(0.006, 'Z');          
        }

        if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        {
            scene->rotate(-0.006, 'Z');
        }

        if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS )
        {
            sel->rotate(0.06f, 'X');
        }
        if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
        {
            sel->rotate(-0.06f, 'X');
        }
        if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS )
        {
            sel->rotate(0.06f, 'Y');
        }
        if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
        {
            sel->translate(-0.004,0,0);
        }
        if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
        {
            sel->translate(0.004,0,0);
        }
        if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS )
        {
            sel->translate(0,0.004,0);
        }
        if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
        {
            sel->translate(0,-0.004,0);
        }
        if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS )
        {
            sel->translate(0,0,0.004);
        }
        if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
        {
            sel->translate(0,0,-0.004);
        }
        if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
        {   
            wiremode = !wiremode;
        }
        if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
        {
            sel->changeFaceColor();
        }
        if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS)
        {
            sel->setColor(0,1,0,1);
        }
        if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
        {   
            if(currentOp + 0.003 <= 1){
                currentOp += 0.003;
                sel->setOp(currentOp);
            }
        }
        if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
        {
            sel->translate(-0.004,0,0);
        }
        if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
        {   
            sel->translate(0.004,0,0);
        }
        if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
        {  
            //std::cout << waiter << std::endl;
            if(waiter == 75){
                waiter = 0;
            }

            if(waiter == 0){
                colIndex++;
                if(colIndex == 10){
                    colIndex = 0;
                    scene->updateSheetColor(cols[colIndex]);
                }
                else{
                    scene->updateSheetColor(cols[colIndex]);
                }
                waiter++;
            } else{
                waiter++;
            }
        }

        if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
        {  
            //std::cout << waiter << std::endl;
            if(waiter == 50){
                waiter = 0;
            }

            if(waiter == 0){
                colIndex--;
                if(colIndex < 0){
                    colIndex = 9;
                    scene->updateSheetColor(cols[colIndex]);
                }
                else{
                    scene->updateSheetColor(cols[colIndex]);
                }
                waiter++;
            } else{
                waiter++;
            }
        }
        if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
        {  
            //std::cout << waiter << std::endl;
            if(waiter == 75){
                waiter = 0;
            }

            if(waiter == 0){
                colIndex++;
                if(colIndex == 10){
                    colIndex = 0;
                    scene->updateGlassColor(cols[colIndex]);
                }
                else{
                    scene->updateGlassColor(cols[colIndex]);
                }
                waiter++;
            } else{
                waiter++;
            }
        }

        if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
        {  
            //std::cout << waiter << std::endl;
            if(waiter == 50){
                waiter = 0;
            }

            if(waiter == 0){
                colIndex--;
                if(colIndex < 0){
                    colIndex = 9;
                    scene->updateGlassColor(cols[colIndex]);
                }
                else{
                    scene->updateGlassColor(cols[colIndex]);
                }
                waiter++;
            } else{
                waiter++;
            }
        }
        if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
        {  
            scene->updateGlassAlpha(0.004);
        }
        if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS)
        {  
            scene->updateGlassAlpha(-0.004);
        }
        if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS)
        {  
            //std::cout << waiter << std::endl;
            if(waiter == 50){
                waiter = 0;
            }

            if(waiter == 0){
                colIndex--;
                if(colIndex < 0){
                    colIndex = 9;
                    scene->updateLightColor(cols[colIndex]);
                }
                else{
                    scene->updateLightColor(cols[colIndex]);
                }
                waiter++;
            } else{
                waiter++;
            }
        }
        if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS)
        {  
            //std::cout << waiter << std::endl;
            if(waiter == 50){
                waiter = 0;
            }

            if(waiter == 0){
                colIndex--;
                if(colIndex < 0){
                    colIndex = 9;
                    scene->updateLightColor(cols[colIndex]);
                }
                else{
                    scene->updateLightColor(cols[colIndex]);
                }
                waiter++;
            } else{
                waiter++;
            }
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