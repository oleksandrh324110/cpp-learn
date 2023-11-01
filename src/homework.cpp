#include "ansi.cpp"
#include <iostream>

#define COLS 10
#define ROWS COLS

struct Max {
  int i, j, value;
};

int find_max_in_matrix(int **matrix, bool (*fn)(int i, int j));

int main() {
  int **matrix = new int *[COLS];

  for (int i = 0; i < COLS; i++) {
    matrix[i] = new int[ROWS];
    for (int j = 0; j < ROWS; j++) {
      matrix[i][j] = i * COLS + j;
    }
  }

  bool (*callbacks[])(int, int) = {
      [](int i, int j) { return i < j; }, [](int i, int j) { return i > j; },
      [](int i, int j) { return i > j && COLS - i > j; },
      [](int i, int j) { return i > j && COLS - i < j; }};

  for (auto callback : callbacks)
    find_max_in_matrix(matrix, callback);
}

int find_max_in_matrix(int **matrix, bool (*callback)(int i, int j)) {
  Max max = {0, 0, matrix[0][0]};
  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < ROWS; j++) {
      if (callback(i, j) && matrix[i][j] > max.value)
        max = {i, j, matrix[i][j]};
    }
  }

  // printing part
  auto print_whitespaces = [](int n) { return n < 10 ? "  " : " "; };

  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < ROWS; j++) {
      if (callback(i, j)) {
        if (i == max.i && j == max.j)
          std::cout << ANSI::red << ANSI::bold << matrix[i][j] << ANSI::reset
                    << print_whitespaces(matrix[i][j]);
        else
          std::cout << ANSI::blue << ANSI::bold << matrix[i][j] << ANSI::reset
                    << print_whitespaces(matrix[i][j]);
      } else
        std::cout << ANSI::bold << matrix[i][j] << ANSI::reset
                  << print_whitespaces(matrix[i][j]);
    }
    std::cout << '\n';
  }
  std::cout << '\n';
  return max.value;
}