#include <functional>
#include <iostream>
#include <vector>

#include "ansi.cpp"

#define COLS 10
#define ROWS COLS

int find_max_in_matrix(std::vector<std::vector<int>> &matrix,
                       std::function<bool(int, int)> callback);

int main() {
  std::vector<std::vector<int>> matrix(ROWS, std::vector<int>(COLS));

  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < ROWS; j++) {
      matrix.at(i).at(j) = COLS * i + j;
    }
  }

  std::vector<std::function<bool(int, int)>> callbacks = {
      [](int i, int j) { return i < j; },
      [](int i, int j) { return i > j; },
      [](int i, int j) { return i <= j && COLS - i > j; },
      [](int i, int j) { return i >= j && COLS - i < j + 2; },
      [](int i, int j) {
        return i <= j && COLS - i > j || i >= j && COLS - i < j + 2;
      },
      [](int i, int j) {
        return i >= j && COLS - i > j || i <= j && COLS - i < j + 2;
      },
      [](int i, int j) { return i >= j && COLS - i > j; },
      [](int i, int j) { return i <= j && COLS - i < j + 2; },
      [](int i, int j) { return COLS - i > j + 1; },
      [](int i, int j) { return COLS - i <= j; }};

  for (auto &callback : callbacks)
    find_max_in_matrix(matrix, callback);
}

int find_max_in_matrix(std::vector<std::vector<int>> &matrix,
                       std::function<bool(int, int)> callback) {
  struct Max {
    int i, j, value;
  };
  Max max = {0, 0, matrix.at(0).at(0)};

  for (int i = 0; i < COLS; i++)
    for (int j = 0; j < ROWS; j++)
      if (callback(i, j) && matrix.at(i).at(j) > max.value)
        max = {i, j, matrix.at(i).at(j)};

  // printing part
  auto print_whitespaces = [](int n) { return n < 10 ? "  " : " "; };

  for (int i = 0; i < COLS; i++) {
    for (int j = 0; j < ROWS; j++) {
      if (callback(i, j)) {
        if (i == max.i && j == max.j)
          std::cout << ANSI::red << ANSI::bold << matrix.at(i).at(j)
                    << ANSI::reset << print_whitespaces(matrix.at(i).at(j));
        else
          std::cout << ANSI::blue << ANSI::bold << matrix.at(i).at(j)
                    << ANSI::reset << print_whitespaces(matrix.at(i).at(j));
      } else
        std::cout << ANSI::bold << matrix.at(i).at(j) << ANSI::reset
                  << print_whitespaces(matrix.at(i).at(j));
    }
    std::cout << '\n';
  }
  std::cout << '\n';
  return max.value;
}