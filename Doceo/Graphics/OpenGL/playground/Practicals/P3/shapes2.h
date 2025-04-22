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
    std::string name = "m";

public:
    Shape(unsigned int sid, unsigned int vao) : shader_program(sid){
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
    }

    Shape(unsigned int sid) : shader_program(sid){
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
    }

    virtual ~Shape() {}

    void updateName(std::string n){
        name = n;
    }

    std::string getName(){
        return name;
    }

    //3D
    virtual std::vector<Vector<3>> getVertices() const {return {};}


    void print(){
        for(size_t i = 0; i < vertices.size(); i++){
            std::cout << "Start..." << std::endl;
            std::cout << vertices[i] << std::endl;
            std::cout << "End..." << std::endl;
        }
    }
    void setColor(float red, float green, float blue, float alpha = 1.0f) {
        color[0] = red;
        color[1] = green;
        color[2] = blue;
        color[3] = alpha;
    }

    void updateOpacity(float op){
        color[3] = op;
    }

    virtual void applyTransform(const Matrix<4, 4>& M){};

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

    virtual void toggleWireframe() {
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

virtual void moveUp() {
    for (size_t i = 1; i < vertices.size(); i += 3) {
        if (vertices[i] + 0.01f >= 0.9f) return; 
    }
    for (size_t i = 1; i < vertices.size(); i += 3) {
        vertices[i] += 0.01f; 
    }
}

virtual void moveDown() {
    for (size_t i = 1; i < vertices.size(); i += 3) {
        if (vertices[i] - 0.01f <= -0.9f) return;
    }
    for (size_t i = 1; i < vertices.size(); i += 3) {
        vertices[i] -= 0.01f; 
    }
}

virtual void moveLeft() {
    for (size_t i = 0; i < vertices.size(); i += 3) {
        if (vertices[i] - 0.01f <= -0.9f) return;
    }
    for (size_t i = 0; i < vertices.size(); i += 3) {
        vertices[i] -= 0.01f; 
    }
}

virtual void moveRight() {
    for (size_t i = 0; i < vertices.size(); i += 3) {
        if (vertices[i] + 0.01f >= 0.9f) return;
    }
    for (size_t i = 0; i < vertices.size(); i += 3) {
        vertices[i] += 0.01f; 
    }
}


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

    
virtual void rotate(float rotate_angle) {
    float* center = getCentre();
    float centerX = center[0];
    float centerY = center[1];
    delete[] center; 

    float rad = rotate_angle * M_PI / 180.0f; 
    float cosA = cos(rad);
    float sinA = sin(rad);

    double** rotMat = new double*[2];
    rotMat[0] = new double[2]{cosA, -sinA};
    rotMat[1] = new double[2]{sinA, cosA};
    Matrix<2, 2> rotationMatrix(rotMat);

    for (size_t i = 0; i < vertices.size(); i += 3) {
        float translatedX = vertices[i] - centerX;
        float translatedY = vertices[i + 1] - centerY;
        double** vertexMat = new double*[2];
        vertexMat[0] = new double[1]{translatedX};
        vertexMat[1] = new double[1]{translatedY};
        Matrix<2, 1> vertexMatrix(vertexMat);
        Matrix<2, 1> rotatedVertexMatrix = rotationMatrix * vertexMatrix;
        vertices[i] = rotatedVertexMatrix[0][0] + centerX;
        vertices[i + 1] = rotatedVertexMatrix[1][0] + centerY;
    }
}

virtual void scale(float scale_value) {
    float* center = getCentre();
    float centerX = center[0];
    float centerY = center[1];
    delete[] center;
    double** scaleMat = new double*[2];
    scaleMat[0] = new double[2]{scale_value, 0};
    scaleMat[1] = new double[2]{0, scale_value};
    Matrix<2, 2> scalingMatrix(scaleMat);

    for (size_t i = 0; i < vertices.size(); i += 3) {
        float translatedX = vertices[i] - centerX;
        float translatedY = vertices[i + 1] - centerY;

        double** vertexMat = new double*[2];
        vertexMat[0] = new double[1]{translatedX};
        vertexMat[1] = new double[1]{translatedY};
        Matrix<2, 1> vertexMatrix(vertexMat);
        Matrix<2, 1> scaledVertexMatrix = scalingMatrix * vertexMatrix;
        vertices[i] = scaledVertexMatrix[0][0] + centerX;
        vertices[i + 1] = scaledVertexMatrix[1][0] + centerY;
    }
}

    void prt(){}

    virtual void draw_wireframe() {
        glUseProgram(shader_program);
        
        GLint colorLoc = glGetUniformLocation(shader_program, "color");
        if (colorLoc != -1) {
            glUniform4fv(colorLoc, 1, color);
        }

        glBindVertexArray(VAO);
}

};

class Triangle : public Shape {
public:
    Triangle(unsigned int sid, unsigned int vao, float points[9]) : Shape(sid, vao) {
        vertices.resize(9);
        for (int i = 0; i < 9; i++) {
            vertices[i] = points[i];
        }

        indices = {0, 1, 2};
    }

    void draw() override {
        Shape::draw(); 

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    void draw_wireframe() override {
        Shape::draw_wireframe(); 

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        std::vector<unsigned int> wireframeIndices = {0, 1, 1, 2, 2, 0};

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, wireframeIndices.size() * sizeof(unsigned int), wireframeIndices.data(), GL_STATIC_DRAW);
        glDrawElements(GL_LINES, wireframeIndices.size(), GL_UNSIGNED_INT, 0);
    }
};

class Square : public Shape {
public:
    Square(unsigned int sid, unsigned int vao, float points[3], float length) : Shape(sid, vao) {
        float x2 = points[0];
        float y2 = points[1];
        float x1 = x2 - length;
        float y1 = y2 - length;

        vertices = {
            x1, y1, 0.0f,  
            x2, y1, 0.0f,  
            x2, y2, 0.0f,  
            x1, y2, 0.0f   
        };

        indices = {0, 1, 2, 2, 3, 0 };
    }

    void draw() override {
        Shape::draw(); 

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    }
    
    void draw_wireframe() override {
        Shape::draw_wireframe(); 

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        std::vector<unsigned int> wireframeIndices = {0, 1, 1, 2, 2, 3, 3, 0};

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, wireframeIndices.size() * sizeof(unsigned int), wireframeIndices.data(), GL_STATIC_DRAW);
        glDrawElements(GL_LINES, wireframeIndices.size(), GL_UNSIGNED_INT, 0);
    }
    
};

class Rectangle : public Shape {
public:
    Rectangle(unsigned int sid, unsigned int vao, float points[12]) : Shape(sid, vao) {
        vertices = {
            points[0], points[1], 0.0f,  
            points[3], points[4], 0.0f,  
            points[6], points[7], 0.0f,  
            points[9], points[10], 0.0f  
        };

        indices = {0, 1, 2, 2, 3, 0 };
    }

    void draw() override {
        Shape::draw(); 

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    }

    void draw_wireframe() override {
        Shape::draw_wireframe(); 

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        std::vector<unsigned int> wireframeIndices = {0, 1, 1, 2, 2, 3, 3, 0};
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, wireframeIndices.size() * sizeof(unsigned int), wireframeIndices.data(), GL_STATIC_DRAW);
        glDrawElements(GL_LINES, wireframeIndices.size(), GL_UNSIGNED_INT, 0);
    }
};

class Circle : public Shape {
private:
    float radius;
    float center_x;
    float center_y;
    int segment_count;
    float scale_factor = 1.0f; 

public:
    Circle(unsigned int sid, unsigned int vao, float radius, float center_x, float center_y, int segment_count = 32)
        : Shape(sid, vao), radius(radius), center_x(center_x), center_y(center_y), segment_count(segment_count < 3 ? 3 : segment_count) {
        generateVertices();
    }

    void setSegmentCount(int count) {
        segment_count = count < 3 ? 3 : count;
        generateVertices();
    }

    void generateVertices() {
        vertices.clear();
        indices.clear();
        vertices.push_back(center_x);
        vertices.push_back(center_y);
        vertices.push_back(0.0f);

        float angleStep = 2.0f * M_PI / segment_count;
        
        for (int i = 0; i <= segment_count; i++) {
            float angle = i * angleStep;
            float x = center_x + (radius * scale_factor) * std::cos(angle);
            float y = center_y + (radius * scale_factor) * std::sin(angle); 
            
            vertices.push_back(x);
            vertices.push_back(y);
            vertices.push_back(0.0f);
            
            if (i < segment_count) {
                indices.push_back(0); 
                indices.push_back(i + 1);
                indices.push_back(i + 2);
            }
        }
    }

    void draw() override {
        Shape::draw();

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    }

    void draw_wireframe() override {
    Shape::draw_wireframe();

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    std::vector<unsigned int> wireframeIndices;
    for (int i = 1; i <= segment_count; i++) {
        wireframeIndices.push_back(i);
        wireframeIndices.push_back(i + 1);
    }
    wireframeIndices.push_back(segment_count + 1); 
    wireframeIndices.push_back(1);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, wireframeIndices.size() * sizeof(unsigned int), wireframeIndices.data(), GL_STATIC_DRAW);
    glDrawElements(GL_LINES, wireframeIndices.size(), GL_UNSIGNED_INT, 0);
}

    void moveUp() override {
        if(center_y + 0.01f > 0.9){return;}
        center_y += 0.01f;
        generateVertices();  
    }

    void moveDown() override {
        if(center_y - 0.01f < -0.9){return;}
        center_y -= 0.01f; 
        generateVertices();
    }

    void moveLeft() override {
        if(center_x - 0.01f < -0.9){return;}
        center_x -= 0.01f;
        generateVertices();
    }

    void moveRight() override {
        if(center_x + 0.01f > 0.9){return;}
        center_x += 0.01f;
        generateVertices();
    }

    float* getCentre() override {
        float* c = new float[2];
        c[0] = center_x;
        c[1] = center_y;
        return c;
    }

    void scale(float scale_value) override {
        scale_factor *= scale_value;
        generateVertices();
    }
};


