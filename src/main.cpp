#include <iostream>

#include "math/vector.h"
#include "math/matrix.h"

int main() {
  matrix<float, 2, 2> m = { {1, 2}, {3, 4} };

  m[0][0] = 2;

  m.print();
}
