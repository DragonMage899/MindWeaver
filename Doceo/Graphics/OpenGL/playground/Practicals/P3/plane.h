#include "shapes3.h"

Vector<3> CenterOfCone;

class Plane{
    protected:
    unsigned int shader_program;
    unsigned int vao;
    double rotSpeed = 0;
    double angle = 0.04;

    Vector<3> MainBodyCenter;

    std::vector<Shapes3D*> AllShapes;

    // std::vector<Shapes3D*> MainBody; //x1

    // std::vector<Shapes3D*> LeftWing; //x3 [wing body, wing edge, ailoron]
    // std::vector<Shapes3D*> RightWing; //x3 [wing body, wing edge, ailoron]
    
    // std::vector<Shapes3D*> Cockpit; //x3 [window (2 prism), base (cube)]
    
    // std::vector<Shapes3D*> Fuselage; //x2 [Top, Bottom]
    // std::vector<Shapes3D*> Propeller; //x4 [cone base, fins (3)]

    // std::vector<Shapes3D*> TailBody; //x7 [body, elev(2), stabH, stabV, connect(2)]

    // std::vector<Shapes3D*> wheels; //x3
    // std::vector<Shapes3D*> wheelArm; //x3
    
    public:
    Plane(unsigned int sid, unsigned int vao) : shader_program(sid), vao(vao){
        double* origin = new double[3]{0,0,0};
        MainBodyCenter = Vector<3>(origin);

        setUpPlane();     
    }
    ~Plane(){
        for (Shapes3D* shape : AllShapes) {
            delete shape;
        }
        AllShapes.clear();
    }

    void updateRot(double val){
        double temp = rotSpeed + val;
        if(angle + temp <= 0){return;}
        if(angle + temp >= 0.2){return;}

        rotSpeed += val;
    }

    void setUpPlane(){
        setUpMainBody();
        setUpWings();
        setUpFuselage();
        setUpPropeller();
        setUpCockPit();
        setUpWheels();
        setUpTail();
    }

    void orientParts(){
        // Can be used for dynamic adjustments during runtime
    }

    void drawPlane(){
        for(Shapes3D* sh : AllShapes){
            sh->draw();
            if(sh->getName() == "cone"){
                CenterOfCone = sh->getCenter();
            }

            double newangle = angle + rotSpeed;
            if(sh->getName() == "prop"){
                sh->rotate(newangle, 'X', CenterOfCone);
            }
        }
    }

    void rotate(double angle, char axis){
        for(Shapes3D* sh : AllShapes){
            sh->rotate(angle, axis, MainBodyCenter);
        }
    }

    void translate(double x, double y, double z){
        for(Shapes3D* sh : AllShapes){
            sh->translate(x, y, z);
        }
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

        // Adding ailerons to wings (control surfaces at the back of the wings)
        Vector<3> darkRed(new double[3]{0.8, 0.0, 0.0});
        
        // Left aileron
        Vector<3> ailCen(new double[3]{0, 0, 0});
        double ailHeight = 0.1;
        double ailWidth = 0.5;
        double ailLength = 0.1;
        Shapes3D* leftAileron = new Cube(ailCen, ailHeight, ailWidth, ailLength, darkRed, shader_program, vao);
        leftAileron->translate(0.3, -0.3, 0.4);
        
        // Right aileron
        Shapes3D* rightAileron = new Cube(ailCen, ailHeight, ailWidth, ailLength, darkRed, shader_program, vao);
        rightAileron->translate(0.3, -0.3, -0.4);

        AllShapes.push_back(leftWingbody);
        AllShapes.push_back(rightWingbody);
        AllShapes.push_back(leftAileron);
        AllShapes.push_back(rightAileron);
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

    void setUpWheels() {
        Vector<3> black(new double[3]{0.1, 0.1, 0.1});
        Vector<3> darkGrey(new double[3]{0.3, 0.3, 0.3});
        
        Vector<3> rearArmPos(new double[3]{0, 0, 0});
        double armHeight = 0.2;
        double armWidth = 0.05;
        double armLength = 0.05;
        Shapes3D* rearArm = new Cube(rearArmPos, armHeight, armWidth, armLength, darkGrey, shader_program, vao);
        rearArm->translate(0.9, -0.4, 0); 
        
        Vector<3> rearWheelPos(new double[3]{0, 0, 0});
        Shapes3D* rearWheel = new Cylinder(rearWheelPos, 0.08, 0.06, black, shader_program, vao, 12);
        rearWheel->translate(0.9, -0.55, -0.025);
        
        Vector<3> leftArmPos(new double[3]{0, 0, 0});
        double mainArmHeight = 0.3;
        Shapes3D* leftArm = new Cube(leftArmPos, mainArmHeight, armWidth, armLength, darkGrey, shader_program, vao);
        leftArm->translate(0, -0.5, 0.3);
        
        Vector<3> leftWheelPos(new double[3]{0, 0, 0});
        Shapes3D* leftWheel = new Cylinder(leftWheelPos, 0.15, 0.1, black, shader_program, vao, 12);
        leftWheel->translate(0, -0.7, 0.3);
        
        Vector<3> rightArmPos(new double[3]{0, 0, 0});
        Shapes3D* rightArm = new Cube(rightArmPos, mainArmHeight, armWidth, armLength, darkGrey, shader_program, vao);
        rightArm->translate(0, -0.5, -0.2);
        
        Vector<3> rightWheelPos(new double[3]{0, 0, 0});
        Shapes3D* rightWheel = new Cylinder(rightWheelPos, 0.15, 0.1, black, shader_program, vao, 12);
        rightWheel->translate(0, -0.7, -0.3);
        
        AllShapes.push_back(rearArm);
        AllShapes.push_back(rearWheel);
        AllShapes.push_back(leftArm);
        AllShapes.push_back(leftWheel);
        AllShapes.push_back(rightArm);
        AllShapes.push_back(rightWheel);
    }

    void setUpTail() {
        Vector<3> brown(new double[3]{0.596, 0.518, 0.425});
        Vector<3> red(new double[3]{1.0, 0.0, 0.0});
        Vector<3> blue(new double[3]{0.0, 0.0, 0.8});

        Vector<3> tailPos(new double[3]{0, 0, 0});
        double tailHeight = 0.4;    
        double tailWidth = 0.6;     
        double tailLength = 0.2;   
        
        Shapes3D* tailBody = new Cube(tailPos, tailHeight, tailWidth, tailLength, brown, shader_program, vao);
        tailBody->translate(0.7, -0.1, 0);  
        
        Vector<3> hStabPos(new double[3]{0, 0, 0});
        double hStabHeight = 0.05;
        double hStabWidth = 0.6;
        double hStabLength = 0.2;
        Shapes3D* horizontalStab = new Cube(hStabPos, hStabHeight, hStabWidth, hStabLength, red, shader_program, vao);
        horizontalStab->translate(1.2, 0.0, 0); 
        
        Vector<3> leftElevPos(new double[3]{0, 0, 0});
        double elevHeight = 0.05;
        double elevWidth = 0.2;
        double elevLength = 0.1;
        Shapes3D* leftElev = new Cube(leftElevPos, elevHeight, elevWidth, elevLength, blue, shader_program, vao);
        leftElev->translate(1.3, 0.0, 0.2);  
        leftElev->updateName("leftElev");
        
        // Right elevator
        Vector<3> rightElevPos(new double[3]{0, 0, 0});
        Shapes3D* rightElev = new Cube(rightElevPos, elevHeight, elevWidth, elevLength, blue, shader_program, vao);
        rightElev->translate(1.3, 0.0, -0.2); 
        rightElev->updateName("rightElev");
        
        Vector<3> vStabPos(new double[3]{0, 0, 0});
        double vStabHeight = 0.3;
        double vStabWidth = 0.2;
        double vStabLength = 0.05;
        Shapes3D* verticalStab = new Cube(vStabPos, vStabHeight, vStabWidth, vStabLength, red, shader_program, vao);
        verticalStab->translate(1.2, 0.15, 0); 
        
        Vector<3> rudderPos(new double[3]{0, 0, 0});
        double rudderHeight = 0.25;
        double rudderWidth = 0.1;
        double rudderLength = 0.05;
        Shapes3D* rudder = new Cube(rudderPos, rudderHeight, rudderWidth, rudderLength, blue, shader_program, vao);
        rudder->translate(1.3, 0.15, 0);  
        rudder->updateName("rudder");
        
        Vector<3> tailConePos(new double[3]{0, 0, 0});
        Shapes3D* tailCone = new Cone(tailConePos, 0.2, 0.3, brown, shader_program, vao, 12);
        tailCone->rotate(M_PI/2, 'Z');  
        tailCone->translate(0.2, -0.1, 0);  
        
        AllShapes.push_back(tailBody);
        AllShapes.push_back(horizontalStab);
        AllShapes.push_back(leftElev);
        AllShapes.push_back(rightElev);
        AllShapes.push_back(verticalStab);
        AllShapes.push_back(rudder);
        AllShapes.push_back(tailCone);
    }

    void enabileWire(){
        for(Shapes3D* sh : AllShapes){
            sh->toggleWire();
        }
    }

    void animateControlSurfaces(double elevatorAngle, double rudderAngle) {
        for(Shapes3D* sh : AllShapes){
            if(sh->getName() == "leftElev" || sh->getName() == "rightElev"){
                sh->resetT();
                sh->rotate(elevatorAngle, 'X');
            }
            if(sh->getName() == "rudder"){
                sh->resetT();
                sh->rotate(rudderAngle, 'Y');
            }
        }
    }
};