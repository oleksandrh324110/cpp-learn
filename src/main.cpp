#include <iostream>

#include "math/vector.h"
#include "math/matrix.h"

int main() {
  matrix<short, 3, 3> m = { {1, 2, 3},{4, 5, 6},{7, 8, 9} };

  std::cout << m.det() << '\n';

  m.print();
}
