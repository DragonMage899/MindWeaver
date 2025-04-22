#ifndef SHAPES_H
#define SHAPES_H

#include "Vector.h"
#include "Matrix.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <vector>

class Shape {
protected:
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    float color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    bool isPastel = false;
    bool wireframe = false;
    unsigned int shader_program;
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;

public:
    Shape(unsigned int sid, unsigned int vao) : shader_program(sid), VAO(vao) {
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
    }

    Shape(unsigned int sid, unsigned int vao, unsigned int ebo) : shader_program(sid), VAO(vao), EBO(ebo){
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
    }

    virtual ~Shape() {}

    void setColor(float red, float green, float blue, float alpha = 1.0f) {
        color[0] = red;
        color[1] = green;
        color[2] = blue;
        color[3] = alpha;
    }

    void pastelOn(){
        float alpha = 0.7;
        if (isPastel) return;
        for (int i = 0; i < 3; ++i) {
            color[i] = color[i] + alpha * (1.0f - color[i]);
        }
        isPastel = true;
    }

    void pastelOff(){
        float alpha = 0.7;
        if (!isPastel) return; 
        for (int i = 0; i < 3; ++i) {
            color[i] = (color[i] - alpha) / (1.0f - alpha); 
        }
        isPastel = false;
    }

    void toggleWireframe() {
        if(wireframe){
            wireframe = false;
        }
        else{
            wireframe = true;
        }

    }

    virtual void draw() {
        glUseProgram(shader_program);
        
        GLint colorLoc = glGetUniformLocation(shader_program, "color");
        if (colorLoc != -1) {
            glUniform4fv(colorLoc, 1, color);
        }

        glBindVertexArray(VAO);
        

        if (wireframe) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        } else {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }

    }

virtual void moveUp() {}

virtual void moveDown() {}

virtual void moveLeft() {}

virtual void moveRight() {}\

virtual float* getCentre(){
    float* centre = new float[2];
    centre[0] = 0.0f;  
    centre[1] = 0.0f; 

    int vertCount = vertices.size() / 3;

    for(int i = 0; i < vertices.size(); i += 3){
        centre[0] += vertices[i];
        centre[1] += vertices[i + 1];
    }

    if(vertCount > 0){
        centre[0] /= vertCount;
        centre[1] /= vertCount;
    }

    return centre;
}
    
virtual void rotate(float rotate_angle){}

virtual void scale(float scale_value) {}


virtual void draw_wireframe() {
    glUseProgram(shader_program);
    
    GLint colorLoc = glGetUniformLocation(shader_program, "color");
    if (colorLoc != -1) {
        glUniform4fv(colorLoc, 1, color);
    }

    glBindVertexArray(VAO);
}

};

#endif