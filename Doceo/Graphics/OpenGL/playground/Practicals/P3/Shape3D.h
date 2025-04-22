#ifndef SHAPES3D_H
#define SHAPES3D_H

#include "Vector.h"
#include "Matrix.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <vector>
#include "Shape2D.h"

class Shape3D : public Shape {
protected:
    Vector<3> center; // Center of the 3D shape

public:
    Shape3D(unsigned int sid, unsigned int vao) : Shape(sid, vao) {
        center = Vector<3>(new double[3]{0, 0, 0});
    }

    Shape3D(unsigned int sid, unsigned int vao, unsigned int ebo) : Shape(sid, vao, ebo) {
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

    void applyTransformation(Matrix<4,4> transform) {
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

class Cube: public Shape3D{

    private:
    std::vector<Rectangle> faces;
    Vector<3> col;
    int numShapes = 6;
    int numVertices = 72; //12*6

    public:
    Cube(Vector<3> center, double height, double width, double length, Vector<3> color, unsigned int sid, unsigned int vao) : Shape3D(sid, vao) {
    //new double[3]{0, height / 2, 0};
    //Vector<3> topPlane = center + Vector<3>(0, height / 2, 0);

    Vector<3> meow(new double[3]{0, 0, 0});
    col = color;

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
        nearLeftBottom[0], nearLeftBottom[1], nearLeftBottom[2]
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

    

    Rectangle front(sid, vao, front_vertics);
    Rectangle back(sid, vao, back_vertics);
    Rectangle left(sid, vao, left_vertics);
    Rectangle right(sid, vao, right_vertics);
    Rectangle bottom(sid, vao, bottom_vertics);
    Rectangle top(sid, vao, top_vertics);

    faces.push_back(front);
    faces.push_back(back);
    faces.push_back(left);
    faces.push_back(right);
    faces.push_back(bottom);
    faces.push_back(top);

    setFaceColors(col);

    for(int i = 0; i < front_vertics.getN(); i++){
        vertices.push_back(front_vertics[i]);
    }

    for(int i = 0; i < back_vertics.getN(); i++){
        vertices.push_back(back_vertics[i]);
    }
    for(int i = 0; i < left_vertics.getN(); i++){
        vertices.push_back(left_vertics[i]);
    }

    for(int i = 0; i < right_vertics.getN(); i++){
        vertices.push_back(right_vertics[i]);
    }

    for(int i = 0; i < bottom_vertics.getN(); i++){
        vertices.push_back(bottom_vertics[i]);
    }

    for(int i = 0; i < top_vertics.getN(); i++){
        vertices.push_back(top_vertics[i]);
    }

    }

    void setFaceColors(Vector<3> color){
        float differ = 0;
        for(Rectangle rec : faces){
            rec.setColor((float) color[0] + differ, (float) color[1], (float) color[2]);
            differ += 0.1;
        }
    }

    void draw() override{
    Shape::draw();

    for(Rectangle rec : faces){
        rec.draw();
    }
    }

    void updateFaces() {
        faces.clear();
        
        // Create new faces with current vertices
        // Rectangle front(sid, VAO, faces[0].);
        // Rectangle back(sid, VAO, faces[1]);
        // Rectangle left(sid, VAO, faces[2]);
        // Rectangle right(sid, VAO, faces[3]);
        // Rectangle bottom(sid, VAO, faces[4]);
        // Rectangle top(sid, VAO, faces[5]);

        // faces.push_back(front);
        // faces.push_back(back);
        // faces.push_back(left);
        // faces.push_back(right);
        // faces.push_back(bottom);
        // faces.push_back(top);
    }
};

#endif