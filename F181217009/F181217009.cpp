
#include <iostream>
#include "MyMatrix.h"
int main()
{
    MyMatrix A(2,2);
    std::cout << "Matrix A\n";
    A.PrintMatrix();
    MyMatrix B(2, 2);
    std::cout << "Matrix B\n";
    B.PrintMatrix();
    MyMatrix C = MyMatrix::ScalarMultiplication(A, 2);
    std::cout << "Matrix C=A*2\n";
    C.PrintMatrix();
    MyMatrix D = MyMatrix::ScalarSum(B, 1);
    std::cout << "Matrix D=B+1\n";
    D.PrintMatrix();
    MyMatrix F = MyMatrix::MatrixSum(A, B);
    std::cout << "Matrix F=A+B\n";
    F.PrintMatrix();
    MyMatrix G = MyMatrix::MatrixMult(A, B);
    std::cout << "Matrix G=A*B\n";
    G.PrintMatrix();
}
