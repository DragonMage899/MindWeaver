#ifndef VECTOR_H
#define VECTOR_H

#include "Matrix.h"

template<int n, int m>
class Matrix;

//use tempates to automatically infer sizes for function calls
template<int n>// size of the vector
class Vector
{
private:   
    double *arr; // array containing the elements in the vector

public:
    Vector();
    Vector(double *);
    ~Vector();
    Vector(const Vector<n> &);
    Vector(const Matrix<n,1>& );
    Vector<n>& operator=(const Vector<n>&);
    Vector<n> operator+(const Vector<n>) const;
    Vector<n> operator-(const Vector<n>) const;
    Vector<n> operator*(const double) const;
    double operator*(const Vector<n>) const;
    double &operator[](int index) const
    {
        if (index < 0 || index >= n)
        {
            throw "Invalid Index";
        }
        return arr[index];
    }
    double magnitude() const;
    operator Matrix<n,1>() const;
    Vector<3> crossProduct(const Vector<3>) const;
    Vector<n> unitVector() const;
    int getN() const;
    void print() const
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << arr[i] << "\n";
        }
        std::cout << std::endl;
    };
};

template <int n>
Vector<n>::Vector()
{
    arr = new double[n]();
}

template <int n>
Vector<n>::Vector(double *arr) : arr(arr)
{}

template <int n>
Vector<n>::~Vector()
{
    delete arr;
}

template <int n>
Vector<n>::Vector(const Vector<n> &other)
{   
    this->arr = new double[n]{};

    for(int i = 0; i < n; i++){
        this->arr[i] = other[i];
    }
}

template <int n>
Vector<n>::Vector(const Matrix<n, 1> &other)
{
    for(int i = 0; i < n; i++){
        this->arr[i] = other[i][1];
    }
}

template <int n>
Vector<n> &Vector<n>::operator=(const Vector<n> &other)
{
    if (this == &other) {
        return *this;
    }

    double* a = new double[n];
    for (int i = 0; i < n; i++) {
        a[i] = other[i];
    }

    delete[] this->arr;
    this->arr = a;

    return *this;
}

template <int n>
Vector<n> Vector<n>::operator+(const Vector rhs) const
{
    double* a = new double[n]();

    for(int i = 0; i < n; i++){
        a[i] = this->arr[i] + rhs[i];
    }

    Vector<n> v(a);
    return v;
}

template <int n>
Vector<n> Vector<n>::operator-(const Vector<n> rhs) const
{
    double* a = new double[n]();

    for(int i = 0; i < n; i++){
        a[i] = this->arr[i] - rhs[i];
    }

    Vector<n> v(a);
    return v;
}

template <int n>
Vector<n> Vector<n>::operator*(const double val) const
{
    double* a = new double[n]();

    for(int i = 0; i < n; i++){
        a[i] = this->arr[i] * val;
    }

    Vector<n> v(a);
    return v;
}

template <int n>
double Vector<n>::operator*(const Vector<n> rhs) const
{
    double dotprod{};

    for(int i = 0; i < n; i++){
        dotprod += this->arr[i] * rhs[i];
    }
    
    return dotprod;
}

template <int n>
double Vector<n>::magnitude() const
{
    double mag{};

    for(int i = 0; i < n; i++){
        mag += this->arr[i] * this->arr[i];
    }

    return sqrt(mag);
}

template <int n>
Vector<n>::operator Matrix<n, 1>() const
{
    double** a = new double[n][1]{};

    for(int i = 0; i < n; i++){
        a[i][1] = this->arr[i]; 
    }

    Matrix<n,1> m(a);
    return m;
}

template <>
Vector<3> Vector<3>::crossProduct(const Vector<3> rhs) const
{   
    double a1 = arr[1] * rhs[2] - arr[2] * rhs[1];
    double a2 = arr[2] * rhs[0] - arr[0] * rhs[2];
    double a3 = arr[0] * rhs[1] - arr[1] * rhs[0];

    double* a =  new double[3]{a1,a2,a3};

    Vector<3> v(a);
    return v;
}

template <int n>
Vector<n> Vector<n>::unitVector() const
{
    if(magnitude() == 0){
        throw(" Invalid unit vector");
    }

    double* a = new double[n]();

    for(int i = 0; i < n; i++){
        a[i] = this->arr[i] / magnitude();
    }

    Vector<n> v(a);
    return v;
}

template <int n>
int Vector<n>::getN() const
{
    return n;
};

#endif