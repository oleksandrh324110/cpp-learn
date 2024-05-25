#include <iostream>
#include <vector>

struct Genome {
  int s, f, a, b;
};

int main(void) {
  size_t size;
  std::cin >> size;

  std::vector<std::vector<int>> genome(size, std::vector<int>(size));

  for (size_t i = 0; i < size; i++) {
    for (size_t j = 0; j < size; j++) {
      std::cin >> genome[i][j];
    }
  }

  for (auto& v : genome) {
    Genome g(v[0], v[1], v[2], v[3]);

    std::vector<int> vec;
  }
}
