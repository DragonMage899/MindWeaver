#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <cmath>
#include <iomanip>

#include "Vector.h"

template <int n>
class Vector;

template<int n, int m>
class Matrix
{
protected:
    double **arr;

public:
    Matrix();
    Matrix(double **);
    Matrix(const Matrix<n,m> &);
    virtual ~Matrix();
    double *&operator[](int index) const
    {
        if (index >= n || index < 0)
        {
            throw "Invalid index";
        }

        return arr[index];
    }

    
    Matrix<n,m>& operator=(const Matrix<n,m>&);
    template<int a>
    Matrix<n,a> operator*(const Matrix<m,a>) const;
    Matrix<n,m> operator*(const double) const;
    Matrix<n,m> operator+(const Matrix<n,m>) const;
    Matrix<m,n> operator~() const;
    void print() const
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                std::cout << (*this)[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    int getM() const;
    int getN() const;

    
};

template <int n>
class SquareMatrix : public Matrix<n,n>
{
public:
    SquareMatrix();
    SquareMatrix(double **);
    virtual ~SquareMatrix();
    Vector<n> solve(const Vector<n>) const;
    double determinant() const;
    SquareMatrix<n> operator!() const;
};

template <int n>
class IdentityMatrix : public SquareMatrix<n>
{
public:
    IdentityMatrix();
    virtual ~IdentityMatrix();
};

template <int n, int m>
Matrix<n, m>::Matrix()
{
    this->arr = new double*[n]();
    for (int i = 0; i < n; i++) {
        this->arr[i] = new double[m]();  
    }
}

template <int n, int m>
Matrix<n, m>::Matrix(double **otherArr)
{
    this->arr = otherArr;
}

template <int n, int m>
Matrix<n, m>::Matrix(const Matrix &other)
{
    this->arr = new double*[n]();

    for (int i = 0; i < n; i++) {
        this->arr[i] = new double[m]();  
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            double val = other[i][j];
            this->arr[i][j] = val;
        }
    }
}

template <int n, int m>
Matrix<n, m>::~Matrix()
{
    for(int i = 0; i < n; i++){
        delete[] this->arr[i];
    }

    delete[] arr;
}

template <int n, int m>
template <int a>
Matrix<n, a> Matrix<n, m>::operator*(const Matrix<m, a> rhs) const
{
    //need n arrays of size a
    double** array = new double*[n]();
    for (int i = 0; i < n; i++) {
        array[i] = new double[a]();  
    }

    int row = 0; //lhs row
    int col = 0; //rhs col

for(int i = 0; i < n; i++){
    for(int j = 0; j < a; j++){ 
        col = 0;
        while(col < m){
            array[i][j] += arr[row][col] * rhs[col][j];
            col++;
            }
        }
    row++;
    }


    Matrix<n, a> prod(array);
    return prod;
}

template <int n, int m>
Matrix<n, m> Matrix<n, m>::operator*(const double val) const
{

    double** array = new double*[n]();
    for (int i = 0; i < n; i++) {
        array[i] = new double[m]();  
    }  
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            array[i][j] = this->arr[i][j] * val;
        }
    }

    Matrix<n,m> mtrx(array);
    return mtrx;
}

template <int n, int m>
Matrix<n, m> Matrix<n, m>::operator+(const Matrix<n, m> rhs) const
{

    double** array = new double*[n]();
    for (int i = 0; i < n; i++) {
        array[i] = new double[m]();  
    }   

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            array[i][j] = this->arr[i][j] + rhs[i][j];
        }
    }

    Matrix<n,m> mtrx(array);
    return mtrx;
}

template <int n>
SquareMatrix<n> SquareMatrix<n>::operator!() const
{
    //Function that returns inverse of Matrix
    double det = determinant();

    if(n == 1){
        if(det == 0){
            throw("det = 0 when doing det");
        }

        double** invArr = new double*[1];
        invArr[0] = new double[1];
        invArr[0][0] = 1.0 / det;
        return SquareMatrix<n>(invArr);

    }

    if(det == 0){
        throw("det = 0 when doing det");
    }

    SquareMatrix<n> adjugate = getAdjoint(*this);

    //std::cout << "Adjugate debug print start" << std::endl;
    //adjugate.print();
    //std::cout << "Adjugate debug print end" << std::endl;

    SquareMatrix<n> inverse;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse[i][j] = adjugate[i][j] / det;
        }
    }

    return inverse;
}

template <int n, int m>
Matrix<m, n> Matrix<n, m>::operator~() const
{
    double** array = new double*[m]();
    for(int i = 0; i < m; i++){
        array[i] = new double[n]();
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
             array[i][j] = this->arr[j][i];
        }
    }

    Matrix<m, n> mtrx(array);

    return mtrx;
}

template <int n, int m>
int Matrix<n, m>::getM() const
{
    return m;
}

template <int n, int m>
int Matrix<n, m>::getN() const
{
    return n;
}

template <int n>
SquareMatrix<n>::SquareMatrix() : Matrix<n,n>(){}

template <int n>
SquareMatrix<n>::SquareMatrix(double **arr)
{
    this->arr = arr;
}

template <int n>
SquareMatrix<n>::~SquareMatrix()
{}

template <int n>
Vector<n> SquareMatrix<n>::solve(const Vector<n> vec) const
{
    //cramers rule
    //get ith unkown by replacing ith column with constants in vec
    //get det of replace and divide by og det

    double det = determinant();
    if(det == 0){
        double* array = new double[n]();
        Vector<n> v(array);
        return v;
    }
    double* sol = new double[n]();

    for(int col = 0; col < n; col++){
        //duplicate
        double** array = new double*[n]();
        for(int i = 0; i < n; i++){
            array[i] = new double[n]();  
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
            array[i][j] = this->arr[i][j];  
        }

        //replace
        for(int i = 0; i < n; i++){
            array[i][col] = vec[i];  
        }

        SquareMatrix<n> temp(array);
        sol[col] = temp.determinant() / det;
    }

    Vector<n> comp(sol);
    return comp;
}

template <int n>
double SquareMatrix<n>::determinant() const
{

    // gauss
    // goal : get upper triangle then det is product of diagonals
    // go col by col and zero out lem below diag
    // find pivot -> largest abs in current col
    // swap piv with current (det = -det)


    double** tempArr = new double*[n];
    for (int i = 0; i < n; ++i) {
        tempArr[i] = new double[n];
        for (int j = 0; j < n; ++j) {
            tempArr[i][j] = this->arr[i][j];
        }
    }

    double det = 1.0;

    for (int i = 0; i < n; ++i) {
        int piv = i;
        for (int j = i + 1; j < n; ++j) {
            if (std::abs(tempArr[j][i]) > std::abs(tempArr[piv][i])) {
                piv = j;
            }
        }

        if (piv != i) {
            std::swap(tempArr[i], tempArr[piv]);
            det *= -1;
        }

        if (tempArr[i][i] == 0) {
            for (int k = 0; k < n; ++k) {
                delete[] tempArr[k];
            }
            delete[] tempArr;
            return 0.0;
        }

        det *= tempArr[i][i];

        for (int j = i + 1; j < n; ++j) {
            double factor = tempArr[j][i] / tempArr[i][i];
            for (int k = i + 1; k < n; ++k) {
                tempArr[j][k] -= factor * tempArr[i][k];
            }
        }
    }

    // Cleanup temporary array
    for (int i = 0; i < n; ++i) {
        delete[] tempArr[i];
    }
    delete[] tempArr;

    return det;
}

template <int n>
IdentityMatrix<n>::IdentityMatrix() : SquareMatrix<n>()
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                this->arr[i][j] = 1;
            }
        }
    }
}

template <int n>
IdentityMatrix<n>::~IdentityMatrix()
{}

template <int n, int m>
inline Matrix<n, m> &Matrix<n, m>::operator=(const Matrix<n, m> &other)
{
    if (this == &other){
        return *this;
    }

    for (int i = 0; i < n; i++){
        delete[] this->arr[i];
    }
    delete[] this->arr;

    this->arr = new double*[n];
    for (int i = 0; i < n; i++) {
        this->arr[i] = new double[m];
        for (int j = 0; j < m; j++) {
            this->arr[i][j] = other[i][j];
        }
    }

    return *this;
}


template <int n>
SquareMatrix<n> getAdjoint(const SquareMatrix<n>& sqmtrx)
{
    SquareMatrix<n> cofactor = getCoefficient(sqmtrx);
    SquareMatrix<n> adjugate;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adjugate[i][j] = cofactor[j][i];
        }
    }

    return adjugate;
}

template <int n>
SquareMatrix<n> getCoefficient(const SquareMatrix<n>& sqmtrx)
{
    SquareMatrix<n> cofactor;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            SquareMatrix<n-1> minor = getMinor(sqmtrx, i, j);
            double minorDet = minor.determinant();
            int sign = ((i + j) % 2 == 0) ? 1 : -1;
            cofactor[i][j] = sign * minorDet;
        }
    }

    return cofactor;
}

template <int n>
SquareMatrix<n-1> getMinor(const SquareMatrix<n>& sqmtrx, int row, int col)
{ 
    double** minorArr = new double*[n-1];
    for (int i = 0; i < n-1; i++) {
        minorArr[i] = new double[n-1];
    }

    int minorRow = 0;
    for (int i = 0; i < n; i++) {
        if (i == row) 
            continue;

        int minorCol = 0;
        for (int j = 0; j < n; j++) {
            if (j == col) 
                continue;

            minorArr[minorRow][minorCol] = sqmtrx[i][j];
            minorCol++;
        }
        minorRow++;
    }

    return SquareMatrix<n-1>(minorArr);

};

#endif 