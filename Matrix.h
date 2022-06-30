//
// Created by yonat on 6/30/2022.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H

#include <iostream>
#include "Exception.h"

class Matrix{
public:
    Matrix(int, int);
    Matrix(const Matrix&);
    ~Matrix();

    Matrix& operator=(const Matrix&);
    Matrix& operator+=(const Matrix&);
    Matrix& operator-=(const Matrix&);
    Matrix& operator*=(const Matrix&);
    Matrix& operator*=(double);
    Matrix transpose();
    int trace();

    void setElement(double, int, int);

    friend std::ostream& operator<<(std::ostream&, const Matrix&);

private:
    int row;
    int col;
    double** matrix;
};

Matrix operator+(const Matrix&, const Matrix&);
Matrix operator-(const Matrix&, const Matrix&);
Matrix operator*(const Matrix&);
Matrix operator*(const Matrix&, double);
Matrix operator*(double, const Matrix&);

#endif //MATRIX_MATRIX_H
