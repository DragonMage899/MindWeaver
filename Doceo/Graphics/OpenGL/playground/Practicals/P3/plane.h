#include "shapes3.h"

Vector<3> CenterOfCone;

class Plane{
    protected:
    unsigned int shader_program;
    unsigned int vao;

    Vector<3> MainBodyCenter;

    std::vector<Shapes3D*> AllShapes;

    std::vector<Shapes3D*> MainBody; //x1

    std::vector<Shapes3D*> LeftWing; //x3 [wing body, wing edge, ailoron]
    std::vector<Shapes3D*> RightWing; //x3 [wing body, wing edge, ailoron]
    
    std::vector<Shapes3D*> Cockpit; //x3 [window (2 prism), base (cube)]
    
    std::vector<Shapes3D*> Fuselage; //x2 [Top, Bottom]
    std::vector<Shapes3D*> Propeller; //x4 [cone base, fins (3)]

    std::vector<Shapes3D*> TailBody; //x7 [body, elev(2), stabH, stabV, connect(2)]

    std::vector<Shapes3D*> wheels; //x3
    std::vector<Shapes3D*> wheelArm; //x3
    
    public:
    Plane(unsigned int sid, unsigned int vao) : shader_program(sid), vao(vao){
        double* origin = new double[3]{0,0,0};
        MainBodyCenter = Vector<3>(origin);

        setUpPlane();     
    }
    ~Plane(){

    }

    void setUpPlane(){
        setUpMainBody();
        setUpWings();
        setUpFuselage();
        setUpPropeller();
        setUpCockPit();
    }

    void orientParts(){

    }

    void drawPlane(){
        for(Shapes3D* sh : AllShapes){
            sh->draw();
            if(sh->getName() == "cone"){
                CenterOfCone = sh->getCenter();
            }

            if(sh->getName() == "prop"){
                sh->rotate(0.04, 'X', CenterOfCone);
            }
        }
    }

    void rotate(double angle, char axis){
        for(Shapes3D* sh : AllShapes){
            sh->rotate(angle, axis, MainBodyCenter);
        }

    }

    void translate(double x, double y, double z){

    }

    void setUpMainBody(){
        Vector<3> cen(new double[3]{0,0,0});  
        Vector<3> brown(new double[3]{0.596,0.518,0.425});
        double hgt = 0.6;
        double wid = 0.8;
        double len = 0.4;

        Shapes3D* mainBody = new Cube(cen, hgt, wid, len, brown, shader_program, vao); 
        AllShapes.push_back(mainBody);
    }

    void setUpWings(){
        Vector<3> brown(new double[3]{0.696,0.618,0.525});
        Vector<3> red(new double[3]{1.0, 0.0, 0.0});

        //start from front face of body and stick out in += z direction
        //a,b on body, c sticking out
        Vector<3> a = new double[3]{-0.4,-0.3,0.2}; //right side
        Vector<3> b = new double[3]{0.4,-0.3,0.2}; //left side
        Vector<3> c = new double[3]{0.4,0,0.2}; //inline with righ
        Shapes3D* leftWingbody = new TriangularPrism(a,b,c,0.5, red, shader_program, vao);
        leftWingbody->rotate(M_PI / 2, 'Y');
        leftWingbody->translate(-0.2,0,0);
        

        Vector<3> ar = new double[3]{-0.4,-0.3,-0.2}; //right side
        Vector<3> br = new double[3]{0.4,-0.3,-0.2}; //left side
        Vector<3> cr = new double[3]{0.4,0,-0.2}; //inline with righ
        Shapes3D* rightWingbody = new TriangularPrism(ar,br,cr,0.5, red, shader_program, vao);
        rightWingbody->rotate(M_PI / 2, 'Y');
        rightWingbody->rotate(M_PI, 'Y');
        rightWingbody->translate(0,0,-0.5);
        rightWingbody->translate(-0.2,0,0);


        AllShapes.push_back(leftWingbody);
        AllShapes.push_back(rightWingbody);
    }

    void setUpFuselage(){
        Vector<3> cen(new double[3]{0,0,0});  
        Vector<3> brown(new double[3]{0.596,0.518,0.425});
        Vector<3> blue(new double[3]{0.0, 0.0, 1.0});
        double hgt = 0.3;
        double wid = 0.4;
        double len = 0.4;

        Shapes3D* fuselageBody = new Cube(cen, hgt, wid, len, blue, shader_program, vao); 
        fuselageBody->translate(-0.6,0.15,0);

        //cyl
        Vector<3> centerCyl(new double[3]{0, 0, 0});
        Vector<3> colorCyl(new double[3]{0, 1, 0});
        Shapes3D* mouth = new Cylinder(centerCyl, 0.2, 0.4, colorCyl, shader_program, vao, 16);
        mouth->rotate(M_PI / 2, 'Y');
        mouth->translate(-0.6, -0.1,-0.2);

        AllShapes.push_back(fuselageBody);
        AllShapes.push_back(mouth);
    }

    void setUpPropeller(){
        Vector<3> centerCone(new double[3]{0, 0, 0});
        Vector<3> colorCone(new double[3]{1, 1, 0});
        Shapes3D* cone = new Cone(centerCone, 0.18, 0.3, colorCone, shader_program, vao, 16);
        cone->rotate(-M_PI / 2, 'Y');
        cone->translate(-0.8,0.1,-0.05);

        Vector<3> coneCenter = cone->getCenter();

        Vector<3> grey(new double[3]{0.367,0.367,0.367});
        double hgt = 0.44;
        double wid = 0.02;
        double len = 0.05;
        Shapes3D* prop1 = new Cube(centerCone, hgt, wid, len, grey, shader_program, vao); 
        prop1->translate(-0.91,-0.1,0);

        Shapes3D* prop2 = new Cube(centerCone, hgt, wid, len, grey, shader_program, vao); 
        prop2->translate(-0.91,-0.3,0);
        prop2->rotate(2*M_PI / 3, 'X', coneCenter);

        Shapes3D* prop3 = new Cube(centerCone, hgt, wid, len, grey, shader_program, vao); 
        prop3->translate(-0.91,-0.22,0.15);
        prop3->rotate(4*M_PI / 3, 'X', coneCenter);

        cone->updateName("cone");
        prop1->updateName("prop");
        prop2->updateName("prop");
        prop3->updateName("prop");

        AllShapes.push_back(cone);
        AllShapes.push_back(prop1);
        AllShapes.push_back(prop2);
        AllShapes.push_back(prop3);

        CenterOfCone = coneCenter;
    }

    void setUpCockPit(){
        Vector<3> cen(new double[3]{0,0,0});  
        Vector<3> blue(new double[3]{0,0.867,1});
        double hgt = 0.3;
        double wid = 0.4;
        double len = 0.25;

        Shapes3D* cockPitBody = new Cube(cen, hgt, wid, len, blue, shader_program, vao); 
        cockPitBody->translate(0,0.3,0);
        cockPitBody->updateOpacity(0.2f);
        AllShapes.push_back(cockPitBody);
    }

    void enabileWire(){
        for(Shapes3D* sh : AllShapes){
            sh->toggleWire();
        }
    }
};
