#pragma once
#ifndef MATRIX_H
#define MATRIX_H
#include "number.h"
#include <iomanip>
#include <ostream>

using namespace std;


class Tmatrix
{
	//number capacity, coloumns_f;
public:
	Tmatrix();
	void FillMatrix(int cap);
	void PrintMatrix();
	number PrintDet();
	
	
	//friend ostream& operator<<(ostream&, Tmatrix&);
private:
	number** arr;
	int capacity = 3;
	void fillWithZeros(number matrix[10][10]);
	number determinant(number matrix[10][10], int capacity);
};

#endif // !MATRIX_H