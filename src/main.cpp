#include <iostream>

#include "math/vector.h"
#include "math/matrix.h"

int main() {
  matrix<char, 3, 2> m1 = { {1,2}, {3,4}, {5,6} };
  matrix<char, 2, 3> m2 = { {1,2,3}, {4,5,6} };

  m1 = m1.mult(m2);

  m1.print();
}
