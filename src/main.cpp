#include <iostream>
#include <vector>

template <typename T>
int binary_search(std::vector<T> &v, int left, int right, T value_to_find) {
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
  std::vector<int> v = {-3, -2, -1, 0, 1, 2, 3};

  for (auto el : v) {
    std::cout << binary_search(v, 0, v.size(), el) << ' ';
  }
}
