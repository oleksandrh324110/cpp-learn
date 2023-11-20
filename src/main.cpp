#include <iostream>
#include <vector>

typedef unsigned int u32;

template <typename T>
u32 binary_search(std::vector<T> &v, u32 left, u32 right, T value_to_find) {
  int middle = left + (right - left) / 2;

  if (left == middle)
    return value_to_find == v[middle] ? middle : -1;
  if (value_to_find < v[middle])
    return binary_search(v, left, middle, value_to_find);
  if (value_to_find > v[middle])
    return binary_search(v, middle, right, value_to_find);
  return middle;
}

int main() {
  std::vector<float> v = {-5, -4, -3, -2.5, -1, 0, 1, 2, 3, 4, 5};

  for (float i : v) {
    std::cout << binary_search(v, 0, v.size(), i) << ' ';
  }
  std::cout << '\n';
}
