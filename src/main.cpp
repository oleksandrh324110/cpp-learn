#include <iostream>

#include "math/vector.h"
#include "math/matrix.h"

int main() {
  vector<float, 2> v = { 0, 1 };

  v = 2 * v;

  v.print();
}
