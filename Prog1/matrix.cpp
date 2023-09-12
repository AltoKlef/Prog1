
#include "matrix.h"
#include <iostream>
#include <algorithm>
using namespace std;
Tmatrix::Tmatrix() {
	
	arr = new number * [capacity];
	for (int i = 0; i < capacity; i++) {
		arr[i] = new number[capacity];
	}
	int a = 0;
	for (int i = 0; i < capacity; i++) {
		for (int j = 0; j < capacity; j++) {
			arr[i][j] = a++;
		}
	}

}
void Tmatrix::FillMatrix() {
	printf("fill in the capacity = ");
	cin >> capacity;
	arr = new number * [capacity];
	for (int i = 0; i < capacity; i++) {
		arr[i] = new number[capacity];
	}
	printf("fill in the matrix \n");
	for (int i = 0; i < capacity; i++) {
		for (int j = 0; j < capacity; j++) {
			cout << "element" << "[" << i << "]" << "[" << j << "]:";
			cin >> arr[i][j];
		}
	}
}
void Tmatrix::PrintMatrix() {
	
	for (int i = 0; i < capacity; i++) {
		for (int j = 0; j < capacity; j++) {
			cout<<std::setw(4) << arr[i][j] << " ";
		}
		cout << std::endl;
	}
}
number Tmatrix::PrintDet() {
	number submatrix[10][10];
	fillWithZeros(submatrix);
	for (int i = 0; i < capacity; i++) {
		for (int j = 0; j < capacity; j++) {
			submatrix[i][j] = arr[i][j];
		}
		
	}
	return determinant(submatrix, capacity);
}
void Tmatrix::fillWithZeros(number massiv[10][10]) {
	for (int i = 0; i < capacity; ++i) {
		for (int j = 0; j < capacity; ++j) {
			massiv[i][j] = 0;
		}
	}
}

number Tmatrix::determinant(number matrix[10][10], int n) {
	number det = 0;
	number submatrix[10][10];
	if (n == 2)
		return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
	else {
		for (int x = 0; x < n; x++) {
			int subi = 0;
			for (int i = 1; i < n; i++) {
				int subj = 0;
				for (int j = 0; j < n; j++) {
					if (j == x)
						continue;
					submatrix[subi][subj] = matrix[i][j];
					subj++;
				}
				subi++;
			}
			det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
		}
	}
	return det;
}
void Tmatrix::Transposition() {
	number** arr2;
	arr2 = new number * [capacity];
	for (int i = 0; i < capacity; i++) {
		arr2[i] = new number[capacity];
	}
	for (int i = 0; i < capacity; i++) {
		for (int j = 0; j < capacity; j++) {
			arr2[i][j] = arr[i][j];
		}
	}
	int a = 0;
	for (int i = 0; i < capacity; i++) {
		for (int j = 0; j < capacity; j++) {
			arr[i][j] = arr2[j][i];
		}
	}
}
int Tmatrix::rank() {
	number** matrix;
	matrix = new number * [capacity];
	for (int i = 0; i < capacity; i++) {
		matrix[i] = new number[capacity];
	}
	for (int i = 0; i < capacity; i++) {
		for (int j = 0; j < capacity; j++) {
			matrix[i][j] = arr[i][j];
		}
	}
	int rank = 0;

	for (int col = 0; col < capacity; col++) {
		int nonzeroRow = -1;
		for (int row = rank; row < capacity; row++) {
			if (matrix[row][col] != 0.0) {
				nonzeroRow = row;
				break;
			}
		}

		if (nonzeroRow != -1) {
			if (nonzeroRow != rank) {
				std::swap(matrix[nonzeroRow], matrix[rank]);
			}
			double pivot = matrix[rank][col];
			for (int i = 0; i < capacity; i++) {
				matrix[rank][i] /= pivot;
			}
			for (int row = 0; row < capacity; row++) {
				if (row != rank) {
					double factor = matrix[row][col];
					for (int i = 0; i < capacity; i++) {
						matrix[row][i] -= factor * matrix[rank][i];
					}
				}
			}
			rank++;
		}
	}
	return rank;
}
