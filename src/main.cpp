#include "ansi.cpp"
#include <ctime>
#include <iostream>
#include <random>

#define ROWS 2
#define COLS 2

void print_matrix(int **matrix);
int matrix_det(int **matrix);

int main() {
  srand(time(0));

  int **matrix = new int *[ROWS];

  for (int i = 0; i < ROWS; i++) {
    matrix[i] = new int[COLS];
    for (int j = 0; j < COLS; j++) {
      matrix[i][j] = rand() % 10;
    }
  }

  print_matrix(matrix);
  std::cout << '\n';

  std::cout << matrix_det(matrix) << '\n';
}

void print_matrix(int **m) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      std::cout << m[i][j] << " ";
    }
    std::cout << '\n';
  }
}

int matrix_det(int **matrix) {
  int det = 0;
  int acc[ROWS]{};

  for (int k = 0; k < ROWS; k++) {
    for (int i = 0; i < COLS; i++) {
      for (int j = 0; j < ROWS; j++) {
        if ((i + k) % ROWS == j) {
          acc[i] = matrix[i][j];
          std::cout << ANSI::bold << ANSI::green << acc[i] << ANSI::reset
                    << ' ';
        }
      }
    }

    int mult = acc[0];
    for (int i = 1; i < ROWS; i++) {
      mult *= acc[i];
    }

    det += mult;

    std::cout << '\n';

    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < ROWS; j++) {
        if ((ROWS - i + k + 1) % ROWS == j) {
          acc[i] = matrix[i][j];
          std::cout << ANSI::bold << ANSI::red << acc[i] << ANSI::reset << ' ';
        }
      }
    }

    mult = acc[0];
    for (int i = 1; i < ROWS; i++) {
      mult *= acc[i];
    }

    det -= mult;
    std::cout << '\n';

    if (ROWS == 2)
      return det;
  }

  return det;
}
