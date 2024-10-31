
#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 100;

class Matrix {
public:
	int matrix_size;
	double matrix_data[MAX_SIZE][MAX_SIZE]; //using array to prevent segmenation faults 100%

	Matrix(int size = 0) : matrix_size(size) {};

	~Matrix() {}

	void print() const {
		// Print the matrix to the console
		for (int y = 0; y < matrix_size; y++) {
			for (int x = 0; x < matrix_size; x++) {
				cout << matrix_data[y][x] << " ";
			}
			// make new line after row is finisehd
			cout << endl;
		}
		cout << endl;
	}

	Matrix operator+(const Matrix &other) const {
		// Implement matrix addition and store the result in 'result'
		Matrix result(matrix_size);
		for (int y = 0; y < matrix_size; y++) {
			for (int x = 0; x < matrix_size; x++) {
				result.matrix_data[y][x] = matrix_data[y][x]+other.matrix_data[y][x];
			}
		}
		return result;
	}

	Matrix operator*(const Matrix &other) const {
		// Implement matrix multiplication and store the result in 'result'
		Matrix result(matrix_size);
		for (int i = 0; i < matrix_size; i++) {
			for (int j = 0; j < matrix_size; j++) {
				result.matrix_data[i][j] = 0;
				for (int k = 0; k < matrix_size; k++) {
					result.matrix_data[i][j] += matrix_data[i][k]*other.matrix_data[k][j];
				}
			}
		}
		return result;
	}

	void get_diagonal_sum() const {
		// Calculate and print the sum of the diagonal elements
		double sum = 0;
		for (int diag = 0; diag < matrix_size; diag++) {
			sum += matrix_data[diag][diag];
		}
		cout << sum << endl;
	}

	void swap_row(int row1, int row2) {
		// Swap the rows 'row1' and 'row2' in the matrix
		// Handle invalid row indices
		if (row1 < 0 || row2 < 0 || row1 >= matrix_size || row2 >= matrix_size) {
			cout << "Invalid row indices" << endl;
			return;
		}

		for (int i = 0; i < matrix_size; i++) {
			double temp = matrix_data[row1][i]; // store value temporarilly

			matrix_data[row1][i] = matrix_data[row2][i]; // swap 2 -> 1
			matrix_data[row2][i] = temp; // 1 -> 2
		}

		print();
	}
};

void read_matrix_from_file(const string& file_name, Matrix& matrix_1, Matrix& matrix_2) {
    // Read matrix data from the file
    // Make sure to handle potential errors and invalid input
	ifstream file(file_name);
	if (!file.is_open()) {
		// handle missing file
		cout << "Couldn't find file" << endl;
		return;
	}

	// first line is matrix_size
	int matrix_size;
	file >> matrix_size;
	matrix_1.matrix_size = matrix_size;
	matrix_2.matrix_size = matrix_size;

	// then matrix_data for matrix 1 then 2
	for (int y = 0; y < matrix_size; y++) {
		for (int x = 0; x < matrix_size; x++) {
			file >> matrix_1.matrix_data[y][x];
            if (file.fail()) {
                cout << "Invalid value in matrix 1" << endl;
                return;
            }
		}
	}

	for (int y = 0; y < matrix_size; y++) {
		for (int x = 0; x < matrix_size; x++) {
			file >> matrix_2.matrix_data[y][x];
            if (file.fail()) {
                cout << "Invalid value in matrix 2" << endl;
                return;
            }
		}
	}

	file.close();
}

void print_matrix(const Matrix& matrix) {
    // Print the matrix to the console
	matrix.print();
}

void print_matrix(const Matrix& matrix_1, const Matrix& matrix_2) {
    // Print both matrices to the console
	matrix_1.print();
	matrix_2.print();
}

Matrix add_matrices(const Matrix& matrix_1, const Matrix& matrix_2) {
    // Implement matrix addition
	return matrix_1 + matrix_2;
}

Matrix multiply_matrices(const Matrix& matrix_1, const Matrix& matrix_2) {
    // Implement matrix multiplication
	return matrix_1 * matrix_2;
}

void get_diagonal_sum(const Matrix& matrix) {
    // Calculate and print the sum of the diagonal elements
	matrix.get_diagonal_sum();
}

void swap_matrix_row(Matrix& matrix, int row1, int row2) {
    // Swap the rows 'row1' and 'row2' in the matrix
    // Handle invalid row indices
	matrix.swap_row(row1, row2);
}

int main(int argc, char* argv[]) {
    Matrix matrix_1, matrix_2;
    read_matrix_from_file("matrix.txt", matrix_1, matrix_2);

    cout << "print_matrix" << endl;
    print_matrix(matrix_1, matrix_2);

    cout << "add_matrices result:" << endl;
    Matrix add_result_1 = add_matrices(matrix_1, matrix_2);
    Matrix add_result_2 = matrix_1 + matrix_2;
    print_matrix(add_result_1);
    print_matrix(add_result_2);

    cout << "multiply_matrices result:" << endl;
    Matrix multiply_result_1 = multiply_matrices(matrix_1, matrix_2);
    Matrix multiply_result_2 = matrix_1 * matrix_2;
    print_matrix(multiply_result_1);
    print_matrix(multiply_result_2);

    cout << "get matrix diagonal sum" << endl;
    get_diagonal_sum(matrix_1);

    cout << "swap matrix rows" << endl;
    swap_matrix_row(matrix_1, 0, 1);

    return 0;
}