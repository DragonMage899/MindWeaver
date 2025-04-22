#ifndef SHAPES2D_H
#define SHAPES2D_H

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <vector>

using namespace glm;
using namespace std;

namespace Shapes2D
{
    mat3 MVPMatrixCreator(mat3 M= mat3(1.0f), mat3 V = mat3(1.0f), mat3 P= mat3(1.0f));
    vector<vec2> applyMatrix(const vector<vec2>& vertices, const mat3& MVP);
    GLfloat* toGLfloat(const vector<vec2>& vertices);
    GLfloat* toGLfloat(const vector<vec3>& colours);

    class Shape
    {
    protected:
        vector<vec2> vertices;
        vector<vec3> colors;
        vector<Shape*> shapes;

    public:
        Shape();
        virtual ~Shape();

        virtual int numPoints() const;
        virtual int numVertices() const;
        virtual int numColors() const;

        virtual vector<vec2> getVertices() const;
        virtual vector<vec3> getColours() const;
        virtual void setColour(vec3 = vec3(1.0, 0.0, 0.0));
        virtual void setColour(vector<vec3>);
    };

    class Triangle : public Shape
    {
        public:
            Triangle(vec2 = vec2(-0.8, 0.0), vec2 = vec2(0.0, 0.8), vec2 = vec2(0.8f, 0.0), vec3 = vec3(1.0, 0.0, 0.0));
            int numVertices() const;
            int numColors() const;
            int numPoints() const;
    };

    class Square: public Shape
    {
        public:
            Square(vec2 BL = vec2(-0.5, -0.5), vec2 TL = vec2(-0.5, 0.5), vec2 TR = vec2(0.5, 0.5), vec2 BR = vec2(0.5, -0.5), vec3 = vec3(1.0, 0.0, 0.0));
    };

    class House: public Shape{
        public:
            House();
    };

} // namespace Shapes2D

#endif /*SHAPES2D_H*/