// OOP 13.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

int** readFile(int& numRows, int& numColumns) {
	ifstream fin;
	fin.open("matrix.txt");
	fin >> numRows >> numColumns;

	int** matrix = new int*[numRows];
	for (int i = 0; i < numRows; i++)
		matrix[i] = new int[numColumns];

	for (int i(0); i < numRows; i++) {
		for (int j(0); j < numColumns; j++) {
			fin >> matrix[i][j];
		}
	}

	return matrix;
}

int main() {
	int numRows = 0;
	int numColumns = 0;
	int** matrix = readFile(numRows, numColumns);
	int currentSum = 0;
	int maxSum = 0;
	int x[2], y[2];

	for (int Y = 0; Y < numRows; Y++) {
		for (int X = 0; X < numColumns; X++) {
			for (int Y1 = Y + 1; Y1 < numRows; Y1++) {
				for (int X1 = X + 1; X1 < numColumns; X1++) {
					currentSum = matrix[Y][X] + matrix[Y1][X1] + matrix[Y][X1] + matrix[Y1][X];
					if (currentSum > maxSum) {
						x[0] = X;
						x[1] = X1;
						y[0] = Y;
						y[1] = Y1;
						maxSum = currentSum;
					}
					currentSum = 0;
				}
			}
		}
	}

	cout << "Maximal sum is " << maxSum << endl;
	cout << "(" << x[0] << ";" << y[0] << ")" << "  " << "(" << x[1] << ";" << y[0] << ")" << endl;
	cout << "(" << x[0] << ";" << y[1] << ")" << "  " << "(" << x[1] << ";" << y[1] << ")" << endl;
	cout << matrix[y[0]][x[0]] << "  " << matrix[y[0]][x[1]] << endl;
	cout << matrix[y[1]][x[0]] << "  " << matrix[y[1]][x[1]];
	_getch();
	system("pause");
}