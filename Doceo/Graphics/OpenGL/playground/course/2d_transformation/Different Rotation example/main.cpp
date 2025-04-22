#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <chrono>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "shader.hpp"

#define timeDT std::chrono::_V2::steady_clock::time_point

using namespace glm;
using namespace std;

template <class T>
struct Tuple
{
    T x;
    T y;
};

struct Rectangle
{
    float t1Points[6]{-0.6, -0.1,
                      -0.6, 0.1,
                      -0.4, 0.1};
    float t2Points[6]{-0.4, 0.1,
                      -0.4, -0.1,
                      -0.6, -0.1};

    static Tuple<float> getTriangleMid(float* arr)
    {
        Tuple<float> res;
        res.x = 0;
        res.y = 0;
        for (int i = 0; i < 3; i++)
        {
            res.x += arr[i * 2];
            res.y += arr[i * 2 + 1];
        }
        res.x /= 3;
        res.y /= 3;
        return res;
    }

    static Tuple<float> getRectangleMid(Rectangle& shp){
        Tuple<float> res;
        res.x = 0;
        res.y = 0;
        for(int i=0; i < 6; i += 2){
            res.x += shp.t1Points[i] + shp.t2Points[i];
            res.y += shp.t1Points[i+1] + shp.t2Points[i+1];
        }
        res.x /= 6;
        res.y /= 6;
        return res;
    }

    void rotateT1(GLfloat *vertices, float angle)
    {
        Tuple<float> d = getTriangleMid(t1Points);
        mat3x3 T1 = mat3x3(0);
        T1[0].z = -1*d.x;
        T1[1].z = -1*d.y;
        T1[2].z = 1;
        T1[0].x = 1;
        T1[1].y = 1;
        mat3x3 R = mat3x3(0);
        R[0].x = cos(angle);
        R[0].y = -sin(angle);
        R[1].x = sin(angle);
        R[1].y = cos(angle);
        R[2].z = 1;
        mat3x3 T2 = mat3x3(0);
        T2[0].z = d.x;
        T2[1].z = d.y;
        T2[2].z = 1;
        T2[0].x = 1;
        T2[1].y = 1;
        mat3x3 M = transpose(T2) * transpose(R) * transpose(T1);
        for(int i=0; i < 6; i += 2){
            vec3 v = vec3(0.0f);
            v.x = t1Points[i];
            v.y = t1Points[i+1];
            v.z = 1;
            vec3 res = M*v;
            t1Points[i] = res.x;
            t1Points[i+1] = res.y;
            vertices[i] = res.x;
            vertices[i+1] = res.y;
        }
    };

    void rotateT2(GLfloat *vertices, float angle){
        Tuple<float> d = getTriangleMid(t2Points);
        mat3x3 T1 = mat3x3(0);
        T1[0].z = -1*d.x;
        T1[1].z = -1*d.y;
        T1[2].z = 1;
        T1[0].x = 1;
        T1[1].y = 1;
        mat3x3 R = mat3x3(0);
        R[0].x = cos(angle);
        R[0].y = -sin(angle);
        R[1].x = sin(angle);
        R[1].y = cos(angle);
        R[2].z = 1;
        mat3x3 T2 = mat3x3(0);
        T2[0].z = d.x;
        T2[1].z = d.y;
        T2[2].z = 1;
        T2[0].x = 1;
        T2[1].y = 1;
        mat3x3 M = transpose(T2) * transpose(R) * transpose(T1);
        for(int i=0; i < 6; i += 2){
            vec3 v = vec3(0.0f);
            v.x = t2Points[i];
            v.y = t2Points[i+1];
            v.z = 1;
            vec3 res = M*v;
            t2Points[i] = res.x;
            t2Points[i+1] = res.y;
            vertices[i+6] = res.x;
            vertices[i+1+6] = res.y;
        }
    };

    void rotateT1Rec(GLfloat *vertices, float angle)
    {
        Tuple<float> d = getRectangleMid(*this);
        mat3x3 T1 = mat3x3(0);
        T1[0].z = -1*d.x;
        T1[1].z = -1*d.y;
        T1[2].z = 1;
        T1[0].x = 1;
        T1[1].y = 1;
        mat3x3 R = mat3x3(0);
        R[0].x = cos(angle);
        R[0].y = -sin(angle);
        R[1].x = sin(angle);
        R[1].y = cos(angle);
        R[2].z = 1;
        mat3x3 T2 = mat3x3(0);
        T2[0].z = d.x;
        T2[1].z = d.y;
        T2[2].z = 1;
        T2[0].x = 1;
        T2[1].y = 1;
        mat3x3 M = transpose(T2) * transpose(R) * transpose(T1);
        for(int i=0; i < 6; i += 2){
            vec3 v = vec3(0.0f);
            v.x = t1Points[i];
            v.y = t1Points[i+1];
            v.z = 1;
            vec3 res = M*v;
            t1Points[i] = res.x;
            t1Points[i+1] = res.y;
            vertices[i+12] = res.x;
            vertices[i+1+12] = res.y;

            v = vec3(0.0f);
            v.x = t2Points[i];
            v.y = t2Points[i+1];
            v.z = 1;
            res = M*v;
            t2Points[i] = res.x;
            t2Points[i+1] = res.y;
            vertices[i+18] = res.x;
            vertices[i+1+18] = res.y;
        }
    };

    void rotateAsAWhole(GLfloat *vertices, float angle){
        mat3x3 R = mat3x3(0);
        R[0].x = cos(angle);
        R[0].y = -sin(angle);
        R[1].x = sin(angle);
        R[1].y = cos(angle);
        R[2].z = 1;
        for(int i=0; i < 6; i += 2){
            vec3 v = vec3(0.0f);
            v.x = t1Points[i];
            v.y = t1Points[i+1];
            v.z = 1;
            vec3 res = transpose(R)*v;
            t1Points[i] = res.x;
            t1Points[i+1] = res.y;
            vertices[i+24] = res.x;
            vertices[i+1+24] = res.y;

            v = vec3(0.0f);
            v.x = t2Points[i];
            v.y = t2Points[i+1];
            v.z = 1;
            res = transpose(R)*v;
            t2Points[i] = res.x;
            t2Points[i+1] = res.y;
            vertices[i+30] = res.x;
            vertices[i+1+30] = res.y;
        }
    }
};

const char *getError()
{
    const char *errorDescription;
    glfwGetError(&errorDescription);
    return errorDescription;
}

inline void startUpGLFW()
{
    glewExperimental = true; // Needed for core profile
    if (!glfwInit())
    {
        throw getError();
    }
}

inline void startUpGLEW()
{
    glewExperimental = true; // Needed in core profile
    if (glewInit() != GLEW_OK)
    {
        glfwTerminate();
        throw getError();
    }
}

inline GLFWwindow *setUp()
{
    startUpGLFW();
    glfwWindowHint(GLFW_SAMPLES, 4);               // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL
    GLFWwindow *window;                                            // (In the accompanying source code, this variable is global for simplicity)
    window = glfwCreateWindow(1000, 1000, "Experiment", NULL, NULL);
    if (window == NULL)
    {
        cout << getError() << endl;
        glfwTerminate();
        throw "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n";
    }
    glfwMakeContextCurrent(window); // Initialize GLEW
    startUpGLEW();
    return window;
}

double aFPS()
{
    static double lastTime = glfwGetTime();
    double currentTime = glfwGetTime();
    double detlaTime = currentTime - lastTime;
    cout << "FPS: " << 1 / detlaTime << endl;
    lastTime = currentTime;
    return detlaTime;
}

int main()
{
    Rectangle shpWrong;
    Rectangle shpRight;
    Rectangle shpOther;
    for(int i=0; i < 6; i+=2){
        shpRight.t1Points[i] += 1;
        shpRight.t2Points[i] += 1;
    }
    GLFWwindow *window;
    try
    {
        window = setUp();
    }
    catch (const char *e)
    {
        cout << e << endl;
        throw;
    }

    glClearColor(0.2, 0.2, 0.2, 0.2);
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    GLuint programID = LoadShaders("vertexShader.glsl", "fragmentShader.glsl");

    timeDT lastChanged = chrono::steady_clock::now();
    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    GLuint colorbuffer;
    glGenBuffers(1, &colorbuffer);
    double lastTime;
    lastTime = glfwGetTime();
    GLfloat vertices[36];
    GLfloat colors[]{
        1,
        0,
        0,
        0,
        1,
        0,
        1,
        0,
        1,
        1,
        0,
        0,
        0,
        1,
        0,
        1,
        0,
        1,
        1,
        0,
        0,
        0,
        1,
        0,
        1,
        0,
        1,
        1,
        0,
        0,
        0,
        1,
        0,
        1,
        0,
        1,
        1,
        0,
        0,
        0,
        1,
        0,
        1,
        0,
        1,
        1,
        0,
        0,
        0,
        1,
        0,
        1,
        0,
        1,
    };
    for(int i=0; i < 6; i++){
        vertices[i] = shpWrong.t1Points[i];
        vertices[i+6] = shpWrong.t2Points[i];
        vertices[i+12] = shpRight.t1Points[i];
        vertices[i+18] = shpRight.t2Points[i];
        vertices[i+24] = shpOther.t1Points[i];
        vertices[i+30] = shpOther.t2Points[i];
    }
    do
    {
        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastTime;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(programID);

        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
            0,        // attribute 0. No particular reason for 0, but must match the layout in the shader.
            2,        // size
            GL_FLOAT, // type
            GL_FALSE, // normalized?
            0,        // stride
            (void *)0 // array buffer offset
        );

        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
        glVertexAttribPointer(
            1,        // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,        // size
            GL_FLOAT, // type
            GL_FALSE, // normalized?
            0,        // stride
            (void *)0 // array buffer offset
        );
        glDrawArrays(GL_TRIANGLES, 0, 18); // Starting from vertex 0; 3 vertices total -> 1 triangle

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glfwSwapBuffers(window);
        glfwPollEvents();
        float angle = 0.1;

        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
            shpWrong.rotateT1(vertices, angle);
            shpWrong.rotateT2(vertices, angle);
            shpRight.rotateT1Rec(vertices, angle);
            shpOther.rotateAsAWhole(vertices, angle);
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
            shpWrong.rotateT1(vertices, -1*angle);
            shpWrong.rotateT2(vertices, -1*angle);
            shpRight.rotateT1Rec(vertices, -1*angle);
            shpOther.rotateAsAWhole(vertices, -1*angle);
        }

        lastTime = currentTime;
        cout << "FPS: " << 1 / deltaTime << endl;

    } while (glfwGetKey(window, GLFW_KEY_SPACE) != GLFW_PRESS &&
             glfwWindowShouldClose(window) == 0);
}
