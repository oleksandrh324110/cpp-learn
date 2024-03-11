#pragma once

#include <cstddef>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <iterator>
#include <initializer_list>

#include "vector.h"

template <typename T, const size_t _rows, const size_t _cols>
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
  matrix(const matrix& other) {
    std::copy(other.begin(), other.end(), begin());
  };
  matrix(T(&arr)[_rows][_cols]) {
    for (size_t i = 0; i < _rows; ++i)
      std::copy(std::begin(arr[i]), std::end(arr[i]), std::begin(_data[i]));
  }
  matrix() {};
  ~matrix() {};

  constexpr size_t rows() const { return _rows; }
  constexpr size_t cols() const { return _cols; }

  T* operator[](size_t index) { return _data[index]; }
  const T* operator[](size_t index) const { return _data[index]; }

  T* begin() { return &_data[0][0]; }
  const T* begin() const { return &_data[0][0]; }
  T* end() { return &_data[_rows - 1][_cols]; }
  const T* end() const { return &_data[_rows - 1][_cols]; }

  matrix add(const matrix& other) const {
    matrix<T, _rows, _cols> res;
    for (size_t i = 0; i < _rows; i++) {
      for (size_t j = 0; j < _cols; j++) {
        res[i][j] = _data[i][j] + other[i][j];
      }
    } return res;
  }
  matrix operator+(const matrix& other) const { return add(other); }

  matrix sub(const matrix& other) const {
    matrix<T, _rows, _cols> res;
    for (size_t i = 0; i < _rows; i++) {
      for (size_t j = 0; j < _cols; j++) {
        res[i][j] = _data[i][j] - other[i][j];
      }
    } return res;
  }
  matrix operator-(const matrix& other) const { return sub(other); }

  matrix mult(const matrix<T, _cols, _rows>& other) const {
    matrix<T, std::max(_rows, _cols), other.cols()> res;
    return res;
  }
  // matrix operator*(const matrix<T, _cols, _rows>& other) const { return mult(other); }

  void print() const {
    for (size_t i = 0; i < _rows; i++) {
      for (size_t j = 0; j < _cols; j++) {
        if constexpr (std::is_same<T, char>::value)
          std::cout << (int)_data[i][j] << ' ';
        else
          std::cout << _data[i][j] << ' ';
      } std::cout << '\n';
    }
  }

private:
  T _data[_rows][_cols];
};