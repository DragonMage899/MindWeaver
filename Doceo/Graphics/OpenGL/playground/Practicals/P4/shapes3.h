#include "shapes2.h"

class Triangle3D : public Shape {
private:
    Vector<3> v0, v1, v2;
    Vector<3> color;
    GLuint programID, VAO;

public:
    Triangle3D(Vector<3> a, Vector<3> b, Vector<3> c, Vector<3> col, GLuint prog, GLuint vao) : Shape(prog, vao){
            v0 = a;
            v1 = b;
            v2 = c;
            color = col;
            setColor(col[0], col[1], col[2]);
        }

    void applyTransform(const Matrix<4, 4>& M){
        v0 = applyToVertex(v0, M);
        v1 = applyToVertex(v1, M);
        v2 = applyToVertex(v2, M);
    }

    void updateOpacity(float op){
        setColor(color[0], color[1], color[2], op);
    }

    void updateColor(Vector<3> col) {
        color = col;
        setColor(col[0], col[1], col[2]);
    }

void draw() override {
    // Build vertex buffer
    vertices.clear();
    for (int i = 0; i < 3; ++i) vertices.push_back(v0[i]);
    for (int i = 0; i < 3; ++i) vertices.push_back(v1[i]);
    for (int i = 0; i < 3; ++i) vertices.push_back(v2[i]);

    Shape::draw();

    // Upload vertex data
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // Configure vertex attributes (location 0 for vec3)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Call parent draw (binds VAO, sets shader, handles wireframe)
    if (wireframe) {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        } else {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }

    // Draw the triangle
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    }

    std::vector<Vector<3>> getVertices() const override {
        return {v0, v1, v2};
    }

    Vector<3> getV0() const { return v0; }
    Vector<3> getV1() const { return v1; }
    Vector<3> getV2() const { return v2; }

    Vector<3> getBaseColor() const {
        return color; 
    }

    Vector<3> getCenter() const {
        double centerX = (v0[0] + v1[0] + v2[0]) / 3.0;
        double centerY = (v0[1] + v1[1] + v2[1]) / 3.0;
        double centerZ = (v0[2] + v1[2] + v2[2]) / 3.0;
        return Vector<3>(new double[3]{centerX, centerY, centerZ});
    }

    Vector<3> getNormal() const {
        Vector<3> edge1 = v1 - v0;
        Vector<3> edge2 = v2 - v0;
        Vector<3> normal = edge1.crossProduct(edge2);
        double mag = normal.magnitude();
        mag = 1 / mag;
        Vector<3> normal1 = normal * mag;
        return normal1;
    }


private:
    Vector<3> applyToVertex(const Vector<3>& v, const Matrix<4, 4>& M) const {
        // Properly create a 2D array for Matrix<4, 1>
        double** vecArr = new double*[4];
        for (int i = 0; i < 4; ++i) {
            vecArr[i] = new double[1];
        }

        vecArr[0][0] = v[0];
        vecArr[1][0] = v[1];
        vecArr[2][0] = v[2];
        vecArr[3][0] = 1.0;

        Matrix<4, 1> vec4d(vecArr);
        Matrix<4, 1> result = M * vec4d;

        double* newCoords = new double[3]{
            result[0][0],
            result[1][0],
            result[2][0]
        };

        return Vector<3>(newCoords);
    }

};

class Rectangle3D : public Shape {
public:
    Triangle3D* tri1;
    Triangle3D* tri2;

public:
    Rectangle3D(Vector<3> a, Vector<3> b, Vector<3> c, Vector<3> d, Vector<3> color, GLuint prog, GLuint vao) : Shape(prog, vao) {
        tri1 = new Triangle3D(a, b, c, color, prog, vao);
        tri2 = new Triangle3D(b, d, c, color, prog, vao);
    }

    ~Rectangle3D() {
        delete tri1;
        delete tri2;
    }

    void applyTransform(const Matrix<4, 4>& M) override{
        tri1->applyTransform(M);
        tri2->applyTransform(M);
    }

    void draw() override {
        tri1->draw();
        tri2->draw();
    }

    void toggleWireframe() override{
        tri1->toggleWireframe();
        tri2->toggleWireframe();
    }

    std::vector<Vector<3>> getVertices() const override {
        std::vector<Vector<3>> verts1 = tri1->getVertices();
        std::vector<Vector<3>> verts2 = tri2->getVertices();
        verts1.insert(verts1.end(), verts2.begin(), verts2.end());
        return verts1;
    }

    void setColor(float red, float green, float blue, float alpha = 1.0f) override {
        Shape::setColor(red, green, blue, alpha);
        
        tri1->setColor(red, green, blue, alpha);
        tri2->setColor(red, green, blue, alpha);
    }

};


class Shapes3D : public Shape {
public:
    Matrix<4, 4> transform;
    Shape** shapes;
    int numShapes;
    Vector<3> center;

public:
    Shapes3D(unsigned int sid, unsigned int vao) : Shape(sid, vao) {
        transform = IdentityMatrix<4>();
        shapes = nullptr; 
        numShapes = 0; 
    }

    void resetT(){
        transform = IdentityMatrix<4>();
    }

    void setOp(float opacity) {
        color[3] = opacity;
        this->setColor(color[0], color[1], color[2], color[3]);
        
    }
    virtual ~Shapes3D() {
        for (int i = 0; i < numShapes; ++i) {
            delete shapes[i];
        }
        delete[] shapes;
    }

    void translate(double dx, double dy, double dz) {
        double** t = new double*[4] {
            new double[4]{1, 0, 0, dx},
            new double[4]{0, 1, 0, dy},
            new double[4]{0, 0, 1, dz},
            new double[4]{0, 0, 0, 1}
        };
        Matrix<4, 4> T(t);
        transform = T * transform;

        //std::cout << "Translation Matrix" << std::endl;
       // transform.print();
    }

    void rotate(double angleRad, char axis) {

        Vector<3> center = getCenter();
        //to origin
        double** t1 = new double*[4] {
            new double[4]{1, 0, 0, -center[0]},
            new double[4]{0, 1, 0, -center[1]},
            new double[4]{0, 0, 1, -center[2]},
            new double[4]{0, 0, 0, 1}
        };

        Matrix<4, 4> T1(t1);


        double c = cos(angleRad);
        double s = sin(angleRad);
        Matrix<4, 4> R;

        if (axis == 'X') {
            double** rx = new double*[4] {
                new double[4]{1, 0, 0, 0},
                new double[4]{0, c, -s, 0},
                new double[4]{0, s, c, 0},
                new double[4]{0, 0, 0, 1}
            };
            R = Matrix<4, 4>(rx);
        } else if (axis == 'Y') {
            double** ry = new double*[4] {
                new double[4]{c, 0, s, 0},
                new double[4]{0, 1, 0, 0},
                new double[4]{-s, 0, c, 0},
                new double[4]{0, 0, 0, 1}
            };
            R = Matrix<4, 4>(ry);
        } else if (axis == 'Z') {
            double** rz = new double*[4] {
                new double[4]{c, -s, 0, 0},
                new double[4]{s, c, 0, 0},
                new double[4]{0, 0, 1, 0},
                new double[4]{0, 0, 0, 1}
            };
            R = Matrix<4, 4>(rz);
        }

        //back to og
        double** t2 = new double*[4] {
            new double[4]{1, 0, 0, center[0]},
            new double[4]{0, 1, 0, center[1]},
            new double[4]{0, 0, 1, center[2]},
            new double[4]{0, 0, 0, 1}
        };
        Matrix<4, 4> T2(t2);

        transform = T2 * R * T1 * transform;

    }

    void rotate(double angleRad, char axis, Vector<3> cen) {

        Vector<3> center = cen;
        //to origin
        double** t1 = new double*[4] {
            new double[4]{1, 0, 0, -center[0]},
            new double[4]{0, 1, 0, -center[1]},
            new double[4]{0, 0, 1, -center[2]},
            new double[4]{0, 0, 0, 1}
        };

        Matrix<4, 4> T1(t1);


        double c = cos(angleRad);
        double s = sin(angleRad);
        Matrix<4, 4> R;

        if (axis == 'X') {
            double** rx = new double*[4] {
                new double[4]{1, 0, 0, 0},
                new double[4]{0, c, -s, 0},
                new double[4]{0, s, c, 0},
                new double[4]{0, 0, 0, 1}
            };
            R = Matrix<4, 4>(rx);
        } else if (axis == 'Y') {
            double** ry = new double*[4] {
                new double[4]{c, 0, s, 0},
                new double[4]{0, 1, 0, 0},
                new double[4]{-s, 0, c, 0},
                new double[4]{0, 0, 0, 1}
            };
            R = Matrix<4, 4>(ry);
        } else if (axis == 'Z') {
            double** rz = new double*[4] {
                new double[4]{c, -s, 0, 0},
                new double[4]{s, c, 0, 0},
                new double[4]{0, 0, 1, 0},
                new double[4]{0, 0, 0, 1}
            };
            R = Matrix<4, 4>(rz);
        }

        //back to og
        double** t2 = new double*[4] {
            new double[4]{1, 0, 0, center[0]},
            new double[4]{0, 1, 0, center[1]},
            new double[4]{0, 0, 1, center[2]},
            new double[4]{0, 0, 0, 1}
        };
        Matrix<4, 4> T2(t2);

        transform = T2 * R * T1 * transform;

    }

    void draw() override {
        for (int i = 0; i < numShapes; ++i) {
            shapes[i]->applyTransform(transform);
            shapes[i]->draw();
        }
        resetT();
    }

    void toggleWire(){
        for (int i = 0; i < numShapes; ++i) {
            shapes[i]->toggleWireframe();
        }
    }

    Vector<3> getCenter() const {
        std::vector<Vector<3>> allVertices;

        for (int i = 0; i < numShapes; ++i) {
            std::vector<Vector<3>> verts = shapes[i]->getVertices();
            allVertices.insert(allVertices.end(), verts.begin(), verts.end());
        }

        double sum[3] = {0, 0, 0};
        for (const Vector<3>& v : allVertices) {
            sum[0] += v[0];
            sum[1] += v[1];
            sum[2] += v[2];
        }

        int count = allVertices.size();
        double* centerArr = new double[3]{
            sum[0] / count,
            sum[1] / count,
            sum[2] / count
        };

        return Vector<3>(centerArr);
    }

    void setColor(float red, float green, float blue, float alpha = 1.0f) override {
        Shape::setColor(red, green, blue, alpha);
        
        for (int i = 0; i < numShapes; ++i) {
            shapes[i]->setColor(red, green, blue, alpha);
        }
    }

    void changeFaceColor() {
        float hueStep = 1.0f / numShapes;
        
        for (int i = 0; i < numShapes; ++i) {
            float hue = i * hueStep;
            
            float r, g, b;
            float h = hue * 6.0f;
            int sector = static_cast<int>(floor(h));
            float f = h - sector;
            
            switch(sector % 6) {
                case 0: r = 1.0f; g = f; b = 0.0f; break;
                case 1: r = 1.0f - f; g = 1.0f; b = 0.0f; break;
                case 2: r = 0.0f; g = 1.0f; b = f; break;
                case 3: r = 0.0f; g = 1.0f - f; b = 1.0f; break;
                case 4: r = f; g = 0.0f; b = 1.0f; break;
                case 5: r = 1.0f; g = 0.0f; b = 1.0f - f; break;
            }
            
            shapes[i]->setColor(r, g, b);
        }
    }
};

class Cube : public Shapes3D {
public:
    Cube(Vector<3> center, double height, double width, double length, Vector<3> color, GLuint sid, GLuint vao) : Shapes3D(sid, vao) {
        Vector<3> top    = Vector<3>(new double[3]{0, height / 2, 0});
        Vector<3> bottom = Vector<3>(new double[3]{0, -height / 2, 0});
        Vector<3> left   = Vector<3>(new double[3]{-width / 2, 0, 0});
        Vector<3> right  = Vector<3>(new double[3]{width / 2, 0, 0});
        Vector<3> near   = Vector<3>(new double[3]{0, 0, -length / 2});
        Vector<3> far    = Vector<3>(new double[3]{0, 0, length / 2});

        Vector<3> nlt = center + near + left + top;
        Vector<3> nrt = center + near + right + top;
        Vector<3> nlb = center + near + left + bottom;
        Vector<3> nrb = center + near + right + bottom;

        Vector<3> flt = center + far + left + top;
        Vector<3> frt = center + far + right + top;
        Vector<3> flb = center + far + left + bottom;
        Vector<3> frb = center + far + right + bottom;

        Shape* front  = new Rectangle3D(nlt, nrt, nlb, nrb, color, shader_program, VAO);
        Shape* back   = new Rectangle3D(frt, flt, frb, flb, color, shader_program, VAO);
        Shape* leftF  = new Rectangle3D(flt, nlt, flb, nlb, color, shader_program, VAO);
        Shape* rightF = new Rectangle3D(nrt, frt, nrb, frb, color, shader_program, VAO);
        Shape* bottoms = new Rectangle3D(nlb, nrb, flb, frb, color, shader_program, VAO);
        Shape* tops    = new Rectangle3D(nlt, nrt, flt, frt, color, shader_program, VAO);

                //testing colors
        // Vector<3> front_col(new double[3]{1,0,0});
        // Vector<3> back_col(new double[3]{1,0.5,0});
        // Vector<3> left_col(new double[3]{1,1,0});
        // Vector<3> right_col(new double[3]{1,1,0.5});
        // Vector<3> bot_col(new double[3]{1,1,1});
        // Vector<3> top_col(new double[3]{0,1,1});

        // Shape* front  = new Rectangle3D(nlt, nrt, nlb, nrb, front_col, shader_program, VAO);
        // Shape* back   = new Rectangle3D(frt, flt, frb, flb, back_col, shader_program, VAO);
        // Shape* leftF  = new Rectangle3D(flt, nlt, flb, nlb, left_col, shader_program, VAO);
        // Shape* rightF = new Rectangle3D(nrt, frt, nrb, frb, right_col, shader_program, VAO);
        // Shape* bottoms = new Rectangle3D(nlb, nrb, flb, frb, bot_col, shader_program, VAO);
        // Shape* tops    = new Rectangle3D(nlt, nrt, flt, frt, top_col, shader_program, VAO);


        numShapes = 6;
        shapes = new Shape*[6]{ front, back, leftF, rightF, bottoms, tops };
    
        this->color[0] = color[0];
        this->color[1] = color[1];
        this->color[2] = color[2];
    }

    Shape** getShapes(){
        return shapes;
    }
};

class TriangularPrism : public Shapes3D {
public:
    TriangularPrism(Vector<3> baseA, Vector<3> baseB, Vector<3> baseC, double depth, Vector<3> color, GLuint sid, GLuint vao)
        : Shapes3D(sid, vao) 
    {
        // Direction along Z-axis
        Vector<3> offset = Vector<3>(new double[3]{0, 0, depth});

        // Back triangle (offset in Z)
        Vector<3> A2 = baseA + offset;
        Vector<3> B2 = baseB + offset;
        Vector<3> C2 = baseC + offset;

        // Faces
        Shape* front = new Triangle3D(baseA, baseB, baseC, color, shader_program, VAO);
        Shape* back  = new Triangle3D(C2, B2, A2, color, shader_program, VAO); // reversed to maintain face orientation

        // Side rectangles (use base and offset pairs)
        Shape* side1 = new Rectangle3D(baseA, baseB, A2, B2, color, shader_program, VAO);
        Shape* side2 = new Rectangle3D(baseB, baseC, B2, C2, color, shader_program, VAO);
        Shape* side3 = new Rectangle3D(baseC, baseA, C2, A2, color, shader_program, VAO);

        numShapes = 5;
        shapes = new Shape*[numShapes]{ front, back, side1, side2, side3 };
        
        this->color[0] = color[0];
        this->color[1] = color[1];
        this->color[2] = color[2];
    }

};

class Circle3D : public Shape {
private:
    std::vector<Triangle3D*> triangles;

public:
    Circle3D(Vector<3> center, double radius, int segments, Vector<3> color, GLuint prog, GLuint vao)
        : Shape(prog, vao)
    {
        if (segments < 3) segments = 3;

        double angleStep = 2.0 * M_PI / segments;
        Vector<3>* points = new Vector<3>[segments + 1];

        // Generate circle points in XY plane
        for (int i = 0; i <= segments; i++) {
            double angle = i * angleStep;
            double x = center[0] + radius * std::cos(angle);
            double y = center[1] + radius * std::sin(angle);
            double z = center[2];
            points[i] = Vector<3>(new double[3]{x, y, z});
        }

        for (int i = 0; i < segments; ++i) {
            triangles.push_back(new Triangle3D(center, points[i], points[i + 1], color, prog, vao));
        }

        delete[] points;
    }

    ~Circle3D() {
        for (auto* t : triangles) {
            delete t;
        }
    }

    void applyTransform(const Matrix<4, 4>& M) override {
        for (auto* t : triangles) {
            t->applyTransform(M);
        }
    }

    void draw() override {
        for (auto* t : triangles) {
            t->draw();
        }
    }

    void setColor(float red, float green, float blue, float alpha = 1.0f) override {
        Shape::setColor(red, green, blue, alpha);
        for (auto* t : triangles) {
            t->setColor(red, green, blue, alpha);
        }
    }

    std::vector<Vector<3>> getVertices() const override {
        std::vector<Vector<3>> verts;
        for (auto* t : triangles) {
            auto triVerts = t->getVertices();
            verts.insert(verts.end(), triVerts.begin(), triVerts.end());
        }
        return verts;
    }
};


class Cone : public Shapes3D {
public:
    Cone(Vector<3> baseCenter, double radius, double height, Vector<3> color, GLuint prog, GLuint vao, int segments = 8)
        : Shapes3D(prog, vao)
    {
        if (segments < 3) segments = 3;

        double angleStep = 2.0 * M_PI / segments;
        Vector<3>* basePoints = new Vector<3>[segments + 1];

        // Apex point directly above center
        Vector<3> apex = baseCenter + Vector<3>(new double[3]{0, 0, height});

        // Generate circle points
        for (int i = 0; i <= segments; ++i) {
            double angle = i * angleStep;
            double x = baseCenter[0] + radius * std::cos(angle);
            double y = baseCenter[1] + radius * std::sin(angle);
            double z = baseCenter[2];
            basePoints[i] = Vector<3>(new double[3]{x, y, z});
        }

        // Build sides
        Shape** temp = new Shape*[segments + 1];
        for (int i = 0; i < segments; ++i) {
            temp[i] = new Triangle3D(basePoints[i], basePoints[i + 1], apex, color, prog, vao);
        }

        // Base face
        temp[segments] = new Circle3D(baseCenter, radius, segments, color, prog, vao);

        numShapes = segments + 1;
        shapes = temp;

        delete[] basePoints;

        this->color[0] = color[0];
        this->color[1] = color[1];
        this->color[2] = color[2];
    }
};

class Cylinder : public Shapes3D {
public:
    Cylinder(Vector<3> baseCenter, double radius, double height, Vector<3> color, GLuint prog, GLuint vao, int segments = 8)
        : Shapes3D(prog, vao)
    {
        if (segments < 3) segments = 3;

        double angleStep = 2.0 * M_PI / segments;
        Vector<3>* basePoints = new Vector<3>[segments + 1];
        Vector<3>* topPoints = new Vector<3>[segments + 1];

        // Top center
        Vector<3> topCenter = baseCenter + Vector<3>(new double[3]{0, 0, height});

        // Compute circle points
        for (int i = 0; i <= segments; ++i) {
            double angle = i * angleStep;
            double x = baseCenter[0] + radius * std::cos(angle);
            double y = baseCenter[1] + radius * std::sin(angle);
            double z = baseCenter[2];

            basePoints[i] = Vector<3>(new double[3]{x, y, z});
            topPoints[i]  = Vector<3>(new double[3]{x, y, z + height});
        }

        Shape** temp = new Shape*[segments * 2 + 2];

        // Side rectangles
        for (int i = 0; i < segments; ++i) {
            temp[i] = new Rectangle3D(basePoints[i], basePoints[i + 1], topPoints[i], topPoints[i + 1], color, prog, vao);
        }

        // Bottom circle
        temp[segments] = new Circle3D(baseCenter, radius, segments, color, prog, vao);

        // Top circle
        temp[segments + 1] = new Circle3D(topCenter, radius, segments, color, prog, vao);

        numShapes = segments + 2;
        shapes = temp;

        delete[] basePoints;
        delete[] topPoints;

        this->color[0] = color[0];
        this->color[1] = color[1];
        this->color[2] = color[2];
    }
};

class Sphere : public Shapes3D {
    public:
        Sphere(Vector<3> center, double radius, Vector<3> sphere_color, GLuint sid, GLuint vao, int quality = 16)
            : Shapes3D(sid, vao) {
    
            int stacks = quality < 3 ? 3 : quality;  // Number of horizontal divisions (latitude lines)
            int sectors = quality < 3 ? 3 : quality; // Number of vertical divisions (longitude lines)
    
            this->setColor(sphere_color[0], sphere_color[1], sphere_color[2]);
            std::vector<Vector<3>> sphere_vertices;
    
            sphere_vertices.push_back(Vector<3>(new double[3]{center[0], center[1], center[2] + radius}));
    
            for (int i = 1; i < stacks; ++i) {
                double phi = M_PI * (double)i / stacks; 

                for (int j = 0; j < sectors; ++j) { 
                    double theta = 2.0 * M_PI * (double)j / sectors;
    
                    double x = radius * std::sin(phi) * std::cos(theta);
                    double y = radius * std::sin(phi) * std::sin(theta);
                    double z_offset = radius * std::cos(phi); // Name z_offset to avoid conflict if center has 'z' member
    
                    sphere_vertices.push_back(Vector<3>(new double[3]{center[0] + x, center[1] + y, center[2] + z_offset}));
                }
            }
    
           sphere_vertices.push_back(Vector<3>(new double[3]{center[0], center[1], center[2] - radius}));
    
            std::vector<Triangle3D*> triangles_list;
    
            int top_pole_idx = 0;

            for (int j = 0; j < sectors; ++j) {
                int current_ring_v_idx = 1 + j;
                int next_ring_v_idx = 1 + (j + 1) % sectors; 
    
                
                triangles_list.push_back(new Triangle3D(
                    sphere_vertices[top_pole_idx],        
                    sphere_vertices[current_ring_v_idx],  
                    sphere_vertices[next_ring_v_idx],    
                    sphere_color, shader_program, VAO));
            }
    
            for (int i = 0; i < stacks - 2; ++i) { 
                int current_ring_start_idx = 1 + i * sectors;
                int next_ring_start_idx = 1 + (i + 1) * sectors;
    
                for (int j = 0; j < sectors; ++j) {
                    int tl_idx = current_ring_start_idx + j;
                    int tr_idx = current_ring_start_idx + (j + 1) % sectors;
                    int bl_idx = next_ring_start_idx + j;
                    int br_idx = next_ring_start_idx + (j + 1) % sectors;
    
                    triangles_list.push_back(new Triangle3D(
                        sphere_vertices[tl_idx],
                        sphere_vertices[bl_idx],
                        sphere_vertices[br_idx],
                        sphere_color, shader_program, VAO));
    
                    triangles_list.push_back(new Triangle3D(
                        sphere_vertices[tl_idx],
                        sphere_vertices[br_idx],
                        sphere_vertices[tr_idx],
                        sphere_color, shader_program, VAO));
                }
            }
    
            int bottom_pole_idx = sphere_vertices.size() - 1;
            int last_ring_start_idx = 1 + (stacks - 2) * sectors;
            for (int j = 0; j < sectors; ++j) {
                int current_ring_v_idx = last_ring_start_idx + j;
                int next_ring_v_idx = last_ring_start_idx + (j + 1) % sectors;
    
                triangles_list.push_back(new Triangle3D(
                    sphere_vertices[bottom_pole_idx],     
                    sphere_vertices[next_ring_v_idx],     
                    sphere_vertices[current_ring_v_idx],  
                    sphere_color, shader_program, VAO));
            }
    
            this->numShapes = triangles_list.size();
            this->shapes = new Shape*[this->numShapes];
            for (int k = 0; k < this->numShapes; ++k) {
                this->shapes[k] = triangles_list[k];
            }
        }
    
        ~Sphere() override {
        }
    
    };