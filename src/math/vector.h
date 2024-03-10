#pragma once

#include <cstddef>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <iterator>
#include <initializer_list>

template <typename T, size_t _size>
class vector {
public:
  vector(std::initializer_list<T> initList) {
    check_range(initList.size());
    std::copy(initList.begin(), initList.end(), _data);
    if (initList.size() < _size)
      std::fill(_data + initList.size(), _data + _size, 0);
  }
  vector(const vector& other) {
    std::copy(std::begin(other._data), std::end(other._data), std::begin(_data));
  }
  vector(T(&arr)[_size]) {
    std::copy(std::begin(arr), std::end(arr), std::begin(_data));
  }
  vector() {};
  ~vector() {};

  T& operator[](size_t index) { return _data[index]; }
  T operator[](size_t index) const { return _data[index]; }
  T& at(const size_t index) { check_range(index); return _data[index]; }
  T at(const size_t index) const { check_range(index); return _data[index]; }

  T* begin() { return _data; }
  const T* begin() const { return _data; }
  T* end() { return _data + _size + 1; }
  const T* end() const { return _data + _size + 1; }

  size_t size() const { return _size; }

  template <typename K>
  vector scale(K value) const {
    vector<T, _size> res;
    std::transform(
      begin(), end(), res.begin(),
      [value](T item) { return item * value; });
    return res;
  }

  vector add(const vector& other) const {
    vector<T, _size> res;
    for (size_t i = 0; i < _size; i++) {
      res[i] = _data[i] + other[i];
    } return res;
  }
  vector sub(const vector& other) const {
    vector<T, _size> res;
    for (size_t i = 0; i < _size; i++) {
      res[i] = _data[i] - other[i];
    } return res;
  }
  double dot(const vector& other) const {
    double product = 0;
    for (size_t i = 0; i < _size; i++) {
      product += _data[i] * other[i];
    } return product;
  }

  double length() const {
    return
      std::sqrt(
        std::accumulate(
          std::begin(_data),
          std::end(_data), (double)0,
          [](double prev, double curr) { return prev + curr * curr; }));
  }

  vector normalize() const { return scale(1 / length()); }

  void print() const {
    for (size_t i = 0; i < _size; i++) {
      std::cout << _data[i] << ' ';
    } std::cout << '\n';
  }

private:
  void check_range(size_t index) {
    if (index > _size - 1)
      throw std::out_of_range("Index out of vector range");
  }

private:
  T _data[_size];
};
