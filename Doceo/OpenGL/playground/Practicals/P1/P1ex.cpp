#include "Matrix.cpp"
#include "Vector.cpp"

#include <iostream>
#include <sstream>

int main(int argc, char const *argv[])
{   

    std::cout << "---\nVector\n---" << std::endl;
    Vector<3> v1;
    v1.print();
    
    double* a = new double[3]{1,2,3};
    Vector<3> v2(a);
    v2.print();

    Vector<3> v3 = v2*2;
    v3.print();

    Vector<3> v4 = v2;
    v4.print();

    Vector<3> v5 = v2 + v3;
    v5.print();

    Vector<3> v6(v5);
    v6.print();

    double dp = v2*v2;
    std::cout << dp << std::endl;

    double* ma = new double[3]{0,0,3};
    Vector<3> mv(ma);
    std::cout << mv.magnitude() << std::endl << std::endl;

    double* c1 = new double[3]{7,3,-4};
    double* c2 = new double[3]{1,0,6};
    Vector<3> vc1(c1);
    Vector<3> vc2(c2);

    Vector<3> cross = vc1.crossProduct(vc2);
    cross.print();

    double* ua = new double[2]{4,-3};
    Vector<2> v7(ua);
    std::cout << "---\nUv\n---" << std::endl;
    v7.unitVector().print();
    std::cout << v7.getN() << std::endl;

    std::cout << "---\nMatrix\n---" << std::endl;

    Matrix<4,3> m0;
    m0.print();

    std::cout << '\n';

    double** m1a = new double*[1];
    m1a[0] = new double[3]{3,1,4};
    Matrix<1,3> m1(m1a);
    m1.print();
    std::cout << '\n';

    double** m2a = new double*[3];
    m2a[0] = new double[2]{4,3};
    m2a[1] = new double[2]{2,5};
    m2a[2] = new double[2]{6,8};
    Matrix<3,2> m2(m2a);
    m2.print();
    std::cout << '\n';

    Matrix<1,2> prod = m1*m2;
    prod.print();
    std::cout << '\n';

    double** testaa = new double*[3];
    testaa[0] = new double[2]{3,4};
    testaa[1] = new double[2]{7,2};
    testaa[2] = new double[2]{5,9};
    Matrix<3,2> testa(testaa);

    double** testba = new double*[2];
    testba[0] = new double[3]{3,1,5};
    testba[1] = new double[3]{6,9,7};
    Matrix<2,3> testb(testba);

    Matrix<3,3> testc = testa*testb;
    testc.print();


    double** deta = new double*[3];
    deta[0] = new double[3]{1,2,4};
    deta[1] = new double[3]{-1,3,0};
    deta[2] = new double[3]{4,1,0};
    SquareMatrix<3> detm(deta);
    std::cout << detm.determinant();


    IdentityMatrix<5> idt;
    idt.print();

    std::cout << "Before Transpose" << std::endl;
    m2.print();
    Matrix<2, 3> m2T(~m2);
    std::cout << "After Transpose" << std::endl;
    m2T.print();

    double** mInva = new double*[3];
    mInva[0] = new double[3]{2,-1,0};
    mInva[1] = new double[3]{0,1,2};
    mInva[2] = new double[3]{1,1,0};
    SquareMatrix<3> mInv(mInva);
    SquareMatrix<3> mInvs(!mInv);
    mInvs.print();

    double** mSolvea = new double*[2];
    mSolvea[0] = new double[2]{1,3};
    mSolvea[1] = new double[2]{2,2};
    SquareMatrix<2> mSolve(mSolvea);

    double* cona = new double[2];
    cona[0] = 5;
    cona[1] = 6;
    Vector<2> con(cona);

    std::cout << "Solutions" << std::endl;
    Vector<2> sol(mSolve.solve(con));
    sol.print();

    std::cout << "Crash tests" << std::endl;
    std::cout << "\nmul\n" << std::endl;
    double** crash11a = new double*[4];
    crash11a[0] = new double[4]{-4,-1,6,-2};
    crash11a[1] = new double[4]{3,7,-6,-7};
    crash11a[2] = new double[4]{-1,-3,-8,3};
    crash11a[3] = new double[4]{-9,7,-7,-2};
    Matrix<4,4> crash11(crash11a);

    double** crash12a = new double*[4];
    crash12a[0] = new double[1]{0};
    crash12a[1] = new double[1]{5};
    crash12a[2] = new double[1]{-1};
    crash12a[3] = new double[1]{4};
    Matrix<4,1> crash12(crash12a);

    Matrix<4,1> crash = crash11*crash12;
    crash.print();

    std::cout << "\nsolve\n" << std::endl;
    double** mSolvea2 = new double*[2];
    mSolvea2[0] = new double[2]{9,0};
    mSolvea2[1] = new double[2]{2,0};
    SquareMatrix<2> mSolve2(mSolvea2);

    double* cona2 = new double[2];
    cona2[0] = 0;
    cona2[1] = 10;
    Vector<2> con2(cona2);

    std::cout << "Solutions" << std::endl;
    Vector<2> sol2(mSolve2.solve(con2));
    sol2.print();
}
