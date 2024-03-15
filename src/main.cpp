#include <iostream>

#include "math/vector.h"
#include "math/matrix.h"

int main() {
  vector<float, 2> v = { 1, 2 };

  v = v * 2;

  v.print();
}
