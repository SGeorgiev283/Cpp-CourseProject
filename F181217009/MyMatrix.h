#pragma once
#include <iostream>
#include<time.h>
#include <stdexcept>
class MyMatrix
{
private: int rows, columns;
	   int** data;
public:
	MyMatrix() {
		this->rows = 1;
		this->columns = 1;
		data = new int* [rows];
		for (int i = 0; i < rows; i++) {
			data[i] = new int[columns];
		}
	}
	MyMatrix(int rowss, int columnss) {
		srand(time(0));
		this->rows = rowss;
		this->columns = columnss;
		data = new int* [rowss];
		for (int i = 0; i < rowss; i++) {
			data[i] = new int[columnss];
		}
		for (int i = 0; i < rowss; i++) {
			for (int j = 0; j < columnss; j++) {
				data[i][j] = rand()%10;
			}
		}
		
	}
	void PrintMatrix() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < columns; j++) {
				std::cout << data[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
	static MyMatrix ScalarMultiplication(MyMatrix A,int a) { //Умножение със скалар
		for (int i = 0; i < A.rows; i++) {
			for (int j = 0; j < A.columns; j++) {
				A.data[i][j] = A.data[i][j] * a;
			}
		}
		return A;
	}
	static MyMatrix ScalarSum(MyMatrix A, int a) { //Събиране със скалар
		for (int i = 0; i < A.rows; i++) {
			for (int j = 0; j < A.columns; j++) {
				A.data[i][j] = A.data[i][j]+a;
			}
		}
		return A;
	}
	static MyMatrix MatrixMult(MyMatrix A, MyMatrix B) { //Матрично умножение
		if (A.columns != B.rows) {
			throw std::invalid_argument("Matrices dimensions missmatch");
		}
		MyMatrix C = MyMatrix(A.rows, B.columns);
		for (int i = 0; i < A.rows; i++)
			for (int j = 0; j < B.columns; j++)
				C.data[i][j] = 0.00000;
		for (int i = 0; i < A.rows; i++) {
			for (int j = 0; j < B.columns; j++)
				for (int k = 0; k < A.columns; k++)
					C.data[i][j] += A.data[i][k] * B.data[k][j];
		}
		return C;
	}
	static MyMatrix MatrixSum(MyMatrix A, MyMatrix B) { //Елементно събиране на 2 матрици
		if (A.rows != B.rows || A.columns != B.columns || A.columns != A.rows) {
			throw std::invalid_argument("Matrices must be squared and with equal dimensions");
		}
		else {
			MyMatrix C = MyMatrix(A.rows, A.columns);
			for (int i = 0; i < C.rows; i++) {
				for (int j = 0; j < C.columns; j++) {
					C.data[i][j] = A.data[i][j] + B.data[i][j];
				}
			}
			return C;
		}
	}
};