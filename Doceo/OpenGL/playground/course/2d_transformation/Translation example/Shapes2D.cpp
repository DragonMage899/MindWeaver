#include "Shapes2D.h"

using namespace Shapes2D;

Shapes2D::Shape::Shape()
{
}

Shape::~Shape()
{
    for (vector<Shape *>::iterator it = shapes.begin(); it != shapes.end(); it++)
    {
        delete (*it);
    }
}

int Shape::numPoints() const
{
    int count = 0;
    for (vector<Shape *>::const_iterator it = shapes.begin(); it != shapes.end(); it++)
    {
        count += (*it)->numPoints();
    }
    return count;
}

int Shape::numVertices() const
{
    int count = 0;
    for (vector<Shape *>::const_iterator it = shapes.begin(); it != shapes.end(); it++)
    {
        count += (*it)->numVertices();
    }
    return count;
}

int Shape::numColors() const
{
    int count = 0;
    for (vector<Shape *>::const_iterator it = shapes.begin(); it != shapes.end(); it++)
    {
        count += (*it)->numColors();
    }
    return count;
}

vector<vec2> Shapes2D::Shape::getVertices() const
{
    if (!vertices.empty())
    {
        return vertices;
    }
    else
    {
        vector<vec2> result;
        for (vector<Shape *>::const_iterator it = shapes.begin(); it != shapes.end(); it++)
        {
            vector<vec2> tempResults = (*it)->getVertices();
            for (vector<vec2>::iterator it2 = tempResults.begin(); it2 != tempResults.end(); it2++)
            {
                result.push_back((*it2));
            }
        }
        return result;
    }
}

vector<vec3> Shapes2D::Shape::getColours() const
{
    if (!colors.empty())
    {
        return colors;
    }
    else
    {
        vector<vec3> result;
        for (vector<Shape *>::const_iterator it = shapes.begin(); it != shapes.end(); it++)
        {
            vector<vec3> tempResults = (*it)->getColours();
            for (vector<vec3>::iterator it2 = tempResults.begin(); it2 != tempResults.end(); it2++)
            {
                result.push_back((*it2));
            }
        }
        return result;
    }
}

void Shapes2D::Shape::setColour(vec3 colour)
{
    if (!colors.empty())
    {
        for (vector<vec3>::iterator it = colors.begin(); it != colors.end(); it++)
        {
            (*it) = (colour);
        }
    }
    else
    {
        for (vector<Shape *>::iterator it = shapes.begin(); it != shapes.end(); it++)
        {
            (*it)->setColour(colour);
        }
    }
}

void Shapes2D::Shape::setColour(vector<vec3> colours)
{
    colors.clear();
    colors = colours;
}

Triangle::Triangle(vec2 point1, vec2 point2, vec2 point3, vec3 color)
{

    vertices.push_back(point1);
    vertices.push_back(point2);
    vertices.push_back(point3);

    colors.push_back(color);
    colors.push_back(color);
    colors.push_back(color);
}

int Triangle::numVertices() const
{
    return 6;
}

int Triangle::numColors() const
{
    return 9;
}

int Triangle::numPoints() const
{
    return 3;
}

mat3 Shapes2D::MVPMatrixCreator(mat3 M, mat3 V, mat3 P)
{
    return (P * (V * M));
}

vector<vec2> Shapes2D::applyMatrix(const vector<vec2> &vertices, const mat3 &MVP)
{
    vector<vec2> worldVertices;

    for (vector<vec2>::const_iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        vec2 p(*it);
        vec3 v(p, 1);
        vec3 vPrime = MVP * v;
        vec2 pPrime = vec2(vPrime[0], vPrime[1]);
        worldVertices.push_back(pPrime);
    }

    return worldVertices;
}

GLfloat *Shapes2D::toGLfloat(const vector<vec2> &vertices)
{
    GLfloat *result = new GLfloat[vertices.size() * 2];
    int i = 0;
    for (vector<vec2>::const_iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        result[i++] = (*it)[0];
        result[i++] = (*it)[1];
    }
    return result;
}

GLfloat *Shapes2D::toGLfloat(const vector<vec3> &colors)
{
    GLfloat *result = new GLfloat[colors.size() * 3];
    int i = 0;
    for (vector<vec3>::const_iterator it = colors.begin(); it != colors.end(); it++)
    {
        result[i++] = (*it)[0];
        result[i++] = (*it)[1];
        result[i++] = (*it)[2];
    }
    return result;
}

Shapes2D::Square::Square(vec2 BL, vec2 TL, vec2 TR, vec2 BR, vec3 color)
{
    shapes.push_back(new Triangle(TR, TL, BL, color));
    shapes.push_back(new Triangle(BR, TR, BL, color));
}

Shapes2D::House::House()
{
    shapes.push_back(new Triangle(vec2(0.5, 0.5), vec2(0, 0.8), vec2(-0.5, 0.5), vec3(0, 1, 0)));
    shapes.push_back(new Square());
}
