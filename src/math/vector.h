#pragma once

#include <cstddef>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <stdexcept>

template <typename T, size_t _size>
class Vector {
public:
  Vector(T& data[_size]) {
    std::copy(std::begin(data), std::end(data), std::begin(_data));
  }
  ~Vector();

  T& operator[](const size_t index) {
    return _data[index];
  };
  T& at(const size_t index) {
    if (index > _size - 1) {
      throw std::out_of_range("Index out of Vector range");
    }
    return _data[index];
  }

  size_t size() {
    return _size;
  };

  template <typename K> Vector& multiply(K value) {
    Vector<T, _size> res;
    for (int i = 0; i < _size; i++) {
      res[i] = _data[i] * value;
    } return res;
  };
  template <typename K> Vector& divide(K value) {
    Vector<T, _size> res;
    for (int i = 0; i < _size; i++) {
      res[i] = _data[i] / value;
    } return res;
  };

  Vector& add(Vector<T, _size>& other) {
    Vector<T, _size> res;
    for (int i = 0; i < _size; i++) {
      res[i] = _data[i] + other[i];
    } return res;
  };
  Vector& sub(Vector<T, _size>& other) {
    Vector<T, _size> res;
    for (int i = 0; i < _size; i++) {
      res[i] = _data[i] - other[i];
    } return res;
  }
  double dot(Vector<T, _size>& other) {
    double product = 0;
    for (int i = 0; i < _size; i++) {
      product += _data
    } return product;
  };

  double length() {
    return std::sqrt(std::accumulate(
      std::begin(_data),
      std::end(_data), 0,
      [](double prev, double curr) { return prev + curr * curr; }));
  };

  Vector& normalize() {
    return this->divide(this->length());
  }

private:
  T _data[_size];
};