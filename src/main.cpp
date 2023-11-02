#include <iostream>
#include <vector>

void mult_vector(std::vector<int> &v, int n) {
  for (auto &i : v) {
    i *= n;
  }
}

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};
  mult_vector(v, 2);

  for (auto &i : v) {
    std::cout << i << ' ';
  }
}