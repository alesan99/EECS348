
#include <iostream>
#include <fstream>

using namespace std;

const int MAX_SIZE = 100;

class Matrix {
private:
	double values[MAX_SIZE][MAX_SIZE];
	int size;

public:
	Matrix(int size) : size(size) {};

	int getSize() const {
		return size;
	}

	void read_matrix_from_stream() {
		// Read matrix data from cin into matrix_1 and matrix_2
		// Make sure to handle potential errors and invalid input
		for (int y = 0; y < size; y++) {
			// for each row
			for (int x = 0; x < size; x++) {
			// for each column
			int value;
			bool valid = false; // make sure input is valid to prevent errors
			while (!valid) {
				cout << x << ", " << y << ": "; // print row, column
				cin >> value;
				if (cin.fail()) {
				cout << "Invalid integer. Retry" << endl;
				cin.clear();
				cin.ignore(1000, '\n'); // ignore invalid input
				continue; // retry
				}
				valid = true;
			}
			values[y][x] = value;
			}
		}
	}

	void print() const {
		// Print the matrix to the console
		for (int y = 0; y < size; y++) {
			for (int x = 0; x < size; x++) {
				cout << values[y][x] << " ";
			}
			// make new line after row is finisehd
			cout << endl;
		}
		cout << endl;
	}

	Matrix operator+(const Matrix &other) const {
		// Implement matrix addition and store the result in 'result'
		Matrix result(size);
		for (int y = 0; y < size; y++) {
			for (int x = 0; x < size; x++) {
				result.values[y][x] = values[y][x]+other.values[y][x];
			}
		}
		return result;
	}

	Matrix operator*(const Matrix &other) const {
		// Implement matrix multiplication and store the result in 'result'
		Matrix result(size);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				result.values[i][j] = 0;
				for (int k = 0; k < size; k++) {
					result.values[i][j] += values[i][k]*other.values[k][j];
				}
			}
		}
		return result;
	}

	void get_diagonal_sum() const {
		// Calculate and print the sum of the diagonal elements
		double sum = 0;
		for (int diag = 0; diag < size; diag++) {
			sum += values[diag][diag];
		}
		cout << sum << endl;
	}

	void swap_row(int row1, int row2) {
		// Swap the rows 'row1' and 'row2' in the matrix
		// Handle invalid row indices
		if (row1 < 0 || row2 < 0 || row1 >= size || row2 >= size) {
			cout << "Invalid row indices" << endl;
			return;
		}

		for (int i = 0; i < size; i++) {
			double temp = values[row1][i]; // store value temporarilly

			values[row1][i] = values[row2][i]; // swap 2 -> 1
			values[row2][i] = temp; // 1 -> 2
		}
	}
};

int main(int argc, char *argv[]) {
	int size;
	cout << "Enter the size of the matrices: ";
	cin >> size;

	if (cin.fail() || size > MAX_SIZE) {
		cout << "Invalid matrix size." << endl;
		return 1;
	}
	Matrix matrix_1(size);
	Matrix matrix_2(size);

	cout << "Enter values for the matrix 1:" << endl;
	matrix_1.read_matrix_from_stream();
	cout << "Enter values for the matrix 2:" << endl;
	matrix_2.read_matrix_from_stream();
	cout << "print_matrix" << endl;
	matrix_1.print();
	matrix_2.print();

	Matrix add_result = matrix_1 + matrix_2;
	cout << "add_matrices result:" << endl;
	add_result.print();

	Matrix multiply_result_matrix = matrix_1 * matrix_2;
	cout << "multiply_matrices result:" << endl;
	multiply_result_matrix.print();

	cout << "get matrix diagonal sum" << endl;
	matrix_1.get_diagonal_sum();

	cout << "swap matrix rows" << endl;
	matrix_1.swap_row(0, 1);
	matrix_1.print();

	return 0;
}