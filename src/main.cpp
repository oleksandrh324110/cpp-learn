#include <ctime>
#include <iostream>
#include <random>

#define ROWS 2
#define COLS 3

void print_matrix(int **m);
void matrix_sum(int **dest, int **m1, int **m2);

int main() {
  srand(time(0));

  int **dest = new int *[ROWS];
  int **matrix1 = new int *[ROWS];
  int **matrix2 = new int *[ROWS];

  for (int i = 0; i < ROWS; i++) {
    dest[i] = new int[COLS];
    matrix1[i] = new int[COLS];
    matrix2[i] = new int[COLS];
    for (int j = 0; j < COLS; j++) {
      matrix1[i][j] = rand() % 5;
      matrix2[i][j] = rand() % 5;
    }
  }

  print_matrix(matrix1);
  std::cout << '\n';
  print_matrix(matrix2);
  std::cout << '\n';

  matrix_sum(dest, matrix1, matrix2);

  print_matrix(dest);
}

void print_matrix(int **m) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      std::cout << m[i][j] << " ";
    }
    std::cout << '\n';
  }
}

void matrix_sum(int **dest, int **m1, int **m2) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      dest[i][j] = m1[i][j] + m2[i][j];
    }
  }
}