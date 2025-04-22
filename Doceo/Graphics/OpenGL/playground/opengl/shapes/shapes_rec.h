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

    virtual ~Shape() {}

    void setColor(float red, float green, float blue, float alpha = 1.0f) {
        color[0] = red;
        color[1] = green;
        color[2] = blue;
        color[3] = alpha;
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
        
        // Set polygon mode based on wireframe flag
        if (wireframe) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        } else {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }

    }

    virtual void moveUp(){};
    virtual void moveDown(){};
    virtual void moveLeft(){};
    virtual void moveRight(){};

    virtual float* getCentre(){
        float* centre = new float[2];

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
    
    virtual void rotate(float rotate_angle) {
        float rad = rotate_angle * M_PI / 180.0f; // Convert degrees to radians
        float cosA = cos(rad);
        float sinA = sin(rad);

        // Create the rotation matrix
        double** rotMat = new double*[2];
        rotMat[0] = new double[2]{cosA, -sinA};
        rotMat[1] = new double[2]{sinA, cosA};
        Matrix<2, 2> rotationMatrix(rotMat);

        // Apply the rotation to each vertex
        for (size_t i = 0; i < vertices.size(); i += 3) {
            double* vertex = new double[2]{vertices[i], vertices[i + 1]};
            Vector<2> vertexVec(vertex);
            Vector<2> rotatedVertex = rotationMatrix * vertexVec;

            vertices[i] = rotatedVertex[0];
            vertices[i + 1] = rotatedVertex[1];
        }
    }

    virtual void scale(float scale_value) {
        // Create the scaling matrix
        double** scaleMat = new double*[2];
        scaleMat[0] = new double[2]{scale_value, 0};
        scaleMat[1] = new double[2]{0, scale_value};
        Matrix<2, 2> scalingMatrix(scaleMat);

        // Apply the scaling to each vertex
        for (size_t i = 0; i < vertices.size(); i += 3) {
            double* vertex = new double[2]{vertices[i], vertices[i + 1]};
            Vector<2> vertexVec(vertex);
            Vector<2> scaledVertex = scalingMatrix * vertexVec;

            vertices[i] = scaledVertex[0];
            vertices[i + 1] = scaledVertex[1];
        }
    }

    void prt(){}

};

class Triangle : public Shape {
public:
    Triangle(unsigned int sid, unsigned int vao, float points[9]) : Shape(sid, vao) {
        // Store vertices (x, y, z) for each corner
        vertices.resize(9);
        for (int i = 0; i < 9; i++) {
            vertices[i] = points[i];
        }

        indices = {0, 1, 2};
    }

    void draw() override {
        Shape::draw(); // Call parent draw for common setup

        // Update vertex buffer
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

        // Set up vertex attributes
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // Draw the triangle
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    void moveUp() override{
        vertices[1] += 0.01;
        vertices[4] += 0.01;
        vertices[7] += 0.01;
    }

    void moveDown()override{
        vertices[1] -= 0.01;
        vertices[4] -= 0.01;
        vertices[7] -= 0.01;
    }

    void moveLeft()override{
        vertices[0] -= 0.01;
        vertices[3] -= 0.01;
        vertices[6] -= 0.01;
    }

    void moveRight()override{
        vertices[0] += 0.01;
        vertices[3] += 0.01;
        vertices[6] += 0.01;
    }
};

class Square : public Shape {
public:
    Square(unsigned int sid, unsigned int vao, float points[3], float length) : Shape(sid, vao) {
        // Calculate all vertices based on top-right point and length
        float x2 = points[0];
        float y2 = points[1];
        float x1 = x2 - length;
        float y1 = y2 - length;

        // Create vertices in counter-clockwise order (standard for OpenGL)
        vertices = {
            x1, y1, 0.0f,  
            x2, y1, 0.0f,  
            x2, y2, 0.0f,  
            x1, y2, 0.0f   
        };

        // Indices for two triangles forming a square
        indices = {
            0, 1, 2,  
            2, 3, 0   
        };
    }

    void draw() override {
        Shape::draw(); // Call parent draw for common setup

        // Update vertex buffer
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

        // Set up vertex attributes
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // Update index buffer
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

        // Draw the square
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    }
    
    void moveUp() override{
        vertices[1] += 0.01;
        vertices[4] += 0.01;
        vertices[7] += 0.01;
        vertices[10] += 0.01;
    }

    void moveDown()override{
        vertices[1] -= 0.01;
        vertices[4] -= 0.01;
        vertices[7] -= 0.01;
        vertices[10] -= 0.01;
    }

    void moveLeft()override{
        vertices[0] -= 0.01;
        vertices[3] -= 0.01;
        vertices[6] -= 0.01;
        vertices[9] -= 0.01;
    }

    void moveRight()override{
        vertices[0] += 0.01;
        vertices[3] += 0.01;
        vertices[6] += 0.01;
        vertices[9] += 0.01;
    }
    
};

class Rectangle : public Shape {
public:
    Rectangle(unsigned int sid, unsigned int vao, float points[12]) : Shape(sid, vao) {
        // Use all 4 corner points directly
        vertices = {
            points[0], points[1], 0.0f,  // bottom-left
            points[3], points[4], 0.0f,  // bottom-right
            points[6], points[7], 0.0f,  // top-right
            points[9], points[10], 0.0f  // top-left
        };

        // Indices for two triangles forming a rectangle
        indices = {
            0, 1, 2,  // first triangle
            2, 3, 0   // second triangle
        };
    }

    void draw() override {
        Shape::draw(); // Call parent draw for common setup

        // Update vertex buffer
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

        // Set up vertex attributes
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // Update index buffer
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

        // Draw the rectangle
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    }

    void moveUp() override{
        vertices[1] += 0.01;
        vertices[4] += 0.01;
        vertices[7] += 0.01;
        vertices[10] += 0.01;
    }

    void moveDown()override{
        vertices[1] -= 0.01;
        vertices[4] -= 0.01;
        vertices[7] -= 0.01;
        vertices[10] -= 0.01;
    }

    void moveLeft()override{
        vertices[0] -= 0.01;
        vertices[3] -= 0.01;
        vertices[6] -= 0.01;
        vertices[9] -= 0.01;
    }

    void moveRight()override{
        vertices[0] += 0.01;
        vertices[3] += 0.01;
        vertices[6] += 0.01;
        vertices[9] += 0.01;
    }
};

class Circle : public Shape {
private:
    float radius;
    float center_x;
    float center_y;
    int segment_count;

public:
    Circle(unsigned int sid, unsigned int vao, float radius, float center_x, float center_y, int segment_count = 32)
        : Shape(sid, vao), radius(radius), center_x(center_x), center_y(center_y), segment_count(segment_count < 3 ? 3 : segment_count) {
        
        // Ensure a minimum number of segments for visual quality
        generateVertices();
    }

    void setSegmentCount(int count) {
        segment_count = count < 3 ? 3 : count;
        generateVertices();
    }

    void generateVertices() {
        // Clear existing data
        vertices.clear();
        indices.clear();

        // Add center vertex
        vertices.push_back(center_x);
        vertices.push_back(center_y);
        vertices.push_back(0.0f);

        // Generate vertices around the circle
        float angleStep = 2.0f * M_PI / segment_count;
        
        for (int i = 0; i <= segment_count; i++) {
            float angle = i * angleStep;
            float x = center_x + radius * std::cos(angle);
            float y = center_y + radius * std::sin(angle);
            
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(0.0f);
            
            // Add indices for triangle fan
            if (i < segment_count) {
                indices.push_back(0);  // Center
                indices.push_back(i + 1);
                indices.push_back(i + 2);
            }
        }
    }

    void draw() override {
        Shape::draw(); // Call parent draw for common setup

        // Update vertex buffer
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

        // Set up vertex attributes
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // Update index buffer
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

        // Draw the circle
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    }

    void moveUp()override{
        center_y += 0.01f;
        generateVertices();  // Regenerate all vertices with new center position
    }

    void moveDown()override{
        center_y -= 0.01f; 
        generateVertices();
    }

    void moveLeft()override{
        center_x -= 0.01f;
        generateVertices();
    }

    void moveRight()override{
        center_x += 0.01f;
        generateVertices();
    }

    float* getCentre()override{
        float* c = new float[2];
        c[0] = center_x;
        c[1] = center_y;

        return c;
    }
};