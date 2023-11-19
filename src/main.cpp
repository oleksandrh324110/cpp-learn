#include "foo/foo.h"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec = {1, 2, 3, 4, 5};

  for (int el : vec) {
    std::cout << el << ' ';
  }
  std::cout << '\n';

  std::cout << foo(1, 3);
}
