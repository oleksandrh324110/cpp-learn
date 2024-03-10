#pragma once

#include <cstddef>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <iterator>
#include <initializer_list>

template <typename T, size_t _rows, size_t _cols>
class matrix {
public:
  matrix(std::initializer_list<std::initializer_list<T>> initList) {
    size_t row = 0;
    for (const auto& rowList : initList) {
      if (row >= _rows)
        throw std::out_of_range("Too many rows in initializer list");
      if (rowList.size() != _cols)
        throw std::invalid_argument("Invalid number of columns in initializer list");
      std::copy(rowList.begin(), rowList.end(), _data[row]);
      row++;
    }
    if (row < _rows)
      throw std::out_of_range("Too few rows in initializer list");
  };
  matrix(matrix& other) {
    std::copy(other.begin(), other.end(), begin());
  };
  matrix(T(&arr)[_rows][_cols]) {
    for (size_t i = 0; i < _rows; ++i)
      std::copy(std::begin(arr[i]), std::end(arr[i]), std::begin(_data[i]));
  }
  matrix() {};
  ~matrix() {};

  T* begin() { return &_data[0][0]; }
  const T* begin() const { return &_data[0][0]; }
  T* end() { return &_data[_rows - 1][_cols]; }
  const T* end() const { return &_data[_rows - 1][_cols]; }

  void print() const {
    for (size_t i = 0; i < _rows; i++) {
      for (size_t j = 0; j < _cols; j++) {
        std::cout << _data[i][j] << ' ';
      } std::cout << '\n';
    }
  }

private:
  T _data[_rows][_cols];
};
