#include "Vector.h"
#include "Matrix.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Init a set of vectors for passed in points
//

class Shape{
    protected:

    float* vertices;
    int vertexCount;
    float col[4];
    bool wireframe = false;
    unsigned int shader_program;
    unsigned int VAO;

    public:

    Shape(unsigned int sid, unsigned int vao) : shader_program(sid), VAO(vao) {

    }

    void setColour(float red, float green, float blue, float alpha){
        this->col[0] = red;
        this->col[1] = green;
        this->col[2] = blue;
        this->col[3] = alpha;
    }

    virtual void draw(){};
};

class Triangle : public Shape{
    private:
    
    public:
    Triangle(unsigned int sid, unsigned int vao, float points[9]) : Shape(sid, vao){
        this->vertexCount = 9;
        this->vertices = new float[9];

        for(int i = 0; i < 9; i++){
            this->vertices[i] = points[i];
        }
    }

    void draw(){
        glUseProgram(shader_program);
        glBufferData(GL_ARRAY_BUFFER, vertexCount * sizeof(float), this->vertices, GL_STATIC_DRAW);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3); //use line loop to get a non filled in triangle
    }

};

class Square : public Shape{
    private:

    public:
    Square(unsigned int sid, unsigned int vao, float points[6]) : Shape(sid, vao){
        this->vertexCount = 12;
        this->vertices = new float[12];
        //calulate other 2 points based off location of two provided points
    }
};

class Rectangle : public Shape{
    private:

    public:
    Rectangle(unsigned int sid, unsigned int vao, float points[12]) : Shape(sid, vao){
        this->vertexCount = 12;
        this->vertices = new float[12];
    }

};

class Circle : public Shape{
    private:
    int polygon_count; //default
    float radius;


    public:
    Circle(unsigned int sid, unsigned int vao, float radius, float centre_x, float centre_y, int poly_count = 10) : Shape(sid, vao){

        this->polygon_count = poly_count;
        this->vertices = new float[polygon_count];

    }
 

};