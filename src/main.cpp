#include <iostream>

#include "math/vector.h"
#include "math/matrix.h"

int main() {
  matrix<int, 3, 3> m1 = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
  auto m2 = m1;

  std::cout << m1.det() << '\n';
}
