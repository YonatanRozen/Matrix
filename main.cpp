#include <iostream>
#include "Matrix.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    int row, col;
    cout << "Enter the number of matrix rows:" << endl;
    cin >> row;
    cout << "Enter the number of matrix columns:" << endl;
    cin >> col;
    Matrix A = Matrix(row, col);

    int val;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << "Enter element: " << endl;
            cin >> val;
            A.setElement(val, i, j);
        }
    }

    cout << A << endl;

    cout << A.operator*=(A*4) << endl;}
