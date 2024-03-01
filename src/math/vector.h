#pragma once

#include <cstddef>

template <typename T, size_t size>
class vector {
public:
  vector(T data[size]);
  ~vector();

  size_t len();

  vector add(T value);
  vector sub(T value);
  vector mult(T value);
  vector div(T value);

  vector add(vector other);
  vector sub(vector other);
  vector mult(vector other);
  vector div(vector other);

private:
  T _data[size];
  size_t _size;
};