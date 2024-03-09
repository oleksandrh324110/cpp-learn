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
  matrix() {};
  ~matrix() {};

private:
  T _data[_rows][_cols];
};