#include "Vector.h"
#include "Matrix.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath> // For circle calculations

class Shape {
protected:
    float* vertices;
    int vertexCount;
    float col[4];
    bool wireframe = false;
    unsigned int shader_program;
    unsigned int VAO;

public:
    Shape(unsigned int sid, unsigned int vao) : shader_program(sid), VAO(vao) {}

    void setColour(float red, float green, float blue, float alpha) {
        this->col[0] = red;
        this->col[1] = green;
        this->col[2] = blue;
        this->col[3] = alpha;
    }

    virtual void draw() {};
};

class Triangle : public Shape {
private:

public:
    Triangle(unsigned int sid, unsigned int vao, float points[9]) : Shape(sid, vao){
        this->vertexCount = 9;
        this->vertices = new float[9];
        for (int i = 0; i < 9; i++) {
            this->vertices[i] = points[i];
        }
    }

    void draw() {
        glUseProgram(shader_program);
        glBindVertexArray(VAO);
        glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(float), this->vertices, GL_STATIC_DRAW);
        glDrawArrays(GL_TRIANGLES, 0, 3); // Use GL_LINE_LOOP for wireframe
    }

    ~Triangle() {
        delete[] vertices;
    }
};

class Square : public Shape {
private:

public:
    Square(unsigned int sid, unsigned int vao, float points[6]) : Shape(sid, vao){
        this->vertexCount = 12;
        this->vertices = new float[12];
        // given x1y1 x2x2
        this->vertices[0] = points[0];  // x1
        this->vertices[1] = points[1];  // y1
        this->vertices[2] = 0;          // z1
        this->vertices[3] = points[0];  // x2
        this->vertices[4] = points[4];  // y2
        this->vertices[5] = 0;          // z2
        this->vertices[6] = points[3];  // x3
        this->vertices[7] = points[4];  // y3
        this->vertices[8] = 0;          // z3
        this->vertices[9] = points[3];  // x4
        this->vertices[10] = points[1]; // y4
        this->vertices[11] = 0;         // z4

    }

    void draw() {
        glUseProgram(shader_program);
        glBindVertexArray(VAO);
        glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(float), this->vertices, GL_STATIC_DRAW);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }

    ~Square() {
        delete[] vertices;
    }
};

class Rectangle : public Shape {
private:

public:
    Rectangle(unsigned int sid, unsigned int vao, float points[12]) : Shape(sid, vao){
        this->vertexCount = 12;
        this->vertices = new float[8];
        // Assuming points are in the order: bottom-left, top-right
        this->vertices[0] = points[0]; // x1
        this->vertices[1] = points[1]; // y1
        this->vertices[2] = points[2]; // x2
        this->vertices[3] = points[1]; // y1
        this->vertices[4] = points[2]; // x2
        this->vertices[5] = points[3]; // y2
        this->vertices[6] = points[0]; // x1
        this->vertices[7] = points[3]; // y2
    }

    void draw() {
        unsigned int indices[] = { 
            0, 1, 3, // first triangle
            1, 2, 3 // second triangle
        };

        unsigned int EBO;
        glGenBuffers(1, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); 
    }

    ~Rectangle() {
        delete[] vertices;
    }
};

class Circle : public Shape {
private:
    int vertex_count;
    float radius;
public:
    Circle(unsigned int sid, unsigned int vao, float radius, float centre_x, float centre_y, int vertex_count = 10)
        : Shape(sid, vao), radius(radius), vertex_count(vertex_count) {
        // For a triangle fan, we need vertex_count + 2 vertices
        int totalVertices = vertex_count + 2;
        this->vertices = new float[totalVertices * 2];
        
        // Set the center point as the first vertex
        this->vertices[0] = centre_x;
        this->vertices[1] = centre_y;
        
        // Generate vertices around the circle
        float angleIncrement = 2 * M_PI / vertex_count;
        for (int i = 0; i <= vertex_count; i++) {
            float angle = i * angleIncrement;
            this->vertices[(i + 1) * 2] = centre_x + radius * cos(angle);
            this->vertices[(i + 1) * 2 + 1] = centre_y + radius * sin(angle);
        }
    }
    
    void draw() {
        glUseProgram(shader_program);
        glBindVertexArray(VAO);
        
        // Disable any element array buffer binding that might be active
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        
        // Set up the vertex buffer
        glBufferData(GL_ARRAY_BUFFER, (vertex_count + 2) * 2 * sizeof(float), this->vertices, GL_STATIC_DRAW);
        
        // Draw the circle
        glDrawArrays(GL_TRIANGLE_FAN, 0, vertex_count + 2);
    }
    
    ~Circle() {
        delete[] vertices;
    }
};