#include "Vector.h"
#include "Matrix.h"
#include <iostream>
#include <map>
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
        
        GLint colorLoc = glGetUniformLocation(shader_program, "shapeColor");
        if (colorLoc != -1) {
            glUniform4f(colorLoc, color[0], color[1], color[2], color[3]);
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

class Dim2Shapes : public Shape{

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
    private:
    Vector<12> pnt;
    public:
    

    Rectangle(unsigned int sid, unsigned int vao, float points[12]) : Shape(sid, vao) {
        vertices = {
            points[0], points[1], 0.0f,  
            points[3], points[4], 0.0f,  
            points[6], points[7], 0.0f,  
            points[9], points[10], 0.0f  
        };

        indices = {0, 1, 2, 1, 3, 2 };
    }

    Rectangle(unsigned int sid, unsigned int vao, Vector<12> points) : Shape(sid, vao) {
        vertices = {
            (float) points[0], (float) points[1], (float) points[2], //ul
            (float) points[3], (float) points[4], (float) points[5], //ur
            (float) points[6], (float) points[7], (float) points[8], //ll
            (float) points[9], (float) points[10], (float) points[11] //lr
        };

        indices = {0, 1, 2, 2, 3, 0 };
        pnt = points;
    }

    void updatePoints(Vector<12> points){
        vertices = {
            (float) points[0], (float) points[1], (float) points[2], //ul
            (float) points[3], (float) points[4], (float) points[5], //ur
            (float) points[6], (float) points[7], (float) points[8], //ll
            (float) points[9], (float) points[10], (float) points[11] //lr
        };

        indices = {0, 1, 2, 2, 3, 0 };
        pnt = points;
    }

void draw() override {
    Shape::draw(); 

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    std::vector<unsigned int> rectIndices = {0, 1, 2, 2, 3, 0};
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, rectIndices.size() * sizeof(unsigned int), 
                rectIndices.data(), GL_STATIC_DRAW);
    glDrawElements(GL_TRIANGLES, rectIndices.size(), GL_UNSIGNED_INT, 0);
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


//3D
//===========================================================================
class Dim3Shapes : public Shape {
protected:
    Vector<3> center; // Center of the 3D shape

public:
    Dim3Shapes(unsigned int sid, unsigned int vao) : Shape(sid, vao) {
        center = Vector<3>(new double[3]{0, 0, 0});
    }

    void rotate(float angle, char axis){
        float rad = angle * M_PI / 180.0f;
        float cosA = cos(rad);
        float sinA = sin(rad);
        
        // Create appropriate rotation matrix based on axis
        Matrix<4,4> rot_mat;
        switch(toupper(axis)) {
            case 'X':
                rot_mat = getXRotationMatrix(cosA, sinA);
                break;
            case 'Y':
                rot_mat = getYRotationMatrix(cosA, sinA);
                break;
            case 'Z':
                rot_mat = getZRotationMatrix(cosA, sinA);
                break;
            default:
                return; 
        }
        
        applyTransformation(rot_mat);
    }

    void rotateAroundAxis(float angle, Vector<3> axis){
        Vector<3> u = axis.unitVector();
        
        float rad = angle * M_PI / 180.0f;
        float cosA = cos(rad);
        float sinA = sin(rad);
        
        Matrix<4,4> rot_mat = getArbitraryRotationMatrix(u, cosA, sinA);
        
        applyTransformation(rot_mat);
    }

protected:
    Matrix<4,4> getXRotationMatrix(float cosA, float sinA) {
        double** mat = new double*[4];
        mat[0] = new double[4]{1, 0,    0,     0};
        mat[1] = new double[4]{0, cosA, -sinA, 0};
        mat[2] = new double[4]{0, sinA, cosA,  0};
        mat[3] = new double[4]{0, 0,    0,     1};
        return Matrix<4,4>(mat);
    }

    Matrix<4,4> getYRotationMatrix(float cosA, float sinA) {
        double** mat = new double*[4];
        mat[0] = new double[4]{cosA,  0, sinA, 0};
        mat[1] = new double[4]{0,     1, 0,    0};
        mat[2] = new double[4]{-sinA, 0, cosA, 0};
        mat[3] = new double[4]{0,     0, 0,    1};
        return Matrix<4,4>(mat);
    }

    Matrix<4,4> getZRotationMatrix(float cosA, float sinA) {
        double** mat = new double*[4];
        mat[0] = new double[4]{cosA, -sinA, 0, 0};
        mat[1] = new double[4]{sinA, cosA,  0, 0};
        mat[2] = new double[4]{0,    0,     1, 0};
        mat[3] = new double[4]{0,    0,     0, 1};
        return Matrix<4,4>(mat);
    }

    Matrix<4,4> getArbitraryRotationMatrix(Vector<3> u, float cosA, float sinA) {
        double ux = u[0], uy = u[1], uz = u[2];
        
        double c1 = 1 - cosA;
        
        double** mat = new double*[4];
        mat[0] = new double[4]{
            cosA + ux*ux*c1,
            ux*uy*c1 - uz*sinA,
            ux*uz*c1 + uy*sinA,
            0
        };
        mat[1] = new double[4]{
            uy*ux*c1 + uz*sinA,
            cosA + uy*uy*c1,
            uy*uz*c1 - ux*sinA,
            0
        };
        mat[2] = new double[4]{
            uz*ux*c1 - uy*sinA,
            uz*uy*c1 + ux*sinA,
            cosA + uz*uz*c1,
            0
        };
        mat[3] = new double[4]{0, 0, 0, 1};
        
        return Matrix<4,4>(mat);
    }

    virtual void applyTransformation(Matrix<4,4> transform) {
        // Create translation matrices to move to origin and back
        double** transToOrigin = new double*[4];
        transToOrigin[0] = new double[4]{1, 0, 0, -center[0]};
        transToOrigin[1] = new double[4]{0, 1, 0, -center[1]};
        transToOrigin[2] = new double[4]{0, 0, 1, -center[2]};
        transToOrigin[3] = new double[4]{0, 0, 0, 1};
        Matrix<4,4> T1(transToOrigin);
        
        double** transBack = new double*[4];
        transBack[0] = new double[4]{1, 0, 0, center[0]};
        transBack[1] = new double[4]{0, 1, 0, center[1]};
        transBack[2] = new double[4]{0, 0, 1, center[2]};
        transBack[3] = new double[4]{0, 0, 0, 1};
        Matrix<4,4> T2(transBack);
        
        //M = T2 * R * T1
        Matrix<4,4> M = T2 * transform * T1;
        
        // Apply transformation to all vertices
        for (size_t i = 0; i < vertices.size(); i += 3) {
            std::cout << "Before: " << std::endl;
            std::cout << i << ". " << vertices[i]<< std::endl;
            std::cout << i + 1 << ". " << vertices[i + 1]<< std::endl;
            std::cout << i + 2 << ". " << vertices[i + 2]<< std::endl;
            // Create homogeneous coordinate vector
            double** vert = new double*[4];
            vert[0] = new double[1]{vertices[i]};
            vert[1] = new double[1]{vertices[i+1]};
            vert[2] = new double[1]{vertices[i+2]};
            vert[3] = new double[1]{1};
            Matrix<4,1> vertex(vert);
            
            // Transform the vertex
            Matrix<4,1> transformed = M * vertex;
            
            // Update the vertex coordinates
            vertices[i]   = transformed[0][0];
            vertices[i+1] = transformed[1][0];
            vertices[i+2] = transformed[2][0];

            std::cout << "After: " << std::endl;
            std::cout << i << ". " << vertices[i]<< std::endl;
            std::cout << i + 1 << ". " << vertices[i + 1]<< std::endl;
            std::cout << i + 2 << ". " << vertices[i + 2]<< std::endl;
        }
    }

    float* getCentre() override {
        float* c = new float[3];
        c[0] = center[0];
        c[1] = center[1];
        c[2] = center[2];
        return c;
    }
};

class Cube: public Dim3Shapes{

    private:
    std::vector<Rectangle> faces;
    std::vector<Vector<12>> originalFaceVertices;
    Vector<3> col;
    Vector<3> center;
    int numShapes = 6;
    int numVertices = 72; //12*6

    public:
    Cube(Vector<3> center, double height, double width, double length, Vector<3> color, unsigned int sid, unsigned int vao) : Dim3Shapes(sid, vao) {
    //new double[3]{0, height / 2, 0};
    //Vector<3> topPlane = center + Vector<3>(0, height / 2, 0);

    Vector<3> meow(new double[3]{0, 0, 0});
    col = color;
    this->center = center;

    Vector<3> topPlane = center + Vector<3>(new double[3]{0, height / 2, 0});
    Vector<3> bottomPlane = center - Vector<3>(new double[3]{0, height / 2, 0});
    Vector<3> leftPlane = center - Vector<3>(new double[3]{width / 2, 0, 0});
    Vector<3> rightPlane = center + Vector<3>(new double[3] {width / 2, 0, 0});
    Vector<3> nearPlane = center - Vector<3>(new double[3] {0, 0, length / 2});
    Vector<3> farPlane = center + Vector<3>(new double[3] {0, 0, length / 2});

    Vector<3> nearLeftTop = nearPlane + leftPlane + topPlane;
    Vector<3> nearRightTop = nearPlane + rightPlane + topPlane;
    Vector<3> nearLeftBottom = nearPlane + leftPlane + bottomPlane;
    Vector<3> nearRightBottom = nearPlane + rightPlane + bottomPlane;

    Vector<3> farLeftTop = farPlane + leftPlane + topPlane;
    Vector<3> farRightTop = farPlane + rightPlane + topPlane;
    Vector<3> farLeftBottom = farPlane + leftPlane + bottomPlane;
    Vector<3> farRightBottom = farPlane + rightPlane + bottomPlane;

    Vector<12> front_vertics(new double[12]{
        nearLeftTop[0], nearLeftTop[1], nearLeftTop[2],
        nearRightTop[0], nearRightTop[1], nearRightTop[2],
        nearLeftBottom[0], nearLeftBottom[1], nearLeftBottom[2],
        nearRightBottom[0], nearRightBottom[1], nearRightBottom[2]
    });

    Vector<12> back_vertics(new double[12]{
        farRightTop[0], farRightTop[1], farRightTop[2],
        farLeftTop[0], farLeftTop[1], farLeftTop[2],
        farRightBottom[0], farRightBottom[1], farRightBottom[2],
        farLeftBottom[0], farLeftBottom[1], farLeftBottom[2]
    });

    Vector<12> left_vertics(new double[12]{
        farLeftTop[0], farLeftTop[1], farLeftTop[2],
        nearLeftTop[0], nearLeftTop[1], nearLeftTop[2],
        farLeftBottom[0], farLeftBottom[1], farLeftBottom[2],
        nearLeftBottom[0], nearLeftBottom[1], nearLeftBottom[2]
    });

    Vector<12> right_vertics(new double[12]{
        nearRightTop[0], nearRightTop[1], nearRightTop[2],
        farRightTop[0], farRightTop[1], farRightTop[2],
        nearRightBottom[0], nearRightBottom[1], nearRightBottom[2],
        farRightBottom[0], farRightBottom[1], farRightBottom[2]
    });

    Vector<12> bottom_vertics(new double[12]{
        nearLeftBottom[0], nearLeftBottom[1], nearLeftBottom[2],
        nearRightBottom[0], nearRightBottom[1], nearRightBottom[2],
        farLeftBottom[0], farLeftBottom[1], farLeftBottom[2],
        farRightBottom[0], farRightBottom[1], farRightBottom[2]
    });

    Vector<12> top_vertics(new double[12]{
        nearLeftTop[0], nearLeftTop[1], nearLeftTop[2],
        nearRightTop[0], nearRightTop[1], nearRightTop[2],
        farLeftTop[0], farLeftTop[1], farLeftTop[2],
        farRightTop[0], farRightTop[1], farRightTop[2]
    });

    indices = {0, 1, 2, 1, 3, 2};

    originalFaceVertices.push_back(front_vertics);
    originalFaceVertices.push_back(back_vertics);
    originalFaceVertices.push_back(left_vertics);
    originalFaceVertices.push_back(right_vertics);
    originalFaceVertices.push_back(bottom_vertics);
    originalFaceVertices.push_back(top_vertics);

    vertices.clear();

    for (const auto& face : originalFaceVertices) {
        for (int i = 0; i < 12; i++) {
            vertices.push_back(face[i]);
        }
    }

    updateFaces();
    setFaceColors(col);



    }

void setFaceColors(Vector<3> color) {
    float differ = 0.0f;
    for(Rectangle& rec : faces) { 
        float r = static_cast<float>(color[0]) + differ;
        float g = static_cast<float>(color[1]) + differ;
        float b = static_cast<float>(color[2]) + differ;
        
        r = std::max(0.0f, std::min(1.0f, r));
        g = std::max(0.0f, std::min(1.0f, g));
        b = std::max(0.0f, std::min(1.0f, b));
        
        rec.setColor(r, g, b);
        differ += 0.1f;
    }
}

void draw() override {
    Shape::draw();
    
    // Draw all faces
    for (Rectangle& rec : faces) {
        rec.draw();
    }
    
    // Draw additional edges that connect top and bottom faces
    // This can be done by directly drawing lines between vertices
    glUseProgram(shader_program);
    
    // Setup color for the edges
    GLint colorLoc = glGetUniformLocation(shader_program, "shapeColor");
    if (colorLoc != -1) {
        glUniform4f(colorLoc, color[0], color[1], color[2], color[3]);
    }
    
    // Create a temporary buffer to hold just the vertices for the missing edges
    std::vector<float> edgeVertices;
    
    // Extract vertices for the four vertical edges connecting top and bottom faces
    // Front left vertical edge
    edgeVertices.push_back(originalFaceVertices[0][0]); // nearLeftTop x
    edgeVertices.push_back(originalFaceVertices[0][1]); // nearLeftTop y
    edgeVertices.push_back(originalFaceVertices[0][2]); // nearLeftTop z
    
    edgeVertices.push_back(originalFaceVertices[0][6]); // nearLeftBottom x
    edgeVertices.push_back(originalFaceVertices[0][7]); // nearLeftBottom y
    edgeVertices.push_back(originalFaceVertices[0][8]); // nearLeftBottom z
    
    // Front right vertical edge
    edgeVertices.push_back(originalFaceVertices[0][3]); // nearRightTop x
    edgeVertices.push_back(originalFaceVertices[0][4]); // nearRightTop y
    edgeVertices.push_back(originalFaceVertices[0][5]); // nearRightTop z
    
    edgeVertices.push_back(originalFaceVertices[0][9]); // nearRightBottom x
    edgeVertices.push_back(originalFaceVertices[0][10]); // nearRightBottom y
    edgeVertices.push_back(originalFaceVertices[0][11]); // nearRightBottom z
    
    // Back left vertical edge
    edgeVertices.push_back(originalFaceVertices[1][3]); // farLeftTop x
    edgeVertices.push_back(originalFaceVertices[1][4]); // farLeftTop y
    edgeVertices.push_back(originalFaceVertices[1][5]); // farLeftTop z
    
    edgeVertices.push_back(originalFaceVertices[1][9]); // farLeftBottom x
    edgeVertices.push_back(originalFaceVertices[1][10]); // farLeftBottom y
    edgeVertices.push_back(originalFaceVertices[1][11]); // farLeftBottom z
    
    // Back right vertical edge
    edgeVertices.push_back(originalFaceVertices[1][0]); // farRightTop x
    edgeVertices.push_back(originalFaceVertices[1][1]); // farRightTop y
    edgeVertices.push_back(originalFaceVertices[1][2]); // farRightTop z
    
    edgeVertices.push_back(originalFaceVertices[1][6]); // farRightBottom x
    edgeVertices.push_back(originalFaceVertices[1][7]); // farRightBottom y
    edgeVertices.push_back(originalFaceVertices[1][8]); // farRightBottom z
    
    // Buffer the edge vertices
    unsigned int edgeVBO;
    glGenBuffers(1, &edgeVBO);
    glBindBuffer(GL_ARRAY_BUFFER, edgeVBO);
    glBufferData(GL_ARRAY_BUFFER, edgeVertices.size() * sizeof(float), edgeVertices.data(), GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    // Draw the vertical edges
    glDrawArrays(GL_LINES, 0, edgeVertices.size() / 3);
    
    // Clean up
    glDeleteBuffers(1, &edgeVBO);
}

    void updateFaces() {
        faces.clear();
        
        // Create new faces with current vertices
        Rectangle front(shader_program, VAO, originalFaceVertices[0]);
        Rectangle back(shader_program, VAO, originalFaceVertices[1]);
        Rectangle left(shader_program, VAO, originalFaceVertices[2]);
        Rectangle right(shader_program, VAO, originalFaceVertices[3]);
        Rectangle bottom(shader_program, VAO, originalFaceVertices[4]);
        Rectangle top(shader_program, VAO, originalFaceVertices[5]);

        faces.push_back(front);
        faces.push_back(back);
        faces.push_back(left);
        faces.push_back(right);
        faces.push_back(bottom);
        faces.push_back(top);
    }

void applyTransformation(Matrix<4,4> transform) override {
        // Apply transformation to original face vertices
        for (auto& faceVertices : originalFaceVertices) {
            for (int i = 0; i < 12; i += 3) {
                // Create homogeneous coordinate vector
                double** vert = new double*[4];
                vert[0] = new double[1]{faceVertices[i]};
                vert[1] = new double[1]{faceVertices[i+1]};
                vert[2] = new double[1]{faceVertices[i+2]};
                vert[3] = new double[1]{1};
                Matrix<4,1> vertex(vert);
                
                // Transform the vertex
                Matrix<4,1> transformed = transform * vertex;
                
                // Update the vertex coordinates
                faceVertices[i] = transformed[0][0];
                faceVertices[i+1] = transformed[1][0];
                faceVertices[i+2] = transformed[2][0];
            }
        }
        
        // Update the faces with transformed vertices
        updateFaces();
        
        // Also update the vertices in Shape class for any other operations
        Dim3Shapes::applyTransformation(transform);
    }

};