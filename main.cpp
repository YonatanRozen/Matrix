#include <iostream>
#include "Matrix.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    double mat1[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    double mat2[3][4] = {{1,2,3,4},
                         {5,6,7,8},
                         {9,10,11,12}};
    Matrix m = Matrix(3,3);
    Matrix f = Matrix(3,4);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; ++j) {
            m.setElement(mat1[i][j], i, j);
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            f.setElement(mat2[i][j], i, j);
        }
    }
    cout << m*f<< endl;
    return 0;
}