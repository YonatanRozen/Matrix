//
// Created by yonat on 6/30/2022.
//

#include "Matrix.h"

using std::ostream;
using std::endl;
using std::min;

double** allocSpace(int row, int col) {
    double** mat = new double*[row];
    for (int i = 0; i < row; ++i) {
        mat[i] = new double[col];
    }
    return mat;
}

Matrix::Matrix(int row, int col){
    this->row = row;
    this->col = col;
    this->matrix = allocSpace(row, col);
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->col; ++j) {
            this->matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix& other) {
    this->row = other.row;
    this->col = other.col;
    this->matrix = allocSpace(other.row, other.col);
    for (int i = 0; i < other.row; ++i) {
        for (int j = 0; j < other.col; ++j) {
            this->matrix[i][j] = other.matrix[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < this->row; ++i) {
        delete[] this->matrix[i];
    }
    delete[] this->matrix;
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other){
        return *this;
    }

    double** temp = allocSpace(other.row, other.col);
    for (int i = 0; i < other.row; ++i) {
        for (int j = 0; j < other.col; ++j) {
            temp[i][j] = other.matrix[i][j];
        }
    }

    for (int i = 0; i < this->row; ++i) {
        delete[] this->matrix[i];
    }

    this->row = other.row;
    this->col = other.col;
    this->matrix = temp;
    return *this;
}

Matrix &Matrix::operator+=(const Matrix& other) {
    if (other.row != this->row || other.col != this->col){
        throw InvalidDimensions();
    }
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->col; ++j) {
            this->matrix[i][j] += other.matrix[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix& other) {
    if (other.row != this->row || other.col != this->col){
        throw InvalidDimensions();
    }
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->col; ++j) {
            this->matrix[i][j] -= other.matrix[i][j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
    if (this->col != other.row){
        throw InvalidDimensions();
    }
    Matrix res(this->row, other.col);
    for (int i = 0; i < res.row; ++i) {
        for (int j = 0; j < res.col; ++j) {
            for (int k = 0; k < other.row; ++k) {
                res.matrix[i][j] += this->matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    *this = res;
    return *this;
}

Matrix& Matrix::operator*=(double scalar) {
    for (int i = 0; i < this->row; ++i) {
        for (int j = 0; j < this->col; ++j) {
            this->matrix[i][j] *= scalar;
        }
    }
    return *this;
}

ostream &operator<<(ostream& os, const Matrix & mat) {
    for (int i = 0; i < mat.row; ++i) {
        for (int j = 0; j < mat.col; ++j) {
            os << " " << mat.matrix[i][j];
        }
        os << endl;
    }
    return os;
}

void Matrix::setElement(double val, int row, int col) {
    this->matrix[row][col] = val;
}

Matrix operator+(const Matrix& mat1, const Matrix& mat2){
    Matrix res = mat1;
    res += mat2;
    return res;
}

Matrix operator-(const Matrix& mat1, const Matrix& mat2){
    return mat1 + (-1*mat2);
}

Matrix operator*(const Matrix& mat, double scalar){
    Matrix res = mat;
    res *= scalar;
    return res;
}

Matrix operator*(double scalar, const Matrix& mat){
    Matrix res = mat;
    res *= scalar;
    return res;
}

Matrix operator*(const Matrix& mat1, const Matrix& mat2){
    Matrix temp = mat1;
    temp *= mat2;
    return temp;
}

int Matrix::trace() {
    int sum = 0, range = min(this->row, this->col);
    for (int i = 0; i < range; ++i) {
        sum += this->matrix[i][i];
    }
    return sum;
}

Matrix Matrix::transpose(){
    Matrix temp(*this);
    for (int i = 0; i < temp.col; ++i) {
        for (int j = 0; j < temp.row; ++j) {
            temp.matrix[i][j] = this->matrix[j][i];
        }
    }
    return temp;
}






