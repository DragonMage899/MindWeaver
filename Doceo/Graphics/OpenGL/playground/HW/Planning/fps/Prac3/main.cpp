#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <chrono>
#include <cmath>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "shader.hpp"

using namespace glm;
using namespace std;

// Student Number should be placed here
const char* WINDOW_TITLE = "u22497618"; 

// Define global variables for transformations
float xRotation = 0.0f;
float yRotation = 0.0f;
float zRotation = 0.0f;
float xPosition = 0.0f;
float yPosition = 0.0f;
float zPosition = 0.0f;
float modelScale = 1.0f;  // New scale variable for zooming
float propellerSpeed = 0.0f;
float propellerAngle = 0.0f;
bool wireframeMode = false;
bool keyPressed = false;
double lastKeyPressTime = 0.0;
const double KEY_PRESS_DELAY = 0.2; 

const float PI = 3.14159265359f;

// Matrix and Vector Implementations
struct Vec3 {
    float x, y, z;
    
    Vec3() : x(0), y(0), z(0) {}
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
    
    Vec3 operator+(const Vec3& v) const {
        return Vec3(x + v.x, y + v.y, z + v.z);
    }
    
    Vec3 operator-(const Vec3& v) const {
        return Vec3(x - v.x, y - v.y, z - v.z);
    }
    
    Vec3 operator*(float s) const {
        return Vec3(x * s, y * s, z * s);
    }
};

struct Vec4 {
    float x, y, z, w;
    
    Vec4() : x(0), y(0), z(0), w(1) {}
    Vec4(float x, float y, float z, float w = 1.0f) : x(x), y(y), z(z), w(w) {}
    Vec4(const Vec3& v, float w = 1.0f) : x(v.x), y(v.y), z(v.z), w(w) {}
    
    Vec4 operator+(const Vec4& v) const {
        return Vec4(x + v.x, y + v.y, z + v.z, w + v.w);
    }
    
    Vec4 operator-(const Vec4& v) const {
        return Vec4(x - v.x, y - v.y, z - v.z, w - v.w);
    }
    
    Vec4 operator*(float s) const {
        return Vec4(x * s, y * s, z * s, w * s);
    }
    
    Vec3 toVec3() const {
        if (w != 0) {
            return Vec3(x / w, y / w, z / w);
        }
        return Vec3(x, y, z);
    }
};

struct Mat4 {
    float m[4][4];
    
    Mat4() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                m[i][j] = (i == j) ? 1.0f : 0.0f;  // Identity matrix
            }
        }
    }
    
    static Mat4 translation(float x, float y, float z) {
        Mat4 result;
        result.m[0][3] = x;
        result.m[1][3] = y;
        result.m[2][3] = z;
        return result;
    }
    
    static Mat4 rotationX(float angle) {
        Mat4 result;
        float c = cos(angle);
        float s = sin(angle);
        result.m[1][1] = c;
        result.m[1][2] = -s;
        result.m[2][1] = s;
        result.m[2][2] = c;
        return result;
    }
    
    static Mat4 rotationY(float angle) {
        Mat4 result;
        float c = cos(angle);
        float s = sin(angle);
        result.m[0][0] = c;
        result.m[0][2] = s;
        result.m[2][0] = -s;
        result.m[2][2] = c;
        return result;
    }
    
    static Mat4 rotationZ(float angle) {
        Mat4 result;
        float c = cos(angle);
        float s = sin(angle);
        result.m[0][0] = c;
        result.m[0][1] = -s;
        result.m[1][0] = s;
        result.m[1][1] = c;
        return result;
    }
    
    static Mat4 scale(float x, float y, float z) {
        Mat4 result;
        result.m[0][0] = x;
        result.m[1][1] = y;
        result.m[2][2] = z;
        return result;
    }
    
    Mat4 operator*(const Mat4& other) const {
        Mat4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result.m[i][j] = 0;
                for (int k = 0; k < 4; k++) {
                    result.m[i][j] += m[i][k] * other.m[k][j];
                }
            }
        }
        return result;
    }
    
    Vec4 operator*(const Vec4& v) const {
        Vec4 result;
        result.x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3] * v.w;
        result.y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3] * v.w;
        result.z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3] * v.w;
        result.w = m[3][0] * v.x + m[3][1] * v.y + m[3][2] * v.z + m[3][3] * v.w;
        return result;
    }
};

// Structure to hold vertex data
struct Vertex {
    Vec3 position;
    Vec3 color;
    
    Vertex(const Vec3& pos, const Vec3& col) : position(pos), color(col) {}
};

// Structure to hold shape data
struct Shape {
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    GLuint VAO, VBO, EBO;
    
    void setup() {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
        
        glBindVertexArray(VAO);
        
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
        
        // Position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
        glEnableVertexAttribArray(0);
        
        // Color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
        glEnableVertexAttribArray(1);
        
        glBindVertexArray(0);
    }
    
    void draw(GLuint shaderProgram, const Mat4& modelMatrix, bool wireframe) {
        glUseProgram(shaderProgram);
        
        // Convert model matrix to GLM format for shader
        float modelMatrixData[16];
        int idx = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                modelMatrixData[idx++] = modelMatrix.m[j][i]; // Note: transpose for column-major
            }
        }
        
        // Set model matrix in shader
        GLint modelLoc = glGetUniformLocation(shaderProgram, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, modelMatrixData);
        
        glBindVertexArray(VAO);
        
        if (wireframe) {
            // Set polygon mode to wireframe
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            // Draw using the same indices but in wireframe mode
            glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
            // Set polygon mode back to fill
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        } else {
            // Draw filled triangles
            glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        }
        
        glBindVertexArray(0);
    }
    
    void cleanup() {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
    }
};

// Define colors
const Vec3 FUSELAGE_COLOR(0.8f, 0.8f, 0.8f);    
const Vec3 WING_COLOR(1.9f, 0.8f, 0.8f);       
const Vec3 WINDOW_COLOR(0.0f, 0.5f, 0.9f);      
const Vec3 TAIL_COLOR(1.13f, 0.86f, 0.37f);  
const Vec3 TAIL_COLOR2(0.1f, 0.1f, 0.3f);     
const Vec3 CONTROL_COLOR(0.7f, 0.0f, 0.0f);     
const Vec3 PROPELLER_COLOR(0.3f, 0.3f, 0.3f);   
const Vec3 YELLOW(0.58f, 0.57f, 0.16f);
const Vec3 WHEEL_COLOR(0.0f, 0.0f, 0.0f);       
const Vec3 STRUT_COLOR(0.5f, 0.5f, 0.5f);      
const Vec3 ENGINE_COLOR(0.4f, 0.4f, 0.4f);      

// Function to create a cuboid shape
Shape createCuboid(const Vec3& center, float width, float height, float depth, const Vec3& color) {
    Shape cuboid;
    
    // Half-dimensions
    float hw = width / 2.0f;
    float hh = height / 2.0f;
    float hd = depth / 2.0f;
    
    // Vertices
    cuboid.vertices = {
        // Front face
        Vertex(Vec3(center.x - hw, center.y - hh, center.z + hd), color),
        Vertex(Vec3(center.x + hw, center.y - hh, center.z + hd), color),
        Vertex(Vec3(center.x + hw, center.y + hh, center.z + hd), color),
        Vertex(Vec3(center.x - hw, center.y + hh, center.z + hd), color),
        
        // Back face
        Vertex(Vec3(center.x - hw, center.y - hh, center.z - hd), color),
        Vertex(Vec3(center.x + hw, center.y - hh, center.z - hd), color),
        Vertex(Vec3(center.x + hw, center.y + hh, center.z - hd), color),
        Vertex(Vec3(center.x - hw, center.y + hh, center.z - hd), color)
    };
    
    // Indices
    cuboid.indices = {
        // Front face
        0, 1, 2,
        0, 2, 3,
        
        // Back face
        4, 6, 5,
        4, 7, 6,
        
        // Left face
        4, 0, 3,
        4, 3, 7,
        
        // Right face
        1, 5, 6,
        1, 6, 2,
        
        // Top face
        3, 2, 6,
        3, 6, 7,
        
        // Bottom face
        0, 4, 5,
        0, 5, 1
    };
    
    cuboid.setup();
    return cuboid;
}

// Function to create a triangular prism
Shape createTriangularPrism(const Vec3& center, float width, float height, float depth, const Vec3& color) {
    Shape prism;
    
    // Half-dimensions
    float hw = width / 2.0f;
    float hh = height / 2.0f;
    float hd = depth / 2.0f;
    
    // Vertices
    prism.vertices = {
        // Front face (triangle)
        Vertex(Vec3(center.x - hw, center.y - hh, center.z + hd), color),
        Vertex(Vec3(center.x + hw, center.y - hh, center.z + hd), color),
        Vertex(Vec3(center.x, center.y + hh, center.z + hd), color),
        
        // Back face (triangle)
        Vertex(Vec3(center.x - hw, center.y - hh, center.z - hd), color),
        Vertex(Vec3(center.x + hw, center.y - hh, center.z - hd), color),
        Vertex(Vec3(center.x, center.y + hh, center.z - hd), color)
    };
    
    // Indices
    prism.indices = {
        // Front face
        0, 1, 2,
        
        // Back face
        3, 5, 4,
        
        // Bottom face
        0, 3, 4,
        0, 4, 1,
        
        // Left face
        0, 2, 5,
        0, 5, 3,
        
        // Right face
        1, 4, 5,
        1, 5, 2
    };
    
    prism.setup();
    return prism;
}

// Function to create a cylinder
// Function to create a cylinder with orientation support
Shape createCylinder(const Vec3& center, float radius, float height, int segments, const Vec3& color, char axis = 'Y') {
    Shape cylinder;
    
    // Half-height
    float hh = height / 2.0f;
    
    // Top and bottom center vertices depend on the orientation axis
    Vec3 top, bottom;
    if (axis == 'X') {
        // Along X-axis
        top = Vec3(center.x + hh, center.y, center.z);
        bottom = Vec3(center.x - hh, center.y, center.z);
    } else if (axis == 'Z') {
        // Along Z-axis
        top = Vec3(center.x, center.y, center.z + hh);
        bottom = Vec3(center.x, center.y, center.z - hh);
    } else {
        // Default - Along Y-axis
        top = Vec3(center.x, center.y + hh, center.z);
        bottom = Vec3(center.x, center.y - hh, center.z);
    }
    
    cylinder.vertices.push_back(Vertex(top, color));
    cylinder.vertices.push_back(Vertex(bottom, color));
    
    // Create vertices for the circular edges
    for (int i = 0; i < segments; ++i) {
        float angle = 2.0f * PI * i / segments;
        
        // Calculate position based on orientation
        Vec3 topRim, bottomRim;
        if (axis == 'X') {
            // Along X-axis, circle is in YZ plane
            float y = center.y + radius * cos(angle);
            float z = center.z + radius * sin(angle);
            topRim = Vec3(center.x + hh, y, z);
            bottomRim = Vec3(center.x - hh, y, z);
        } else if (axis == 'Z') {
            // Along Z-axis, circle is in XY plane
            float x = center.x + radius * cos(angle);
            float y = center.y + radius * sin(angle);
            topRim = Vec3(x, y, center.z + hh);
            bottomRim = Vec3(x, y, center.z - hh);
        } else {
            // Default - Along Y-axis, circle is in XZ plane
            float x = center.x + radius * cos(angle);
            float z = center.z + radius * sin(angle);
            topRim = Vec3(x, center.y + hh, z);
            bottomRim = Vec3(x, center.y - hh, z);
        }
        
        // Top rim
        cylinder.vertices.push_back(Vertex(topRim, color));
        // Bottom rim
        cylinder.vertices.push_back(Vertex(bottomRim, color));
    }
    
    // Top face
    for (int i = 0; i < segments; ++i) {
        cylinder.indices.push_back(0); // Top center
        cylinder.indices.push_back(2 + (i * 2));
        cylinder.indices.push_back(2 + (((i + 1) % segments) * 2));
    }
    
    // Bottom face
    for (int i = 0; i < segments; ++i) {
        cylinder.indices.push_back(1); // Bottom center
        cylinder.indices.push_back(3 + (((i + 1) % segments) * 2));
        cylinder.indices.push_back(3 + (i * 2));
    }
    
    // Side faces
    for (int i = 0; i < segments; ++i) {
        int current = 2 + (i * 2);
        int next = 2 + (((i + 1) % segments) * 2);
        
        // First triangle
        cylinder.indices.push_back(current);
        cylinder.indices.push_back(current + 1);
        cylinder.indices.push_back(next);
        
        // Second triangle
        cylinder.indices.push_back(next);
        cylinder.indices.push_back(current + 1);
        cylinder.indices.push_back(next + 1);
    }
    
    cylinder.setup();
    return cylinder;
}

// Function to create a cone
// Function to create a cone with orientation support
Shape createCone(const Vec3& center, float radius, float height, int segments, const Vec3& color, char axis = 'Y') {
    Shape cone;
    
    // Tip and base center vertices depend on the orientation axis
    Vec3 tip, baseCenter;
    if (axis == 'X') {
        // Along X-axis
        tip = Vec3(center.x + height / 2.0f, center.y, center.z);
        baseCenter = Vec3(center.x - height / 2.0f, center.y, center.z);
    } else if (axis == 'Z') {
        // Along Z-axis
        tip = Vec3(center.x, center.y, center.z + height / 2.0f);
        baseCenter = Vec3(center.x, center.y, center.z - height / 2.0f);
    } else {
        // Default - Along Y-axis
        tip = Vec3(center.x, center.y + height / 2.0f, center.z);
        baseCenter = Vec3(center.x, center.y - height / 2.0f, center.z);
    }
    
    // Tip and base center vertices
    cone.vertices.push_back(Vertex(tip, color)); // Tip
    cone.vertices.push_back(Vertex(baseCenter, color)); // Base center
    
    // Create vertices for the circular base
    for (int i = 0; i < segments; ++i) {
        float angle = 2.0f * PI * i / segments;
        
        // Calculate rim position based on orientation
        Vec3 baseRim;
        if (axis == 'X') {
            // Along X-axis, circle is in YZ plane
            float y = center.y + radius * cos(angle);
            float z = center.z + radius * sin(angle);
            baseRim = Vec3(center.x - height / 2.0f, y, z);
        } else if (axis == 'Z') {
            // Along Z-axis, circle is in XY plane
            float x = center.x + radius * cos(angle);
            float y = center.y + radius * sin(angle);
            baseRim = Vec3(x, y, center.z - height / 2.0f);
        } else {
            // Default - Along Y-axis, circle is in XZ plane
            float x = center.x + radius * cos(angle);
            float z = center.z + radius * sin(angle);
            baseRim = Vec3(x, center.y - height / 2.0f, z);
        }
        
        // Base rim
        cone.vertices.push_back(Vertex(baseRim, color));
    }
    
    // Triangles from tip to base
    for (int i = 0; i < segments; ++i) {
        cone.indices.push_back(0); // Tip
        cone.indices.push_back(2 + i);
        cone.indices.push_back(2 + ((i + 1) % segments));
    }
    
    // Base face
    for (int i = 0; i < segments - 2; ++i) {
        cone.indices.push_back(1); // Base center
        cone.indices.push_back(2 + i + 1);
        cone.indices.push_back(2 + i);
    }
    
    cone.setup();
    return cone;
}

// Function to create a rounded fuselage using cylinders
Shape createRoundedFuselage(const Vec3& center, float radius, float length, int segments, const Vec3& color) {
    Shape fuselage;
    
    // Half-length
    float hl = length / 2.0f;
    
    // We'll create a cylinder and then add tapering at the front and back
    
    // Create vertices for the main body cylinder
    for (int i = 0; i < segments; ++i) {
        float angle = 2.0f * PI * i / segments;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        
        // Front ring
        fuselage.vertices.push_back(Vertex(Vec3(center.x + x, center.y + y, center.z + hl), color));
        // Back ring
        fuselage.vertices.push_back(Vertex(Vec3(center.x + x, center.y + y, center.z - hl), color));
    }
    
    // Create nose cone (smaller radius at front tip)
    fuselage.vertices.push_back(Vertex(Vec3(center.x, center.y, center.z + hl + radius * 0.8f), color)); // Front tip
    
    // Create rear taper
    fuselage.vertices.push_back(Vertex(Vec3(center.x, center.y, center.z - hl - radius * 0.5f), color)); // Rear tip
    
    // Side faces for main cylinder
    for (int i = 0; i < segments; ++i) {
        int current = i * 2;
        int next = ((i + 1) % segments) * 2;
        
        // First triangle
        fuselage.indices.push_back(current);
        fuselage.indices.push_back(current + 1);
        fuselage.indices.push_back(next);
        
        // Second triangle
        fuselage.indices.push_back(next);
        fuselage.indices.push_back(current + 1);
        fuselage.indices.push_back(next + 1);
    }
    
    // Front cone triangles
    int frontTip = segments * 2;
    for (int i = 0; i < segments; ++i) {
        int current = i * 2;
        int next = ((i + 1) % segments) * 2;
        
        fuselage.indices.push_back(frontTip);
        fuselage.indices.push_back(current);
        fuselage.indices.push_back(next);
    }
    
    // Rear cone triangles
    int rearTip = segments * 2 + 1;
    for (int i = 0; i < segments; ++i) {
        int current = i * 2 + 1;
        int next = ((i + 1) % segments) * 2 + 1;
        
        fuselage.indices.push_back(rearTip);
        fuselage.indices.push_back(next);
        fuselage.indices.push_back(current);
    }
    
    fuselage.setup();
    return fuselage;
}

// Function to handle key press events
// Function to handle key press events
void handleKeyPress(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action != GLFW_PRESS && action != GLFW_REPEAT) {
        return;
    }
    
    double currentTime = glfwGetTime();
    
    // Check for Enter key with delay to toggle wireframe
    if (key == GLFW_KEY_ENTER && (currentTime - lastKeyPressTime) > KEY_PRESS_DELAY) {
        wireframeMode = !wireframeMode;
        lastKeyPressTime = currentTime;
        return;
    }
    
    switch (key) {
        // Rotation controls - fixed to match requirements
        case GLFW_KEY_W:
            xRotation += 0.1f;  // W rotates about x-axis anti-clockwise
            break;
        case GLFW_KEY_S:
            xRotation -= 0.1f;  // S rotates about x-axis clockwise
            break;
        case GLFW_KEY_A:
            yRotation += 0.1f;  // A rotates about y-axis anti-clockwise
            break;
        case GLFW_KEY_D:
            yRotation -= 0.1f;  // D rotates about y-axis clockwise
            break;
        case GLFW_KEY_E:
            zRotation += 0.1f;  // E rotates about z-axis anti-clockwise
            break;
        case GLFW_KEY_Q:
            zRotation -= 0.1f;  // Q rotates about z-axis clockwise
            break;
            
        // Translation controls - fixed to match requirements
        case GLFW_KEY_I:
            yPosition += 0.1f;  // I increases y-position
            break;
        case GLFW_KEY_K:
            yPosition -= 0.1f;  // K decreases y-position
            break;
        case GLFW_KEY_L:
            xPosition += 0.1f;  // L increases x-position
            break;
        case GLFW_KEY_J:
            xPosition -= 0.1f;  // J decreases x-position
            break;
        case GLFW_KEY_O:
            zPosition += 0.1f;  // O increases z-position (not scale)
            break;
        case GLFW_KEY_U:
            zPosition -= 0.1f;  // U decreases z-position (not scale)
            break;
            
        // Propeller speed controls
        case GLFW_KEY_EQUAL: // + key
            propellerSpeed += 0.02f;
            break;
        case GLFW_KEY_MINUS: // - key
            propellerSpeed = (propellerSpeed - 0.02f > 0.0f) ? (propellerSpeed - 0.02f) : 0.0f;
            break;
    }
}

const char *getError() {
    const char *errorDescription;
    glfwGetError(&errorDescription);
    return errorDescription;
}

inline void startUpGLFW() {
    glewExperimental = true; // Needed for core profile
    if (!glfwInit()) {
        throw getError();
    }
}

inline void startUpGLEW() {
    glewExperimental = true; // Needed in core profile
    if (glewInit() != GLEW_OK) {
        glfwTerminate();
        throw getError();
    }
}

inline GLFWwindow *setUp() {
    startUpGLFW();
    glfwWindowHint(GLFW_SAMPLES, 4);               // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL
    GLFWwindow *window;                                           
    window = glfwCreateWindow(1000, 1000, WINDOW_TITLE, NULL, NULL);
    if (window == NULL) {
        cout << getError() << endl;
        glfwTerminate();
        throw "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n";
    }
    glfwMakeContextCurrent(window);
    startUpGLEW();
    return window;
}

int main() {
    GLFWwindow *window;
    try {
        window = setUp();
    } catch (const char *e) {
        cout << e << endl;
        throw;
    }
    
    // Set key callback
    glfwSetKeyCallback(window, handleKeyPress);
    
    // Create and compile our GLSL program from the shaders
    GLuint programID = LoadShaders("vertex_shader.glsl", "fragment_shader.glsl");
    
    // Create all shapes for the aircraft
    vector<Shape> shapes;
    
    // Main fuselage - using a more aerodynamic rounded shape
    shapes.push_back(createRoundedFuselage(Vec3(0.0f, 0.0f, 0.0f), 0.15f, 1.0f, 12, FUSELAGE_COLOR));
    
    // Nose cone
    shapes.push_back(createCone(Vec3(0.0f, 0.0f, 0.55f), 0.1f, 0.3f, 8, YELLOW, 'Z'));    
    // Cockpit window (streamlined to match the rounded fuselage)
    shapes.push_back(createCuboid(Vec3(0.0f, 0.1f, 0.3f), 0.3f, 0.1f, 0.3f, WINDOW_COLOR));
    
    // Side windows (modified to fit rounded fuselage)
    shapes.push_back(createCylinder(Vec3(-0.15f, 0.05f, 0.05f), 0.05f, 0.2f, 8, WINDOW_COLOR, 'Z'));
    shapes.push_back(createCylinder(Vec3(0.15f, 0.05f, 0.05f), 0.05f, 0.2f, 8, WINDOW_COLOR, 'Z'));
    
    // Main wings (cuboid)
    shapes.push_back(createCuboid(Vec3(0.0f, -0.05f, 0.0f), 1.5f, 0.05f, 0.4f, WING_COLOR));
    
    // Tail section horizontal stabilizer (cuboid)
    shapes.push_back(createCuboid(Vec3(0.0f, 0.0f, -0.6f), 0.6f, 0.05f, 0.2f, TAIL_COLOR2));
    
    // Tail section vertical stabilizer (triangular prism)
    shapes.push_back(createTriangularPrism(Vec3(0.0f, 0.15f, -0.6f), 0.1f, 0.3f, 0.3f, TAIL_COLOR));
    
    // Elevator (control surfaces on tail - different color)
    shapes.push_back(createCuboid(Vec3(0.0f, 0.0f, -0.7f), 0.5f, 0.05f, 0.1f, CONTROL_COLOR));
    
    // Rudder (control surface on vertical stabilizer - different color)
    shapes.push_back(createTriangularPrism(Vec3(0.0f, 0.15f, -0.75f), 0.05f, 0.2f, 0.1f, CONTROL_COLOR));
    
    shapes.push_back(createCylinder(Vec3(-0.5f, 0.05f, 0.15f), 0.1f, 0.3f, 8, ENGINE_COLOR, 'Z'));
    shapes.push_back(createCylinder(Vec3(0.5f, 0.05f, 0.15f), 0.1f, 0.3f, 8, ENGINE_COLOR, 'Z'));
    
    // Propeller hub (left and right engines)
    shapes.push_back(createCone(Vec3(-0.5f, 0.05f, 0.3f), 0.05f, 0.1f, 8, YELLOW, 'Z'));
    shapes.push_back(createCone(Vec3(0.5f, 0.05f, 0.3f), 0.05f, 0.1f, 8, YELLOW, 'Z'));
    
    // Propeller blades (left engine) - will be rotated during rendering
    shapes.push_back(createCuboid(Vec3(-0.5f, 0.05f, 0.35f), 0.4f, 0.02f, 0.02f, PROPELLER_COLOR));
    shapes.push_back(createCuboid(Vec3(-0.5f, 0.05f, 0.35f), 0.02f, 0.4f, 0.02f, PROPELLER_COLOR));
    
    // Propeller blades (right engine) - will be rotated during rendering
    shapes.push_back(createCuboid(Vec3(0.5f, 0.05f, 0.35f), 0.4f, 0.02f, 0.02f, PROPELLER_COLOR));
    shapes.push_back(createCuboid(Vec3(0.5f, 0.05f, 0.35f), 0.02f, 0.4f, 0.02f, PROPELLER_COLOR));
    
    // Landing gear struts
    shapes.push_back(createCuboid(Vec3(-0.3f, -0.2f, 0.2f), 0.05f, 0.3f, 0.05f, STRUT_COLOR));
    shapes.push_back(createCuboid(Vec3(0.3f, -0.2f, 0.2f), 0.05f, 0.3f, 0.05f, STRUT_COLOR));
    shapes.push_back(createCuboid(Vec3(0.0f, -0.2f, -0.5f), 0.05f, 0.3f, 0.05f, STRUT_COLOR));
    
    // Wheels (black cylinders)
    shapes.push_back(createCylinder(Vec3(-0.3f, -0.35f, 0.2f), 0.1f, 0.12f, 8, WHEEL_COLOR, 'X'));
    shapes.push_back(createCylinder(Vec3(0.3f, -0.35f, 0.2f), 0.1f, 0.12f, 8, WHEEL_COLOR, 'X'));
    shapes.push_back(createCylinder(Vec3(0.0f, -0.35f, -0.5f), 0.08f, 0.12f, 8, WHEEL_COLOR, 'X'));

    
    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    
    // Set background color (sky blue)
    glClearColor(0.5f, 0.7f, 1.0f, 1.0f);
    
    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        // Use our shader
        glUseProgram(programID);
        
        // Update propeller angle based on speed
        propellerAngle += propellerSpeed;
        if (propellerAngle > 2.0f * PI) {
            propellerAngle -= 2.0f * PI;
        }
        
        // Create main model matrix
        Mat4 model = Mat4::translation(xPosition, yPosition, zPosition);
        model = model * Mat4::rotationX(xRotation);
        model = model * Mat4::rotationY(yRotation);
        model = model * Mat4::rotationZ(zRotation);
        model = model * Mat4::scale(modelScale, modelScale, modelScale);
        
        // Draw all shapes with the main model transform
        for (size_t i = 0; i < shapes.size(); i++) {
            // Special case for propeller blades
            if (i >= 14 && i <= 17) {
                // Left propeller (blades 14-15)
                if (i == 14 || i == 15) {
                    Mat4 propellerModel = model * Mat4::translation(-0.5f, 0.05f, 0.35f);
                    propellerModel = propellerModel * Mat4::rotationZ(propellerAngle);
                    propellerModel = propellerModel * Mat4::translation(0.5f, -0.05f, -0.35f);
                    shapes[i].draw(programID, propellerModel, wireframeMode);
                }
                // Right propeller (blades 16-17)
                else {
                    Mat4 propellerModel = model * Mat4::translation(0.5f, 0.05f, 0.35f);
                    propellerModel = propellerModel * Mat4::rotationZ(propellerAngle);
                    propellerModel = propellerModel * Mat4::translation(-0.5f, -0.05f, -0.35f);
                    shapes[i].draw(programID, propellerModel, wireframeMode);
                }
            } else {
                shapes[i].draw(programID, model, wireframeMode);
            }
        }
        
        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    // Cleanup
    for (auto& shape : shapes) {
        shape.cleanup();
    }
    
    glDeleteProgram(programID);
    
    // Close OpenGL window and terminate GLFW
    glfwTerminate();
    
    return 0;
}