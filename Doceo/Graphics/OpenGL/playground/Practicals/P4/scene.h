#ifndef SCENE_H
#define SCENE_H

#include "shapes3.h"

class Scene{
    private:
    std::vector<Shapes3D*> objects;
    std::vector<Shapes3D*> sheet;
    Shapes3D* glass;
    float glassAlpha = 0.7;
    unsigned int shader_program;
    unsigned int vao;

    Shapes3D* lightGlobe;
    Shapes3D* back;
    Vector<3> origin;
    Vector<3> currentLightColor;

    public:
    Scene(unsigned int sid, unsigned int vao) : shader_program(sid), vao(vao){
        currentLightColor = Vector<3>(new double[3]{1.0, 1.0, 1.0});
        setUpLight();
        setUpBacksheet();
        setUpBottomSheet();
        setUpGlass();
        
        this->origin = Vector<3>(new double[3]{0,0,0});
    }

    Scene(unsigned int sid, unsigned int vao, int Res) : shader_program(sid), vao(vao){
        currentLightColor = Vector<3>(new double[3]{1.0, 1.0, 1.0});
        setUpLight();
        setUpBacksheet();
        setUpBottomSheet();
        setUpGlass();
        
        this->origin = Vector<3>(new double[3]{0,0,0});
    }

    void draw(){

        this->updateLighting();

        for(Shapes3D* sh : sheet){
            sh->draw();
        }

        for(Shapes3D* sh : objects){
            sh->draw();
        }
    }

    void updateLightColor(float r, float g, float b) {
        currentLightColor[0] = r;
        currentLightColor[1] = g;
        currentLightColor[2] = b;
    }

    void wire_draw(){
        for(Shapes3D* sh : sheet){
            sh->toggleWire();
            sh->draw();
            sh->toggleWire();
        }

        for(Shapes3D* sh : objects){
            sh->toggleWire();
            sh->draw();
            sh->toggleWire();
        }

    }

    void rotate(double angle, char axis){
        for(Shapes3D* sh : objects){
            sh->rotate(angle, axis, origin);
        }

        for(Shapes3D* sh : sheet){
            sh->rotate(angle, axis, origin);
        }
    }

    void translate(double x, double y, double z){
        for(Shapes3D* sh : objects){
            sh->translate(x, y, z);
        }

        for(Shapes3D* sh : sheet){
            sh->translate(x, y, z);
        }
    }

    void setOp(float op){
        for(Shapes3D* sh : objects){
            sh->setOp(op);
        }
        
        for(Shapes3D* sh : sheet){
            sh->setOp(op);
        }  
    }

    void updateSheetColor(float* col){
        for (Shapes3D* sh : sheet) {
            sh->setColor(col[0],col[1],col[2]);
        }
    }

    void updateGlassColor(float* col){
        glass->setColor(col[0],col[1],col[2], glassAlpha);
    }

    void updateLightColor(float* col){
        lightGlobe->setColor(col[0],col[1],col[2], glassAlpha);
    }

    void updateGlassAlpha(float a){
        if(glassAlpha + a < 0 || glassAlpha + a > 1)
            return;

        glassAlpha += a;
        glass->setOp(glassAlpha);
    }

    Shapes3D* getGlobe(){return lightGlobe;}
    Shapes3D* getBack(){return back;}

    private:
    void setUpBacksheet() {
        int rowCount, colCount = 0;
    
        std::cout << "Number of rows:" << std::endl;
        std::cin >> rowCount;
    
        std::cout << "Number of cols:" << std::endl;
        std::cin >> colCount;
    
        Vector<3> red(new double[3]{1, 0, 0});
    
        // Sheet dimensions
        double hgt = 0.6;
        double wid = 0.02;
        double len = 0.6;
    
        double cubeHeight = hgt / rowCount;
        double cubeDepth = len / colCount;
    
        // Pre-calculate the sheet's center after translation
        Vector<3> sheetCenter(new double[3]{-0.2, 0, 0});
    
        for (int i = 0; i < rowCount; i++) {
            for (int j = 0; j < colCount; j++) {
                // Position cubes in local grid (centered at 0,0,0)
                double centerY = (i + 0.5) * cubeHeight - hgt/2.0;
                double centerZ = (j + 0.5) * cubeDepth - len/2.0;
    
                Vector<3> cubeCen(new double[3]{0, centerY, centerZ});
    
                Shapes3D* backsheet = new Cube(cubeCen, cubeHeight, wid, cubeDepth, red, shader_program, vao);
                sheet.push_back(backsheet);
            }
        }
    
        // Apply transformations relative to sheet center
        for (Shapes3D* sh : sheet) {
            sh->translate(-0.2, 0, 0);  // Move entire sheet to X=-0.2
            sh->translate(0, 0, 0.0557);
            sh->rotate(0.3, 'Y', sheetCenter);  // Rotate around translated sheet center
        }
    }

    void setUpGlass(){
        Vector<3> cen(new double[3]{0,0,0});
        Vector<3> green(new double[3]{0,1,0});
        double hgt = 0.6;
        double wid = 0.1;
        double len = 0.6;
        Shapes3D* glass = new Cube(cen, hgt, wid, len, green, shader_program, vao);
        glass->rotate(0.3, 'Y');
        glass->setOp(0.7);
        //glass->changeFaceColor();
        this->glass = glass;
        objects.push_back(glass);
    }

    void setUpLight(){
        Vector<3> sphereCenter(new double[3]{0.0, 0.2, 0.0});
        Vector<3> sphereColor(new double[3]{0.2, 0.5, 0.8});
        double sphereRadius = 0.03;
        int sphereQuality = 50; 
        Sphere* light = new Sphere(sphereCenter, sphereRadius, sphereColor, shader_program, vao, sphereQuality);
        light->translate(0.2,0,0);
        light->changeFaceColor();

        this->lightGlobe = light;

        objects.push_back(light);
    }

    void setUpLight(int Res){
        Vector<3> sphereCenter(new double[3]{0.0, 0.2, 0.0});
        Vector<3> sphereColor(new double[3]{0.2, 0.5, 0.8});
        double sphereRadius = 0.3;
        int sphereQuality = Res; 
        Sphere* light = new Sphere(sphereCenter, sphereRadius, sphereColor, shader_program, vao, sphereQuality);
        light->translate(0.2,0,0);
        light->changeFaceColor();

        this->lightGlobe = light;

        objects.push_back(light);
    }

    void setUpBottomSheet(){
        Vector<3> cen(new double[3]{0,0,0});
        Vector<3> grey(new double[3]{0.5,0.5,0.5});
        double hgt = 0.6;
        double wid = 0.02;
        double len = 0.6;
        Shapes3D* bottomsheet = new Cube(cen, hgt, wid, len, grey, shader_program, vao);

        
        bottomsheet->rotate(M_PI/2, 'Z');
        bottomsheet->translate(0.09,0,0);
        bottomsheet->translate(0,-0.31,0);
        bottomsheet->rotate(0.3, 'Y');
        

        back = bottomsheet;
        objects.push_back(bottomsheet);
    }

    void updateLighting() {
        if (!lightGlobe) return;
    
        Vector<3> lightPos = lightGlobe->getCenter(); 
        Vector<3>& lightColorRGB = this->currentLightColor; 
    
        for (Shapes3D* backsheetCube_s3d : sheet) {
            if (!backsheetCube_s3d) continue;
            
            Cube* currentCube = static_cast<Cube*>(backsheetCube_s3d);
    
            for (int i = 0; i < currentCube->numShapes; ++i) {
                Shape* faceShape = currentCube->shapes[i];
                if (!faceShape) continue;
    
                Rectangle3D* rectFace = static_cast<Rectangle3D*>(faceShape);
                Triangle3D* trianglesToLight[] = {rectFace->tri1, rectFace->tri2};
                
                for (Triangle3D* tri : trianglesToLight) {
                    if (!tri) continue;
    
                    Vector<3> triCenter = tri->getCenter(); 
                    Vector<3> triNormal = tri->getNormal();   
                    Vector<3> matColor = tri->getBaseColor(); 
    
                    Vector<3> vecToLight = lightPos - triCenter;
                    double r_squared = vecToLight.magnitude();
                    r_squared = r_squared * r_squared;
                    
                    if (r_squared < 0.00001) r_squared = 0.00001;
    
                    double r = std::sqrt(r_squared);
                    double invMag = 1/vecToLight.magnitude();
                    Vector<3> l_vec = vecToLight * invMag;
    
                    double n_dot_l = triNormal * l_vec;
                    double diffuseFactor = std::max(0.0, n_dot_l);
    
                    Vector<3> finalColorVec(new double[3]{
                        matColor[0] * lightColorRGB[0] * diffuseFactor / r_squared,
                        matColor[1] * lightColorRGB[1] * diffuseFactor / r_squared,
                        matColor[2] * lightColorRGB[2] * diffuseFactor / r_squared
                    });
    
                    finalColorVec[0] = std::max(0.0, std::min(1.0, finalColorVec[0]));
                    finalColorVec[1] = std::max(0.0, std::min(1.0, finalColorVec[1]));
                    finalColorVec[2] = std::max(0.0, std::min(1.0, finalColorVec[2]));
    
                    // Update the triangle's rendering color using Shape::setColor
                    // Preserve original alpha if possible, or assume opaque for backsheet.
                    float originalAlpha = tri->getAlpha(); // Uses the new getAlpha() in Shape
                    tri->setColor(finalColorVec[0], finalColorVec[1], finalColorVec[2], originalAlpha);
                }
            }
        }
    }
};

#endif