#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <vector>
#include <string>
#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include <cstddef> 
#include <algorithm>
#include <iostream>
#include <cmath>

#include "Matrix.h"
#include "Vector.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

struct Vertex {
    float x, y, z;          // Position
    float nx, ny, nz;       // Normal
    float u, v;             // Texture coordinates
};

struct Face {
    unsigned int v1, v2, v3;    // Vertex indices
    unsigned int vt1, vt2, vt3; // Texture coordinate indices
    unsigned int vn1, vn2, vn3; // Normal indices
};

class ObjLoader {
private:
    GLuint shaderProgram;
    GLuint VAO, VBO, EBO;
    GLuint textureID;
    
    std::vector<Vector<3>> positions;
    std::vector<Vector<3>> normals;
    std::vector<Vector<2>> texCoords;
    std::vector<Face> faces;
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    
    Matrix<4, 4> transform;
    Vector<3> center;
    float color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    
    bool hasTexture = false;
    bool wireframe = false;
    
    void calculateCenter();
    void setupBuffers();
    void processVertices();

public:
    ObjLoader(GLuint program);
    ~ObjLoader();
    
    bool loadObject(const std::string& filename);
    bool loadTexture(const std::string& filename);
    
    void draw();
    void setDrawColor(float r, float g, float b, float a = 1.0f);
    
    // Transformation methods
    void translate(double dx, double dy, double dz);
    void rotate(double angleRad, char axis);
    void rotate(double angleRad, char axis, Vector<3> center);
    void scale(double sx, double sy, double sz);
    void resetTransform();
    
    // Utility methods
    void toggleWireframe();
    Vector<3> getCenter() const { return center; }
    void setCenter(Vector<3> newCenter) { center = newCenter; }
};

#endif

ObjLoader::ObjLoader(GLuint program) : shaderProgram(program) {
    transform = IdentityMatrix<4>();
    
    // Generate buffers
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glGenTextures(1, &textureID);
}

ObjLoader::~ObjLoader() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteTextures(1, &textureID);
}

bool ObjLoader::loadObject(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open OBJ file: " << filename << std::endl;
        return false;
    }
    
    // Clear previous data
    positions.clear();
    normals.clear();
    texCoords.clear();
    faces.clear();
    
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;
        
        if (prefix == "v") {
            // Vertex position
            float x, y, z;
            iss >> x >> y >> z;
            positions.push_back(Vector<3>(new double[3]{x, y, z}));
        }
        else if (prefix == "vn") {
            // Vertex normal
            float nx, ny, nz;
            iss >> nx >> ny >> nz;
            normals.push_back(Vector<3>(new double[3]{nx, ny, nz}));
        }
        else if (prefix == "vt") {
            // Texture coordinate
            float u, v;
            iss >> u >> v;
            texCoords.push_back(Vector<2>(new double[2]{u, v}));
        }
        else if (prefix == "f") {
            // Face
            std::string vertex1, vertex2, vertex3;
            iss >> vertex1 >> vertex2 >> vertex3;
            
            Face face;
            
            // Parse vertex1 (format: v/vt/vn)
            std::replace(vertex1.begin(), vertex1.end(), '/', ' ');
            std::istringstream v1(vertex1);
            v1 >> face.v1 >> face.vt1 >> face.vn1;
            
            // Parse vertex2
            std::replace(vertex2.begin(), vertex2.end(), '/', ' ');
            std::istringstream v2(vertex2);
            v2 >> face.v2 >> face.vt2 >> face.vn2;
            
            // Parse vertex3
            std::replace(vertex3.begin(), vertex3.end(), '/', ' ');
            std::istringstream v3(vertex3);
            v3 >> face.v3 >> face.vt3 >> face.vn3;
            
            // Convert from 1-based to 0-based indexing
            face.v1--; face.v2--; face.v3--;
            face.vt1--; face.vt2--; face.vt3--;
            face.vn1--; face.vn2--; face.vn3--;
            
            faces.push_back(face);
        }
    }
    
    file.close();
    
    processVertices();
    calculateCenter();
    setupBuffers();
    
    std::cout << "Loaded OBJ: " << positions.size() << " vertices, " 
              << faces.size() << " faces" << std::endl;
    
    return true;
}

void ObjLoader::processVertices() {
    vertices.clear();
    indices.clear();
    
    // Create vertices from faces
    for (size_t i = 0; i < faces.size(); ++i) {
        const Face& face = faces[i];
        
        // Vertex 1
        Vertex v1;
        if (face.v1 < positions.size()) {
            v1.x = positions[face.v1][0];
            v1.y = positions[face.v1][1];
            v1.z = positions[face.v1][2];
        }
        if (face.vn1 < normals.size()) {
            v1.nx = normals[face.vn1][0];
            v1.ny = normals[face.vn1][1];
            v1.nz = normals[face.vn1][2];
        }
        if (face.vt1 < texCoords.size()) {
            v1.u = texCoords[face.vt1][0];
            v1.v = texCoords[face.vt1][1];
        }
        
        // Vertex 2
        Vertex v2;
        if (face.v2 < positions.size()) {
            v2.x = positions[face.v2][0];
            v2.y = positions[face.v2][1];
            v2.z = positions[face.v2][2];
        }
        if (face.vn2 < normals.size()) {
            v2.nx = normals[face.vn2][0];
            v2.ny = normals[face.vn2][1];
            v2.nz = normals[face.vn2][2];
        }
        if (face.vt2 < texCoords.size()) {
            v2.u = texCoords[face.vt2][0];
            v2.v = texCoords[face.vt2][1];
        }
        
        // Vertex 3
        Vertex v3;
        if (face.v3 < positions.size()) {
            v3.x = positions[face.v3][0];
            v3.y = positions[face.v3][1];
            v3.z = positions[face.v3][2];
        }
        if (face.vn3 < normals.size()) {
            v3.nx = normals[face.vn3][0];
            v3.ny = normals[face.vn3][1];
            v3.nz = normals[face.vn3][2];
        }
        if (face.vt3 < texCoords.size()) {
            v3.u = texCoords[face.vt3][0];
            v3.v = texCoords[face.vt3][1];
        }
        
        vertices.push_back(v1);
        vertices.push_back(v2);
        vertices.push_back(v3);
        
        // Add indices
        unsigned int baseIndex = i * 3;
        indices.push_back(baseIndex);
        indices.push_back(baseIndex + 1);
        indices.push_back(baseIndex + 2);
    }
}

void ObjLoader::calculateCenter() {
    if (positions.empty()) {
        center = Vector<3>(new double[3]{0, 0, 0});
        return;
    }
    
    double sumX = 0, sumY = 0, sumZ = 0;
    for (const auto& pos : positions) {
        sumX += pos[0];
        sumY += pos[1];
        sumZ += pos[2];
    }
    
    center = Vector<3>(new double[3]{
        sumX / positions.size(),
        sumY / positions.size(),
        sumZ / positions.size()
    });
}

void ObjLoader::setupBuffers() {
    glBindVertexArray(VAO);
    
    // Vertex buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), 
                 vertices.data(), GL_STATIC_DRAW);
    
    // Element buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
                 indices.data(), GL_STATIC_DRAW);
    
    // Position attribute (location 0)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);
    
    // Normal attribute (location 1)
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 
                         (void*)offsetof(Vertex, nx));
    glEnableVertexAttribArray(1);
    
    // Texture coordinate attribute (location 2)
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), 
                         (void*)offsetof(Vertex, u));
    glEnableVertexAttribArray(2);
    
    glBindVertexArray(0);
}

bool ObjLoader::loadTexture(const std::string& filename) {
    int width, height, nrChannels;
    unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrChannels, 0);
    
    if (!data) {
        std::cerr << "Failed to load texture: " << filename << std::endl;
        return false;
    }
    
    glBindTexture(GL_TEXTURE_2D, textureID);
    
    GLenum format = GL_RGB;
    if (nrChannels == 1)
        format = GL_RED;
    else if (nrChannels == 3)
        format = GL_RGB;
    else if (nrChannels == 4)
        format = GL_RGBA;
    
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, 
                 GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    
    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    stbi_image_free(data);
    hasTexture = true;
    
    std::cout << "Loaded texture: " << filename << " (" << width << "x" << height << ")" << std::endl;
    
    return true;
}

void ObjLoader::draw() {
    // Apply transformations to vertices
    std::vector<Vertex> transformedVertices = vertices;
    
    for (auto& vertex : transformedVertices) {
        // Apply transformation matrix
        double** vecArr = new double*[4];
        for (int i = 0; i < 4; ++i) {
            vecArr[i] = new double[1];
        }
        
        vecArr[0][0] = vertex.x;
        vecArr[1][0] = vertex.y;
        vecArr[2][0] = vertex.z;
        vecArr[3][0] = 1.0;
        
        Matrix<4, 1> vec4d(vecArr);
        Matrix<4, 1> result = transform * vec4d;
        
        vertex.x = result[0][0];
        vertex.y = result[1][0];
        vertex.z = result[2][0];
        
        // Clean up
        for (int i = 0; i < 4; ++i) {
            delete[] vecArr[i];
        }
        delete[] vecArr;
    }
    
    // Update buffer with transformed vertices
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, transformedVertices.size() * sizeof(Vertex), 
                    transformedVertices.data());
    
    // Use shader program
    glUseProgram(shaderProgram);
    
    // Set color uniform
    GLint colorLoc = glGetUniformLocation(shaderProgram, "color");
    if (colorLoc != -1) {
        glUniform4f(colorLoc, color[0], color[1], color[2], color[3]);
    }
    
    // Bind texture if available
    if (hasTexture) {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textureID);
        GLint texLoc = glGetUniformLocation(shaderProgram, "ourTexture");
        if (texLoc != -1) {
            glUniform1i(texLoc, 0);
        }
    }
    
    // Set wireframe mode
    if (wireframe) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    
    // Draw
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    
    // Reset transform for next frame
    resetTransform();
}

void ObjLoader::setDrawColor(float r, float g, float b, float a) {
    color[0] = r;
    color[1] = g;
    color[2] = b;
    color[3] = a;
}

void ObjLoader::translate(double dx, double dy, double dz) {
    double** t = new double*[4] {
        new double[4]{1, 0, 0, dx},
        new double[4]{0, 1, 0, dy},
        new double[4]{0, 0, 1, dz},
        new double[4]{0, 0, 0, 1}
    };
    Matrix<4, 4> T(t);
    transform = T * transform;
}

void ObjLoader::rotate(double angleRad, char axis) {
    rotate(angleRad, axis, center);
}

void ObjLoader::rotate(double angleRad, char axis, Vector<3> rotCenter) {
    // Translate to origin
    double** t1 = new double*[4] {
        new double[4]{1, 0, 0, -rotCenter[0]},
        new double[4]{0, 1, 0, -rotCenter[1]},
        new double[4]{0, 0, 1, -rotCenter[2]},
        new double[4]{0, 0, 0, 1}
    };
    Matrix<4, 4> T1(t1);
    
    // Rotation matrix
    double c = cos(angleRad);
    double s = sin(angleRad);
    Matrix<4, 4> R;
    
    if (axis == 'X' || axis == 'x') {
        double** rx = new double*[4] {
            new double[4]{1, 0, 0, 0},
            new double[4]{0, c, -s, 0},
            new double[4]{0, s, c, 0},
            new double[4]{0, 0, 0, 1}
        };
        R = Matrix<4, 4>(rx);
    } else if (axis == 'Y' || axis == 'y') {
        double** ry = new double*[4] {
            new double[4]{c, 0, s, 0},
            new double[4]{0, 1, 0, 0},
            new double[4]{-s, 0, c, 0},
            new double[4]{0, 0, 0, 1}
        };
        R = Matrix<4, 4>(ry);
    } else if (axis == 'Z' || axis == 'z') {
        double** rz = new double*[4] {
            new double[4]{c, -s, 0, 0},
            new double[4]{s, c, 0, 0},
            new double[4]{0, 0, 1, 0},
            new double[4]{0, 0, 0, 1}
        };
        R = Matrix<4, 4>(rz);
    }
    
    // Translate back
    double** t2 = new double*[4] {
        new double[4]{1, 0, 0, rotCenter[0]},
        new double[4]{0, 1, 0, rotCenter[1]},
        new double[4]{0, 0, 1, rotCenter[2]},
        new double[4]{0, 0, 0, 1}
    };
    Matrix<4, 4> T2(t2);
    
    transform = T2 * R * T1 * transform;
}

void ObjLoader::scale(double sx, double sy, double sz) {
    // Scale around center
    Vector<3> center = getCenter();
    
    // Translate to origin
    translate(-center[0], -center[1], -center[2]);
    
    // Apply scale
    double** s = new double*[4] {
        new double[4]{sx, 0, 0, 0},
        new double[4]{0, sy, 0, 0},
        new double[4]{0, 0, sz, 0},
        new double[4]{0, 0, 0, 1}
    };
    Matrix<4, 4> S(s);
    transform = S * transform;
    
    // Translate back
    translate(center[0], center[1], center[2]);
}

void ObjLoader::resetTransform() {
    transform = IdentityMatrix<4>();
}

void ObjLoader::toggleWireframe() {
    wireframe = !wireframe;
}