// Alejandro Sandoval
// EECS 348 Lab 5 part 2

#include <stdio.h>

#define SIZE 5

int (*addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]))[SIZE];
int (*multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]))[SIZE];
int (*transposeMatrix(int m[SIZE][SIZE]))[SIZE];
int compareDimensions(int m1[SIZE][SIZE], int m2[SIZE][SIZE]);
int (*printMatrix(int m[SIZE][SIZE]))[SIZE];

int main() {
	// Input matrices
	static int m1[SIZE][SIZE] = {
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 10},
		{11, 12, 13, 14, 15},
		{16, 17, 18, 19, 20},
		{21, 22, 23, 24, 25}
	};

	static int m2[SIZE][SIZE] = {
		{25, 24, 23, 22, 21},
		{20, 19, 18, 17, 16},
		{15, 14, 13, 12, 11},
		{10, 9, 8, 7, 6},
		{5, 4, 3, 2, 1}
	};

	// Perform operations and print results
	printMatrix(addMatrices(m1, m2)); // Add
	printMatrix(multiplyMatrices(m1, m2)); // Multiply
	printMatrix(transposeMatrix(m1)); // Transpose
};

int (*addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]))[SIZE] {
	// Add two matrices
	static int result[SIZE][SIZE];
	if (compareDimensions(m1, m2) == 1) {
		printf("Matrices cannot be added. Not the same size\n");
		return result;
	}

	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) {
			result[y][x] = m1[y][x] + m2[y][x];
		}
	}
	return result;
};

int (*multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]))[SIZE] {
	// Multiply two matrices
	static int result[SIZE][SIZE];
	if (compareDimensions(m1, m2) == 1) {
		printf("Matrices cannot be multiplied are not the same size\n");
		return result;
	}

	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) {
			result[y][x] = 0;

			// dot product
			for (int i = 0; i < SIZE; i++) {
				result[y][x] += m1[y][i] * m2[i][x];
			}
		}
	}

	return result;
};

int (*transposeMatrix(int m[SIZE][SIZE]))[SIZE] {
	// Return new transposed matrix
	static int result[SIZE][SIZE];

	for (int y = 0; y < SIZE; y++) {
		for (int x = 0; x < SIZE; x++) {
			result[y][x] = m[x][y];
		}
	}
	return result;
};

int compareDimensions(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
	// Compare dimensions of two matrices
	// (Size will always be the same because it is defined as a constant)
	
	// Get length of first matrix
	int length = SIZE; //sizeof(m1) / sizeof(m1[0]); (gives compilation error for reason stated above)

	// Get length of second matrix
	int length2 = SIZE; //sizeof(m2) / sizeof(m2[0]); (ditto.)

	// Compare lengths
	if (length != length2) {
		return 1;
	}
	return 0;
};

int (*printMatrix(int m[SIZE][SIZE]))[SIZE] {
	// Print each row in order
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            printf("%d ", m[y][x]);
        }
        printf("\n");
    }
    printf("\n");
	return 0;
};