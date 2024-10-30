
#include <iostream>

using namespace std;

const int MAX_SIZE = 4; // Adjust if necessary

void read_matrix_from_stream(double matrix_1[][MAX_SIZE], 
                             double matrix_2[][MAX_SIZE], 
                             int &matrix_size) {

  cout << "Enter the size of the matrices: ";
  cin >> matrix_size;

  // TODO: Read matrix data from cin into matrix_1 and matrix_2
  //       Make sure to handle potential errors and invalid input

}

void print_matrix(const double matrix[][MAX_SIZE], int matrix_size) {
  // TODO: Print the matrix to the console
}

void print_matrix(const double matrix_1[][MAX_SIZE], 
                 const double matrix_2[][MAX_SIZE], 
                 int matrix_size) {
  // TODO: Print both matrices to the console
}

void add_matrices(const double matrix_1[][MAX_SIZE], 
                 const double matrix_2[][MAX_SIZE], 
                 double result[][MAX_SIZE], 
                 int matrix_size) {
  // TODO: Implement matrix addition and store the result in 'result'
}

void multiply_matrices(const double matrix_1[][MAX_SIZE], 
                      const double matrix_2[][MAX_SIZE], 
                      double result[][MAX_SIZE], 
                      int matrix_size) {
  // TODO: Implement matrix multiplication and store the result in 'result'
}

void get_diagonal_sum(const double matrix[][MAX_SIZE], int matrix_size) {
  // TODO: Calculate and print the sum of the diagonal elements
}

void swap_matrix_row(double matrix[][MAX_SIZE], int matrix_size, int row1, int row2) {
  // TODO: Swap the rows 'row1' and 'row2' in the matrix
  //       Handle invalid row indices
}

int main(int argc, char *argv[]) {
  double matrix_1[MAX_SIZE][MAX_SIZE], matrix_2[MAX_SIZE][MAX_SIZE];
  int matrix_size;

  read_matrix_from_stream(matrix_1, matrix_2, matrix_size);
  cout << "print_matrix" << endl;
  print_matrix(matrix_1, matrix_2, matrix_size);

  double add_result[MAX_SIZE][MAX_SIZE];
  add_matrices(matrix_1, matrix_2, add_result, matrix_size);
  cout << "add_matrices result:" << endl;
  print_matrix(add_result, matrix_size);

  double multiply_result[MAX_SIZE][MAX_SIZE];
  multiply_matrices(matrix_1, matrix_2, multiply_result, matrix_size);
  cout << "multiply_matrices result:" << endl;
  print_matrix(multiply_result, matrix_size);

  cout << "get matrix diagonal sum" << endl;
  get_diagonal_sum(matrix_1, matrix_size);

  cout << "swap matrix rows" << endl;
  swap_matrix_row(matrix_1, matrix_size, 0, 1);

  return 0;
}